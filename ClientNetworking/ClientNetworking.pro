#-------------------------------------------------
#
# Project created by QtCreator 2013-10-26T17:00:08
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = ClientNetworking
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Client.cc \
    Message.cpp \
    ta.cpp \
    task.cpp \
    user.cpp \
    course.cpp \
    evaluation.cpp

HEADERS += \
    Client.h \
    instructor.h \
    ta.h \
    task.h \
    user.h \
    course.h \
    evaluation.h
