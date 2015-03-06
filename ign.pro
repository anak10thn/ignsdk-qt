#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core webkitwidgets sql printsupport serialport

TARGET = ignsdk
TEMPLATE = app
CONFIG += qt

SOURCES += src/main.cpp\
        src/ign.cpp \
    src/fs.cpp \
    src/igndownload.cpp \
    src/ignsql.cpp \
    src/ignsystem.cpp \
    src/ignnetwork.cpp \
    src/ignprocess.cpp \
    src/ignserial.cpp

HEADERS  += src/ign.h \
    src/fs.h \
    src/igndownload.h \
    src/ignsql.h \
    src/ignsystem.h \
    src/ignnetwork.h \
    src/version.h \
    src/ignjson.h \
    src/ignprocess.h \
    src/ignserial.h

RESOURCES += \
    ign.qrc

macx{
ICON += icon/ignsdk-logo.icns
}

OTHER_FILES += \
    bar-descriptor.xml

OBJECTS_DIR = ./build
MOC_DIR = ./build
DESTDIR = ./bin

DISTFILES += \
    LICENSE.BSD
