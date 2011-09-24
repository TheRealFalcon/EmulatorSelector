#ifndef FILTERCONFIG_H
#define FILTERCONFIG_H

#include <QtGui/QDialog>
#include <QtCore/QModelIndex>

namespace Ui {
    class FilterConfig;
}

class Settings;

class FilterConfig : public QDialog
{
    Q_OBJECT

public:
    explicit FilterConfig(Settings *config, QWidget *parent = 0);
    ~FilterConfig();

private:
    Ui::FilterConfig *ui;

private slots:
    void on_treeView_customContextMenuRequested(QPoint pos);
    void on_treeView_clicked(QModelIndex index);
    void doSomething();
};

#endif // FILTERCONFIG_H
