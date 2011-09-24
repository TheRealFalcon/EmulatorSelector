#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <QtGui/QDialog>
#include <include/settings.h>

namespace Ui {
    class GlobalConfig;
}

class EmulatorModel;

class GlobalConfig : public QDialog
{
    Q_OBJECT

public:
    GlobalConfig(Settings *config, EmulatorModel *configModel, QWidget *parent = 0);
    ~GlobalConfig();

private:
    Ui::GlobalConfig *ui;
    EmulatorModel *configModel;
    Settings *config;
    void launchEmulatorConfig(Emulator em);


private slots:
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void on_newButton_clicked();
    void on_closeButton_clicked();
};

#endif // GLOBALCONFIG_H
