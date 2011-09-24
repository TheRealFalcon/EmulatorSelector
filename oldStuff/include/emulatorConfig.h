#ifndef EMULATORCONFIG_H
#define EMULATORCONFIG_H

#include <QtGui/QDialog>
#include "include/settings.h"

namespace Ui {
    class EmulatorConfig;
}

class QStringListModel;

class EmulatorConfig : public QDialog
{
    Q_OBJECT

public:
    explicit EmulatorConfig(Emulator *em, QWidget *parent = 0);
    ~EmulatorConfig();

private:
    Ui::EmulatorConfig *ui;
    QStringListModel *dirModel;
    Emulator *emulator;
    Settings *config;

private slots:
    void on_nameEdit_textChanged(QString );
    void on_buttonBox_accepted();
    void on_removeButton_clicked();
    void on_addButton_clicked();
    void on_pathChooser_clicked();
    void on_exeChooser_clicked();
};

#endif // CONFIGUREEMULATOR_H
