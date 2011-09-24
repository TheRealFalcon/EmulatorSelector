/****************************************************************************
** Meta object code from reading C++ file 'filterConfig.h'
**
** Created: Sun Aug 21 06:36:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/filterConfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilterConfig[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x08,
      71,   65,   13,   13, 0x08,
     104,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FilterConfig[] = {
    "FilterConfig\0\0pos\0"
    "on_treeView_customContextMenuRequested(QPoint)\0"
    "index\0on_treeView_clicked(QModelIndex)\0"
    "doSomething()\0"
};

const QMetaObject FilterConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FilterConfig,
      qt_meta_data_FilterConfig, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilterConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilterConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilterConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilterConfig))
        return static_cast<void*>(const_cast< FilterConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int FilterConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_treeView_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: on_treeView_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: doSomething(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
