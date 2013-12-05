#-------------------------------------------------
#
# Project created by QtCreator 2013-10-26T21:59:12
#
#-------------------------------------------------
QT       += core
QT       += network
QT       -= gui
QT       += sql

TARGET = ServerNetworking
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Server.cpp \
    Message.cpp \
    requesthandler.cpp \
    ta.cpp \
    task.cpp \
    user.cpp \
    course.cpp \
    evaluation.cpp \
    instructor.cpp \
    databasemanager.cpp \
    databasecontroller.cpp \
    dbinstructor.cpp \
    dbevaluation.cpp \
    dbtask.cpp \
    dbta.cpp \
    dbcourse.cpp

HEADERS += \
    Server.h \
    requesthandler.h \
    ta.h \
    task.h \
    user.h \
    course.h \
    evaluation.h \
    instructor.h \
    databasemanager.h \
    databasecontroller.h \
    dbinstructor.h \
    dbevaluation.h \
    dbtask.h \
    dbta.h \
    dbcourse.h

