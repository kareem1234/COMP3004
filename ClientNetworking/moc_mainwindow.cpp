/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Nov 4 12:11:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,
      77,   11,   11,   11, 0x05,
      94,   11,   11,   11, 0x05,
     112,   11,   11,   11, 0x05,
     135,   11,   11,   11, 0x05,
     148,   11,   11,   11, 0x05,
     159,   11,   11,   11, 0x05,
     172,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     191,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     226,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     278,   11,   11,   11, 0x08,
     291,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     329,   11,   11,   11, 0x08,
     346,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0taskCreateTaskButtonPressed()\0"
    "viewCoursesSignal()\0viewTASignal()\0"
    "editTaskSignal()\0viewTasksSignal()\0"
    "saveEvaluationSignal()\0createEval()\0"
    "editEval()\0deleteEval()\0deleteTaskSignal()\0"
    "taskCreateSlot()\0viewCoursesSlot()\0"
    "editTaskSlot()\0saveEvaluationSlot()\0"
    "viewTasksSlot()\0viewTASlot()\0"
    "createEvaluation()\0deleteEvaluation()\0"
    "editEvaluation()\0deleteTaskSlot()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->taskCreateTaskButtonPressed(); break;
        case 1: _t->viewCoursesSignal(); break;
        case 2: _t->viewTASignal(); break;
        case 3: _t->editTaskSignal(); break;
        case 4: _t->viewTasksSignal(); break;
        case 5: _t->saveEvaluationSignal(); break;
        case 6: _t->createEval(); break;
        case 7: _t->editEval(); break;
        case 8: _t->deleteEval(); break;
        case 9: _t->deleteTaskSignal(); break;
        case 10: _t->taskCreateSlot(); break;
        case 11: _t->viewCoursesSlot(); break;
        case 12: _t->editTaskSlot(); break;
        case 13: _t->saveEvaluationSlot(); break;
        case 14: _t->viewTasksSlot(); break;
        case 15: _t->viewTASlot(); break;
        case 16: _t->createEvaluation(); break;
        case 17: _t->deleteEvaluation(); break;
        case 18: _t->editEvaluation(); break;
        case 19: _t->deleteTaskSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::taskCreateTaskButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::viewCoursesSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::viewTASignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::editTaskSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::viewTasksSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::saveEvaluationSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::createEval()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::editEval()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MainWindow::deleteEval()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void MainWindow::deleteTaskSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
