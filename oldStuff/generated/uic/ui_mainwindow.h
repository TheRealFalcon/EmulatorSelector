/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Sep 10 15:50:20 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *stack;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListView *emulatorView;
    QListView *letterView;
    QListView *fileView;
    QWidget *page_2;
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
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pathEdit;
    QPushButton *pathChooser;
    QPushButton *addButton;
    QListView *pathView;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *removeButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *emulatorList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *mainButton;
    QPushButton *configButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(983, 573);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(0, 100));
        Dialog->setFocusPolicy(Qt::NoFocus);
        Dialog->setStyleSheet(QString::fromUtf8("/*font: 12pt \"MS Shell Dlg 2\"; */\n"
"\n"
"*:focus {\n"
"	background: red;\n"
"}\n"
"\n"
"QPushButton:pushed {\n"
"	background: red;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: rgba(0,0,0,0);\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	/*\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"    stop: 0 rgba(183, 210, 192, 255), stop: 0.5 rgba(105, 165, 5, 255), stop:1 rgba(203, 225, 0, 255)); */\n"
"	background: rgb(0,0,200);\n"
"    min-height: 2px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"   /* background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"    stop: 0 rgba(183, 210, 192, 255), stop: 0.5 rgba(105, 165, 5, 255), stop:1 rgba(203, 225, 0, 255));\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin; */\n"
"	height: 0px;\n"
"} \n"
"QScrollBar::sub-line:vertical {\n"
"/*    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"    stop: 0 rgba(183, 210, 192, 255), stop: 0.5 r"
                        "gba(105, 165, 5, 255), stop:1 rgba(203, 225, 0, 255));\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;*/\n"
"	height: 0px;\n"
"}\n"
"\n"
"* {\n"
"	font: 12pt \"MS Shell Dlg 2\"; \n"
"}\n"
""));
        Dialog->setSizeGripEnabled(true);
        stack = new QStackedWidget(Dialog);
        stack->setObjectName(QString::fromUtf8("stack"));
        stack->setGeometry(QRect(216, -2, 761, 571));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        emulatorView = new QListView(page);
        emulatorView->setObjectName(QString::fromUtf8("emulatorView"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(emulatorView->sizePolicy().hasHeightForWidth());
        emulatorView->setSizePolicy(sizePolicy1);
        emulatorView->setMinimumSize(QSize(50, 0));
        emulatorView->setBaseSize(QSize(0, 0));
        emulatorView->setFrameShape(QFrame::NoFrame);
        emulatorView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        emulatorView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        emulatorView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        emulatorView->setProperty("showDropIndicator", QVariant(false));
        emulatorView->setSelectionMode(QAbstractItemView::MultiSelection);
        emulatorView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(emulatorView);

        letterView = new QListView(page);
        letterView->setObjectName(QString::fromUtf8("letterView"));
        sizePolicy1.setHeightForWidth(letterView->sizePolicy().hasHeightForWidth());
        letterView->setSizePolicy(sizePolicy1);
        letterView->setMinimumSize(QSize(50, 0));
        letterView->setFrameShape(QFrame::NoFrame);
        letterView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        letterView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        letterView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        letterView->setProperty("showDropIndicator", QVariant(false));
        letterView->setSelectionMode(QAbstractItemView::MultiSelection);

        horizontalLayout->addWidget(letterView);

        fileView = new QListView(page);
        fileView->setObjectName(QString::fromUtf8("fileView"));
        sizePolicy1.setHeightForWidth(fileView->sizePolicy().hasHeightForWidth());
        fileView->setSizePolicy(sizePolicy1);
        fileView->setMinimumSize(QSize(100, 0));
        fileView->setBaseSize(QSize(0, 0));
        fileView->setStyleSheet(QString::fromUtf8(""));
        fileView->setFrameShape(QFrame::NoFrame);
        fileView->setFrameShadow(QFrame::Raised);
        fileView->setLineWidth(1);
        fileView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        fileView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        fileView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fileView->setProperty("showDropIndicator", QVariant(false));
        fileView->setSelectionMode(QAbstractItemView::SingleSelection);
        fileView->setSelectionBehavior(QAbstractItemView::SelectRows);
        fileView->setMovement(QListView::Static);
        fileView->setLayoutMode(QListView::Batched);

        horizontalLayout->addWidget(fileView);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 2);

        horizontalLayout_2->addLayout(horizontalLayout);

        stack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 10, 401, 561));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
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
        verticalLayout_3->setSpacing(6);
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
        horizontalLayout_4->setSpacing(6);
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
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_4);

        exeChooser = new QPushButton(layoutWidget);
        exeChooser->setObjectName(QString::fromUtf8("exeChooser"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(exeChooser->sizePolicy().hasHeightForWidth());
        exeChooser->setSizePolicy(sizePolicy2);
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
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pathEdit = new QLineEdit(groupBox);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        horizontalLayout_3->addWidget(pathEdit);

        pathChooser = new QPushButton(groupBox);
        pathChooser->setObjectName(QString::fromUtf8("pathChooser"));
        sizePolicy2.setHeightForWidth(pathChooser->sizePolicy().hasHeightForWidth());
        pathChooser->setSizePolicy(sizePolicy2);
        pathChooser->setIconSize(QSize(4, 4));

        horizontalLayout_3->addWidget(pathChooser);

        addButton = new QPushButton(groupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(addButton);

        horizontalLayout_3->setStretch(0, 15);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_7->addLayout(horizontalLayout_3);

        pathView = new QListView(groupBox);
        pathView->setObjectName(QString::fromUtf8("pathView"));
        pathView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_7->addWidget(pathView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout_6->addWidget(removeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_5->addWidget(groupBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_7->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalLayout_5->setStretch(1, 3);
        verticalLayout_5->setStretch(2, 1);
        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 160, 541));
        emulatorList = new QVBoxLayout(verticalLayoutWidget_2);
        emulatorList->setSpacing(6);
        emulatorList->setContentsMargins(11, 11, 11, 11);
        emulatorList->setObjectName(QString::fromUtf8("emulatorList"));
        emulatorList->setContentsMargins(0, 0, 0, 0);
        stack->addWidget(page_2);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 175, 112));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainButton = new QPushButton(verticalLayoutWidget);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));
        mainButton->setFocusPolicy(Qt::StrongFocus);
        mainButton->setInputMethodHints(Qt::ImhNone);
        mainButton->setCheckable(false);
        mainButton->setFlat(false);

        verticalLayout->addWidget(mainButton);

        configButton = new QPushButton(verticalLayoutWidget);
        configButton->setObjectName(QString::fromUtf8("configButton"));
        configButton->setFocusPolicy(Qt::StrongFocus);
        configButton->setFlat(true);

        verticalLayout->addWidget(configButton);


        retranslateUi(Dialog);

        stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("Dialog", "Name:", 0, QApplication::UnicodeUTF8));
        exeLabel->setText(QApplication::translate("Dialog", "Exe Location:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Arguments:", 0, QApplication::UnicodeUTF8));
        extensionLabel->setText(QApplication::translate("Dialog", "File Extension:", 0, QApplication::UnicodeUTF8));
        exeChooser->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Search Paths", 0, QApplication::UnicodeUTF8));
        pathChooser->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Dialog", "Add", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("Dialog", "Remove", 0, QApplication::UnicodeUTF8));
        mainButton->setText(QApplication::translate("Dialog", "Main", 0, QApplication::UnicodeUTF8));
        configButton->setText(QApplication::translate("Dialog", "Emulator Configuration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
