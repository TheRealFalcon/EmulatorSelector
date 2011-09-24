#ifndef TEST_H
#define TEST_H

#include <QtGui/QWidget>

namespace Ui {
    class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

private:
    Ui::Test *ui;
};

#endif // TEST_H
