#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T17:28:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

DESTDIR = $$OUT_PWD/../bin

release:message(Building in release mode.)
debug:message(Building in debug mode.)


# подключить библиотеки и *.h файлы
#CONFIG += depend_includepath

INCLUDEPATH += "$$PWD/../loadingdialog-lib/"

message(PWD: $$PWD)
message(DESTDIR: $$DESTDIR)

LIBS += -L"$${DESTDIR}"
CONFIG(release, debug|release) {
    LIBS += -lloadingdialog-lib
} else:CONFIG(debug, debug|release) {
    LIBS += -lloadingdialog-lib
}



SOURCES += main.cpp\
        mainwindow.cpp \
    myclass.cpp

HEADERS  += mainwindow.h \
    myclass.h

FORMS    += mainwindow.ui

CODECFORTR = UTF-8
