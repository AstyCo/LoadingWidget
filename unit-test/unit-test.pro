#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T15:19:25
#
#-------------------------------------------------

QT       += testlib

#QT       -= gui

TARGET = test
#CONFIG   += console
#CONFIG   -= app_bundle
DEFINES += SRCDIR=\\\"$$PWD/\\\"
TEMPLATE = app

DESTDIR = $$OUT_PWD/../bin

unix:{
    CONFIG += debug_and_release debug_and_release_target
}
# выведем сообщение компилятора в каком режиме собираем (для проверки)
release:message(Building in release mode.)
debug:message(Building in debug mode.)


# подключить библиотеки и *.h файлы
CONFIG += depend_includepath

INCLUDEPATH += "$$PWD/../loadingdialog-lib/"



message(DESTDIR: $$DESTDIR)
LIBS += -L"$${DESTDIR}"
CONFIG(release, debug|release) {
    LIBS += -lloadingdialog-lib
} else:CONFIG(debug, debug|release) {
    LIBS += -lloadingdialog-lib
}

SOURCES += tst_classtest.cpp \
    myclass.cpp

HEADERS += \
    myclass.h
