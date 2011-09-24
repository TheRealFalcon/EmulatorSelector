#include "include/test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
}

Test::~Test()
{
    delete ui;
}

void Test::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Test::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
