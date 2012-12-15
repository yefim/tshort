TARGET = model
TEMPLATE = lib
CONFIG += shared x86_64
QT += sql
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects
DEPENDPATH  += ../helpers sqlobjects
LIBS += -L../lib -lhelper

include(../appbase.pri)

HEADERS += shorturlobject.h
HEADERS += shorturl.h
SOURCES += shorturl.cpp
