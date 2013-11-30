/****************************************************************************
** Meta object code from reading C++ file 'TAcontroller.h'
**
** Created: Sat Nov 30 17:11:43 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TAcontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TAcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TAcontroller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      25,   13,   13,   13, 0x0a,
      38,   36,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TAcontroller[] = {
    "TAcontroller\0\0viewTask()\0viewEval()\0"
    ",\0cellSelected(int,int)\0"
};

void TAcontroller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TAcontroller *_t = static_cast<TAcontroller *>(_o);
        switch (_id) {
        case 0: _t->viewTask(); break;
        case 1: _t->viewEval(); break;
        case 2: _t->cellSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TAcontroller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TAcontroller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TAcontroller,
      qt_meta_data_TAcontroller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TAcontroller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TAcontroller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TAcontroller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TAcontroller))
        return static_cast<void*>(const_cast< TAcontroller*>(this));
    return QObject::qt_metacast(_clname);
}

int TAcontroller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
