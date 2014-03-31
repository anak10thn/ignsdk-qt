#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core webkitwidgets sql

TARGET = ignsdk
TEMPLATE = app
CONFIG += qt

SOURCES += main.cpp\
        ign.cpp \
    fs.cpp \
    igndownload.cpp \
    ignsql.cpp \
    ignsystem.cpp \
    ignmovedrag.cpp \
    ignnetwork.cpp

HEADERS  += ign.h \
    fs.h \
    igndownload.h \
    ignsql.h \
    ignsystem.h \
    ignmovedrag.h \
    ignnetwork.h

RESOURCES += \
    ign.qrc

macx{
ICON += icon/ignsdk-logo.icns
}

OTHER_FILES += \
    bar-descriptor.xml
