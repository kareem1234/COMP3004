/****************************************************************************
** Meta object code from reading C++ file 'saveevaluation.h'
**
<<<<<<< HEAD
** Created: Mon Nov 4 11:20:38 2013
=======
** Created: Mon Nov 4 12:11:21 2013
>>>>>>> 2816de39d9883517bca2bdfce0cb35b417347e41
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "saveevaluation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'saveevaluation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SaveEvaluation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      41,   15,   15,   15, 0x05,
      64,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   15,   15,   15, 0x08,
     115,   15,   15,   15, 0x08,
     139,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SaveEvaluation[] = {
    "SaveEvaluation\0\0createEvaluationSignal()\0"
    "editEvaluationSignal()\0deleteEvaluationSignal()\0"
    "createEvaluationPressed()\0"
    "editEvaluationPressed()\0"
    "deleteEvaluationPressed()\0"
};

void SaveEvaluation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SaveEvaluation *_t = static_cast<SaveEvaluation *>(_o);
        switch (_id) {
        case 0: _t->createEvaluationSignal(); break;
        case 1: _t->editEvaluationSignal(); break;
        case 2: _t->deleteEvaluationSignal(); break;
        case 3: _t->createEvaluationPressed(); break;
        case 4: _t->editEvaluationPressed(); break;
        case 5: _t->deleteEvaluationPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SaveEvaluation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SaveEvaluation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SaveEvaluation,
      qt_meta_data_SaveEvaluation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SaveEvaluation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SaveEvaluation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SaveEvaluation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SaveEvaluation))
        return static_cast<void*>(const_cast< SaveEvaluation*>(this));
    return QDialog::qt_metacast(_clname);
}

int SaveEvaluation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SaveEvaluation::createEvaluationSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SaveEvaluation::editEvaluationSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SaveEvaluation::deleteEvaluationSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
