TEMPLATE = subdirs

CONFIG +=  ordered
QMAKE_CXXFLAGS += -Wall

SUBDIRS += \
    loadingdialog-lib \
#    unit-test \
    test
