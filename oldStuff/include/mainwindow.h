#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QDialog>
#include <QtGui/QStandardItemModel>
#include <QtGui/QItemSelection>
#include <QDebug>
#include "include/settings.h"

namespace Ui {
    class Dialog;
}

class EmulatorModel;
class Settings;
class QItemSelection;
class QSortFilterProxyModel;

typedef struct RomRegex_struct {
    QStringList firstLetters;
    //QString body;
    QMultiHash<QString, QString> codes;
    QStringList extensions;

    QString pattern() {
        QString pattern = "^";

        //First character set
        pattern += '(' + firstLetters.join("|") + ')';

        //body
        pattern += ".*";

        //codes
        // (\\(U|J|E\\)|\\[!|h|t\\])
        //pattern += "(";
        foreach (QString delimiter, codes.uniqueKeys()) {
            Q_ASSERT(delimiter.size() == 2);
            QString codeStart = QString(delimiter.at(0));
            QString codeEnd = QString(delimiter.at(1));
            QStringList codeValues(codes.values(delimiter));
            pattern += "\\" + codeStart + "(" + codeValues.join("|") + ")\\" + codeEnd;
        }
        //pattern += ")";

        //Anything else between codes and extensions
        pattern += ".*";

        //extensions
        pattern += "(" + extensions.join("|") + ')';
        return pattern;
    }
} RomRegex;

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(Settings *config, EmulatorModel *emulatorModel, QWidget *parent = 0);
    void setupRemainingUi();
    ~MainWindow();

private slots:
    void on_fileView_doubleClicked(QModelIndex index);
    void on_pushButton_clicked();
    void on_emulatorView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected);
    void on_codeView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected);
    void on_letterView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected);

    void on_mainButton_clicked();

    void on_configButton_clicked();

private:
    Ui::Dialog *ui;
    Settings *config;
    QSortFilterProxyModel *proxyModel;
    EmulatorModel *emulatorModel;
//    QString regCode;
//    QString regExt;
    RomRegex regex;
};

#endif // MAINWINDOW_H
