#-------------------------------------------------
#
# Project created by QtCreator 2013-10-26T20:34:50
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += sql

TARGET = test-database
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    databasetest.cpp \
    databasemanager.cpp \
    databasecontroller.cpp \
    user.cpp \
    task.cpp \
    ta.cpp \
    instructor.cpp \
    evaluation.cpp \
    course.cpp

HEADERS += \
    databasetest.h \
    databasemanager.h \
    databasecontroller.h \
    user.h \
    task.h \
    ta.h \
    instructor.h \
    evaluation.h \
    course.h
