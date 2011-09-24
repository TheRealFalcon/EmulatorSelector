/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Sep 10 15:23:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
     101,   81,   11,   11, 0x08,
     166,   81,   11,   11, 0x08,
     227,   81,   11,   11, 0x08,
     290,   11,   11,   11, 0x08,
     314,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0index\0"
    "on_fileView_doubleClicked(QModelIndex)\0"
    "on_pushButton_clicked()\0selected,deselected\0"
    "on_emulatorView_selection_changed(QItemSelection,QItemSelection)\0"
    "on_codeView_selection_changed(QItemSelection,QItemSelection)\0"
    "on_letterView_selection_changed(QItemSelection,QItemSelection)\0"
    "on_mainButton_clicked()\0"
    "on_configButton_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_fileView_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_emulatorView_selection_changed((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 3: on_codeView_selection_changed((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 4: on_letterView_selection_changed((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 5: on_mainButton_clicked(); break;
        case 6: on_configButton_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
