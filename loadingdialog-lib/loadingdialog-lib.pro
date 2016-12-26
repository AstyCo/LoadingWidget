#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T15:18:12
#
#-------------------------------------------------

#QT       -= gui
QT       += core gui
QMAKE_CXXFLAGS += -Wall

TARGET = loadingdialog-lib
TEMPLATE = lib

DEFINES += LOADINGDIALOG_LIBRARY

DESTDIR = $$OUT_PWD/../bin

SOURCES += \
    loadingdialog.cpp \
    waitingspinnerwidget.cpp \
    htask.cpp \
    abstracthtaskcaller.cpp \
    htaskmanager.cpp \
    multitaskloadingwidget.cpp \
    abstracthtaskbreaker.cpp \
    loadingitem.cpp

HEADERS += \
    loadingdialog.h \
    waitingspinnerwidget.h \
    loadingdialog_global.h \
    htask.h \
    abstracthtaskcaller.h \
    htaskcaller.h \
    htaskmanager.h \
    htaskextension.h \
    multitaskloadingwidget.h \
    htaskbreaker.h \
    abstracthtaskbreaker.h \
    runandwait.h \
    loadingitem.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    loadingdialog.ui \
    multitaskloadingwidget.ui \
    loadingitem.ui

DISTFILES +=

#include(build_config.pri)

RESOURCES += \
    icons.qrc

CODECFORTR = UTF-8
