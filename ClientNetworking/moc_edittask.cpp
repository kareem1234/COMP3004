/****************************************************************************
** Meta object code from reading C++ file 'edittask.h'
**
<<<<<<< HEAD
** Created: Mon Nov 4 11:20:34 2013
=======
** Created: Mon Nov 4 12:11:20 2013
>>>>>>> 2816de39d9883517bca2bdfce0cb35b417347e41
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "edittask.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edittask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditTask[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_EditTask[] = {
    "EditTask\0"
};

void EditTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EditTask::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditTask::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditTask,
      qt_meta_data_EditTask, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditTask::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditTask::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditTask))
        return static_cast<void*>(const_cast< EditTask*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
