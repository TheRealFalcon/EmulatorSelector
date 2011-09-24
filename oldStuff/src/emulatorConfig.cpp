#include "include/emulatorConfig.h"
#include "generated/uic/ui_emulatorConfig.h"
#include <QtGui/QFileDialog>
#include <QtGui/QStringListModel>
#include "QtCore/QDebug"


EmulatorConfig::EmulatorConfig(Emulator *em, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmulatorConfig)
{
    //setAttribute(Qt::WA_DeleteOnClose);
    this->dirModel = new QStringListModel();
    this->emulator = em;

    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->pathView->setModel(dirModel);

    ui->nameEdit->setText(em->name);
    ui->exeEdit->setText(em->path);
    ui->argEdit->setText(em->args);
    ui->extEdit->setText(em->extension);

    dirModel->setStringList(em->searchPaths);
}

EmulatorConfig::~EmulatorConfig()
{
    delete ui;
    delete dirModel;
}

void EmulatorConfig::on_exeChooser_clicked()
{
    QString exePath = QFileDialog::getOpenFileName(this, tr("Select Emulator"), "", tr("Binary (*.exe *.bat *.out);; All Files (*.*)"));
    if (!exePath.isEmpty()) {
        ui->exeEdit->setText(exePath);
    }
}

void EmulatorConfig::on_pathChooser_clicked()
{
    static QString filesDir;
    filesDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), filesDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!filesDir.isEmpty()) {
        ui->pathEdit->setText(filesDir);
    }
}

void EmulatorConfig::on_addButton_clicked()
{
    QString pathText = ui->pathEdit->text();
    if (!pathText.isEmpty()) {
        pathText.replace("\\", "/");
        int rowIndex = dirModel->rowCount();
        dirModel->insertRow(rowIndex);
        dirModel->setData(dirModel->index(rowIndex), pathText);
        ui->pathEdit->setText("");
    }
}

void EmulatorConfig::on_removeButton_clicked()
{
    dirModel->removeRow(ui->pathView->currentIndex().row());
}


void EmulatorConfig::on_buttonBox_accepted()
{
    emulator->name = ui->nameEdit->text();
    emulator->path = ui->exeEdit->text();
    emulator->args = ui->argEdit->text();
    emulator->extension = ui->extEdit->text();
    emulator->searchPaths = dirModel->stringList();

    emulator->path.replace("\\", "/");
}

void EmulatorConfig::on_nameEdit_textChanged(QString text)
{
    if (text == "") {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}
