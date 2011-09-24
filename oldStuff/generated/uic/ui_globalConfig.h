/********************************************************************************
** Form generated from reading UI file 'globalConfig.ui'
**
** Created: Sun Aug 21 06:25:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALCONFIG_H
#define UI_GLOBALCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GlobalConfig
{
public:
    QListView *emulatorView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *newButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *GlobalConfig)
    {
        if (GlobalConfig->objectName().isEmpty())
            GlobalConfig->setObjectName(QString::fromUtf8("GlobalConfig"));
        GlobalConfig->resize(362, 244);
        emulatorView = new QListView(GlobalConfig);
        emulatorView->setObjectName(QString::fromUtf8("emulatorView"));
        emulatorView->setGeometry(QRect(10, 10, 256, 192));
        layoutWidget = new QWidget(GlobalConfig);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 10, 77, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newButton = new QPushButton(layoutWidget);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        verticalLayout->addWidget(newButton);

        editButton = new QPushButton(layoutWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout->addWidget(editButton);

        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout->addWidget(removeButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(GlobalConfig);

        QMetaObject::connectSlotsByName(GlobalConfig);
    } // setupUi

    void retranslateUi(QDialog *GlobalConfig)
    {
        GlobalConfig->setWindowTitle(QApplication::translate("GlobalConfig", "Dialog", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("GlobalConfig", "New...", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("GlobalConfig", "Edit...", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("GlobalConfig", "Remove", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("GlobalConfig", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GlobalConfig: public Ui_GlobalConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALCONFIG_H
