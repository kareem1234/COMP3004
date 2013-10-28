#-------------------------------------------------
#
# Project created by QtCreator 2013-10-26T21:59:12
#
#-------------------------------------------------
QT       += core
QT       += network
QT       -= gui

TARGET = ServerNetworking
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Server.cpp \
    Message.cpp

HEADERS += \
    Server.h
