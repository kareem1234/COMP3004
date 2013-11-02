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
    databasecontroller.cpp

HEADERS += \
    databasetest.h \
    databasemanager.h \
    databasecontroller.h
