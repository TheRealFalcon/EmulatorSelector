#include "include/filterConfig.h"
#include "include/settings.h"
#include "generated/uic/ui_filterConfig.h"
#include <QtGui/QStandardItemModel>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <QtGui/QMenu>

FilterConfig::FilterConfig(Settings *config, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterConfig)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *root = model->invisibleRootItem();
    model->setHorizontalHeaderLabels(QStringList() << "Code" << "Definition");

    QStringList codeTypes = config->getCodeTypes();
    foreach (QString codeType, codeTypes) {
        QStandardItem *typeRow = new QStandardItem(codeType);
        root->appendRow(typeRow);
        //TODO: FIXME...I changed getCodes so whats returned is different than the for loop
        QList<Code> codes = config->getCodes(codeType);
        foreach (Code code, codes) {
            QList<QStandardItem*> codeList;
            codeList.append(new QStandardItem(code.key));
            codeList.append(new QStandardItem(code.value));
            typeRow->appendRow(codeList);
        }
    }

    ui->treeView->setModel(model);
}

FilterConfig::~FilterConfig()
{
    delete ui;
}


void FilterConfig::on_treeView_clicked(QModelIndex index)
{
//    QMenu contextMenu(this);
//    contextMenu.addAction("Edit", this, SLOT(doSomething()));
//    contextMenu.popup(QCursor::pos());
//    contextMenu.exec();
}

void FilterConfig::on_treeView_customContextMenuRequested(QPoint pos)
{
    QMenu contextMenu(this);
    contextMenu.addAction("New", this, SLOT(doSomething()));
    contextMenu.popup(ui->treeView->mapToGlobal(pos));
    contextMenu.exec();
}

void FilterConfig::doSomething()
{
    qDebug() << "hello";
}
