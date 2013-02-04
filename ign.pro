#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core gui webkit

TARGET = ign
TEMPLATE = app


SOURCES += main.cpp\
        ign.cpp \
    fs.cpp

HEADERS  += ign.h \
    fs.h

OTHER_FILES += \
    js/jquery.js \
    js/ign.js \
    examples/index.html \
    test/index.html

RESOURCES += \
    ign.qrc
