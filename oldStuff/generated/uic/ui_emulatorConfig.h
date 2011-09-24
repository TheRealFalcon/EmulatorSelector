/********************************************************************************
** Form generated from reading UI file 'emulatorConfig.ui'
**
** Created: Sun Aug 21 06:25:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMULATORCONFIG_H
#define UI_EMULATORCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmulatorConfig
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *nameLabel;
    QLabel *exeLabel;
    QLabel *label;
    QLabel *extensionLabel;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nameEdit;
    QLineEdit *exeEdit;
    QLineEdit *argEdit;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *extEdit;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *exeChooser;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *pathEdit;
    QPushButton *pathChooser;
    QPushButton *addButton;
    QListView *pathView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *removeButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *EmulatorConfig)
    {
        if (EmulatorConfig->objectName().isEmpty())
            EmulatorConfig->setObjectName(QString::fromUtf8("EmulatorConfig"));
        EmulatorConfig->setWindowModality(Qt::WindowModal);
        EmulatorConfig->resize(336, 457);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmulatorConfig->sizePolicy().hasHeightForWidth());
        EmulatorConfig->setSizePolicy(sizePolicy);
        EmulatorConfig->setModal(false);
        layoutWidget = new QWidget(EmulatorConfig);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 10, 311, 436));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout_4->addWidget(nameLabel);

        exeLabel = new QLabel(layoutWidget);
        exeLabel->setObjectName(QString::fromUtf8("exeLabel"));

        verticalLayout_4->addWidget(exeLabel);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        extensionLabel = new QLabel(layoutWidget);
        extensionLabel->setObjectName(QString::fromUtf8("extensionLabel"));

        verticalLayout_4->addWidget(extensionLabel);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout_3->addWidget(nameEdit);

        exeEdit = new QLineEdit(layoutWidget);
        exeEdit->setObjectName(QString::fromUtf8("exeEdit"));

        verticalLayout_3->addWidget(exeEdit);

        argEdit = new QLineEdit(layoutWidget);
        argEdit->setObjectName(QString::fromUtf8("argEdit"));

        verticalLayout_3->addWidget(argEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        extEdit = new QLineEdit(layoutWidget);
        extEdit->setObjectName(QString::fromUtf8("extEdit"));

        horizontalLayout_4->addWidget(extEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_4);

        exeChooser = new QPushButton(layoutWidget);
        exeChooser->setObjectName(QString::fromUtf8("exeChooser"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exeChooser->sizePolicy().hasHeightForWidth());
        exeChooser->setSizePolicy(sizePolicy1);
        exeChooser->setIconSize(QSize(4, 4));

        verticalLayout_6->addWidget(exeChooser);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_6);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pathEdit = new QLineEdit(groupBox);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        horizontalLayout->addWidget(pathEdit);

        pathChooser = new QPushButton(groupBox);
        pathChooser->setObjectName(QString::fromUtf8("pathChooser"));
        sizePolicy1.setHeightForWidth(pathChooser->sizePolicy().hasHeightForWidth());
        pathChooser->setSizePolicy(sizePolicy1);
        pathChooser->setIconSize(QSize(4, 4));

        horizontalLayout->addWidget(pathChooser);

        addButton = new QPushButton(groupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(addButton);

        horizontalLayout->setStretch(0, 15);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        pathView = new QListView(groupBox);
        pathView->setObjectName(QString::fromUtf8("pathView"));
        pathView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(pathView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout_2->addWidget(removeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_5->setStretch(1, 3);
        verticalLayout_5->setStretch(2, 1);

        retranslateUi(EmulatorConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), EmulatorConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EmulatorConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(EmulatorConfig);
    } // setupUi

    void retranslateUi(QDialog *EmulatorConfig)
    {
        EmulatorConfig->setWindowTitle(QApplication::translate("EmulatorConfig", "Dialog", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("EmulatorConfig", "Name:", 0, QApplication::UnicodeUTF8));
        exeLabel->setText(QApplication::translate("EmulatorConfig", "Exe Location:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmulatorConfig", "Arguments:", 0, QApplication::UnicodeUTF8));
        extensionLabel->setText(QApplication::translate("EmulatorConfig", "File Extension:", 0, QApplication::UnicodeUTF8));
        exeChooser->setText(QApplication::translate("EmulatorConfig", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("EmulatorConfig", "Search Paths", 0, QApplication::UnicodeUTF8));
        pathChooser->setText(QApplication::translate("EmulatorConfig", "...", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("EmulatorConfig", "Add", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("EmulatorConfig", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmulatorConfig: public Ui_EmulatorConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMULATORCONFIG_H
