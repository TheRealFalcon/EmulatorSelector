#include "include/mainwindow.h"
#include "generated/uic/ui_mainwindow.h"
#include "include/emulatorModel.h"
#include "include/globalConfig.h"
#include "include/settings.h"
#include <QtGui/QStandardItemModel>
#include <QtGui/QSortFilterProxyModel>
#include <QtGui/QFileSystemModel>
#include <QtGui/QStringListModel>
#include <QtGui/QListView>
#include <QtCore/QDir>
#include <QtCore/QRegExp>
#include <QtGui/QItemSelection>
#include <QtGui/QSizePolicy>
#include <QtCore/QProcess>

#include <QtCore/QDebug>

MainWindow::MainWindow(Settings *config, EmulatorModel *emulatorModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->config = config;
    this->emulatorModel = emulatorModel;

    ui->setupUi(this);

    //Add the code models/views
    QStringList codeTypes = config->getCodeTypes();
    for (int i=0; i<codeTypes.size(); i++) {
        QString codeType = codeTypes.at(i);
        QStandardItemModel *codeModel = new QStandardItemModel();
        codeModel->setObjectName(codeType);
        //QStandardItem *root = codeModel->invisibleRootItem();
        codeModel->setHorizontalHeaderLabels(QStringList() << codeType);

        //codeModel->appendRow(new QStandardItem("All"));
        foreach (Code code, config->getCodes(codeType)) {
            QStandardItem *newRow = new QStandardItem(code.value);
            newRow->setData(qVariantFromValue(code));
            codeModel->appendRow(newRow);
            //codeModel->appendRow(new QStandardItem(code.value));
        }
        //codeModels.append(codeModel);
        QListView *codeView = new QListView();
        //codeView->setObjectName(codeType);
        codeView->setFrameShape(QFrame::NoFrame);
        codeView->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        codeView->setMinimumWidth(50);
        codeView->setSelectionMode(QAbstractItemView::MultiSelection);
        codeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        codeView->setModel(codeModel);
        ui->horizontalLayout->insertWidget(i, codeView, 20);
        connect(codeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),
                this, SLOT(on_codeView_selection_changed(const QItemSelection &, const QItemSelection &)));
    }

    //Set Emulator view
    ui->emulatorView->setModel(emulatorModel->getModel());


    //Setup the letters view
    int asciiA = 65;
    int asciiZ = 90;
    QStringList lettersList;
    for (int i=asciiA; i<=asciiZ; i++) {
        lettersList.append(QChar(i));
    }
    QStringListModel *letterModel = new QStringListModel();
    letterModel->setStringList(lettersList);
    ui->letterView->setModel(letterModel);


    //Create file model/proxy
    QStandardItemModel *fileModel = new QStandardItemModel();
    foreach (Emulator emulator, emulatorModel->emulatorList()) {
        foreach (QString searchPath, emulator.searchPaths) {
            QDir dir(searchPath);
            QStringList searchFiles = dir.entryList(QStringList() << "*" + emulator.extension, QDir::Files);
            foreach (QString searchFile, searchFiles) {
                QStandardItem *fileItem = new QStandardItem(searchFile);
                QStandardItem *directoryItem = new QStandardItem(searchPath);
                QStandardItem *extensionItem = new QStandardItem(emulator.extension);
                QStandardItem *exeItem = new QStandardItem(emulator.path);
                QStandardItem *argsItem = new QStandardItem(emulator.args);
                QList<QStandardItem*> row;
                row << fileItem << directoryItem << extensionItem << exeItem << argsItem;
                fileModel->appendRow(row);
            }
        }
    }

    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(fileModel);


    ui->fileView->setModel(proxyModel);

    connect(ui->emulatorView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(on_emulatorView_selection_changed(const QItemSelection &, const QItemSelection &)));
    connect(ui->letterView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(on_letterView_selection_changed(const QItemSelection &, const QItemSelection &)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GlobalConfig w(config, emulatorModel);
    w.exec();
}

void MainWindow::on_emulatorView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
{

    //Based on current implementation, I can't select/deselect more than one thing at once.
    //Assertion is to insure it stays that way.
    Q_ASSERT(selected.indexes().size() < 2);
    Q_ASSERT(deselected.indexes().size() < 2);

    if (!selected.isEmpty()) {
        this->regex.extensions.append("\\" + emulatorModel->getEmulator(selected.indexes().at(0)).extension);
    }
    if (!deselected.isEmpty()) {
        this->regex.extensions.removeOne("\\" + emulatorModel->getEmulator(deselected.indexes().at(0)).extension);
    }

    qDebug() << this->regex.pattern();
    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
    proxyModel->setFilterRegExp(regExp);
}

void MainWindow::on_codeView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
{
    if (!selected.isEmpty()) {
        Code code = selected.indexes().at(0).data(Qt::UserRole+1).value<Code>();
        this->regex.codes.insert(code.delimiters, code.key);
    }
    if (!deselected.isEmpty()) {
        Code code = deselected.indexes().at(0).data(Qt::UserRole+1).value<Code>();
        this->regex.codes.remove(code.delimiters, code.key);
    }

    qDebug() << this->regex.pattern();

    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
    proxyModel->setFilterRegExp(regExp);
}

void MainWindow::on_letterView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
{
    if (!selected.isEmpty()) {
        this->regex.firstLetters.append(selected.indexes().at(0).data().toString());
    }
    if (!deselected.isEmpty()) {
        this->regex.firstLetters.removeOne(deselected.indexes().at(0).data().toString());
    }

    qDebug() << this->regex.pattern();

    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
    proxyModel->setFilterRegExp(regExp);
}

void MainWindow::on_fileView_doubleClicked(QModelIndex index)
{
    int i = 0;
    QString romFile = index.sibling(0, i++).data().value<QString>();
    QString romDir = index.sibling(0, i++).data().value<QString>();
    //QString romExt = index.sibling(0, i++).data().value<QString>();
    QString romEmulatorExe = index.sibling(0, i++).data().value<QString>();
    QString romArgs = index.sibling(0, i).data().value<QString>();
    //qDebug() << romFile << romDir << romExt << romEmulatorExe << romArgs;
    QProcess::execute(romEmulatorExe, QStringList() << romDir + "/" + romFile << romArgs);

}

void MainWindow::on_mainButton_clicked()
{
    ui->stack->setCurrentIndex(0);
}

void MainWindow::on_configButton_clicked()
{
    ui->stack->setCurrentIndex(1);
}
