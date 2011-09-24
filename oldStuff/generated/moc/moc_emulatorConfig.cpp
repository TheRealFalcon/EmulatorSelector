/****************************************************************************
** Meta object code from reading C++ file 'emulatorConfig.h'
**
** Created: Sun Aug 21 06:36:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/emulatorConfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emulatorConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmulatorConfig[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      49,   15,   15,   15, 0x08,
      73,   15,   15,   15, 0x08,
      99,   15,   15,   15, 0x08,
     122,   15,   15,   15, 0x08,
     147,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmulatorConfig[] = {
    "EmulatorConfig\0\0on_nameEdit_textChanged(QString)\0"
    "on_buttonBox_accepted()\0"
    "on_removeButton_clicked()\0"
    "on_addButton_clicked()\0on_pathChooser_clicked()\0"
    "on_exeChooser_clicked()\0"
};

const QMetaObject EmulatorConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EmulatorConfig,
      qt_meta_data_EmulatorConfig, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmulatorConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmulatorConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmulatorConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmulatorConfig))
        return static_cast<void*>(const_cast< EmulatorConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int EmulatorConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_nameEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_buttonBox_accepted(); break;
        case 2: on_removeButton_clicked(); break;
        case 3: on_addButton_clicked(); break;
        case 4: on_pathChooser_clicked(); break;
        case 5: on_exeChooser_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
