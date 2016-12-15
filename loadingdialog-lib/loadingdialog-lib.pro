#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T15:18:12
#
#-------------------------------------------------

#QT       -= gui
QT       += core gui

TARGET = loadingdialog-lib
TEMPLATE = lib
#CONFIG += staticlib
DEFINES += LOADINGDIALOG_LIBRARY

DESTDIR = $$OUT_PWD/../bin

SOURCES += \
    loadingdialog.cpp \
    loadingdialogsingleton.cpp \
    waitingspinnerwidget.cpp \
    htask.cpp \
    abstracthtaskcaller.cpp \
    htaskmanager.cpp \
    loadingdialogitem.cpp \
    multitaskloadingwidget.cpp \
    abstracthtaskbreaker.cpp

HEADERS += \
    loadingdialog.h \
    loadingdialogsingleton.h \
    waitingspinnerwidget.h \
    loadingdialog_global.h \
    htask.h \
    abstracthtaskcaller.h \
    htaskcaller.h \
    htaskmanager.h \
    loadingdialogitem.h \
    htaskextension.h \
    multitaskloadingwidget.h \
    htaskbreaker.h \
    abstracthtaskbreaker.h \
    runandwaitsingleton.h \
    runandwait.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    loadingdialog.ui \
    loadingdialogitem.ui \
    multitaskloadingwidget.ui

DISTFILES +=

#include(build_config.pri)

RESOURCES += \
    icons.qrc

CODECFORTR = UTF-8
