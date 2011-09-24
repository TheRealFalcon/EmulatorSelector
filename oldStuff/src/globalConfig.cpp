#include "generated/uic/ui_globalconfig.h"
#include "include/globalconfig.h"
#include "include/emulatorconfig.h"
#include "include/emulatorModel.h"
#include <QtCore/QStringList>
#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QtGui/QMessageBox>
#include <QtCore/QDebug>
#include <QtGui/QStandardItemModel>

GlobalConfig::GlobalConfig(Settings *config, EmulatorModel *configModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalConfig)
{
    this->config = config;
    this->configModel = configModel;

    ui->setupUi(this);
    ui->emulatorView->setModel(configModel->getModel());
    ui->emulatorView->setCurrentIndex(configModel->getFirstIndex());
}


GlobalConfig::~GlobalConfig()
{
    delete ui;
}

void GlobalConfig::on_closeButton_clicked()
{
    close();
}

void GlobalConfig::on_newButton_clicked()
{
    Emulator emulator;
    EmulatorConfig emulatorConfig(&emulator);
    if (emulatorConfig.exec() == QDialog::Accepted) {
        configModel->addEmulator(emulator);
        ui->emulatorView->setCurrentIndex(configModel->getLastIndex());
    }
}

void GlobalConfig::on_editButton_clicked()
{
    QModelIndex currentIndex = ui->emulatorView->currentIndex();
    Emulator emulator = configModel->getEmulator(currentIndex);
    EmulatorConfig emulatorConfig(&emulator);
    if (emulatorConfig.exec() == QDialog::Accepted) {
        configModel->replaceEmulator(currentIndex, emulator);
    }
}

void GlobalConfig::on_removeButton_clicked()
{
    configModel->removeEmulator(ui->emulatorView->currentIndex());
}
