/********************************************************************************
** Form generated from reading UI file 'filterConfig.ui'
**
** Created: Sun Aug 21 06:25:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCONFIG_H
#define UI_FILTERCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_FilterConfig
{
public:
    QTreeView *treeView;

    void setupUi(QDialog *FilterConfig)
    {
        if (FilterConfig->objectName().isEmpty())
            FilterConfig->setObjectName(QString::fromUtf8("FilterConfig"));
        FilterConfig->resize(870, 640);
        FilterConfig->setContextMenuPolicy(Qt::DefaultContextMenu);
        treeView = new QTreeView(FilterConfig);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(140, 60, 256, 192));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setAcceptDrops(false);
        treeView->setFrameShape(QFrame::Box);
        treeView->setFrameShadow(QFrame::Sunken);
        treeView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        treeView->setTabKeyNavigation(true);
        treeView->setProperty("showDropIndicator", QVariant(true));
        treeView->setDragEnabled(true);
        treeView->setDragDropOverwriteMode(false);
        treeView->setDragDropMode(QAbstractItemView::InternalMove);
        treeView->setDefaultDropAction(Qt::MoveAction);
        treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
        treeView->setAutoExpandDelay(0);
        treeView->setRootIsDecorated(true);
        treeView->setUniformRowHeights(true);
        treeView->setItemsExpandable(true);
        treeView->setSortingEnabled(false);
        treeView->setAnimated(true);
        treeView->setAllColumnsShowFocus(false);
        treeView->header()->setCascadingSectionResizes(true);
        treeView->header()->setHighlightSections(true);

        retranslateUi(FilterConfig);

        QMetaObject::connectSlotsByName(FilterConfig);
    } // setupUi

    void retranslateUi(QDialog *FilterConfig)
    {
        FilterConfig->setWindowTitle(QApplication::translate("FilterConfig", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilterConfig: public Ui_FilterConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCONFIG_H
