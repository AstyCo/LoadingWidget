#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T15:18:12
#
#-------------------------------------------------

#QT       -= gui

TARGET = loadingdialog-lib
TEMPLATE = lib
CONFIG += staticlib

DEFINES += LOADINGDIALOG_LIBRARY

SOURCES += \
    loadingdialog.cpp \
    loadingdialogsingleton.cpp \
    waitingspinnerwidget.cpp \
    htask.cpp \
    abstracthtaskcaller.cpp \
    abstracthtaskcancealer.cpp \
    htaskcaller.cpp \
    htaskcancealer.cpp \
    htaskmanager.cpp \
    loadingdialogitem.cpp \
    multitaskloadingwidget.cpp

HEADERS += \
    loadingdialog.h \
    loadingdialogsingleton.h \
    runandwait.h \
    waitingspinnerwidget.h \
    loadingdialog_global.h \
    htask.h \
    abstracthtaskcaller.h \
    abstracthtaskcancealer.h \
    htaskcaller.h \
    htaskcancealer.h \
    htaskmanager.h \
    loadingdialogitem.h \
    multitaskloadingwidget.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    loadingdialog.ui \
    loadingdialogitem.ui \
    multitaskloadingwidget.ui
