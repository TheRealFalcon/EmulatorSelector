/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created: Sun Aug 21 06:37:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QWidget *page_2;
    QRadioButton *radioButton;

    void setupUi(QWidget *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QString::fromUtf8("Test"));
        Test->resize(1092, 768);
        stackedWidget = new QStackedWidget(Test);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1071, 741));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 240, 75, 23));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        radioButton = new QRadioButton(page_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(400, 290, 82, 17));
        stackedWidget->addWidget(page_2);

        retranslateUi(Test);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QWidget *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Test", "PushButton", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Test", "RadioButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
