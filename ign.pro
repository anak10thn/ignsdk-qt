#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core webkitwidgets sql

TARGET = ignsdk
TEMPLATE = app


SOURCES += main.cpp\
        ign.cpp \
    fs.cpp \
    igndownload.cpp \
    ignsql.cpp \
    ignnetwork.cpp \
    ignsystem.cpp \
    ignmovedrag.cpp

HEADERS  += ign.h \
    fs.h \
    igndownload.h \
    ignsql.h \
    ignnetwork.h \
    ignsystem.h \
    ignmovedrag.h

RESOURCES += \
    ign.qrc

macx{
ICON += icon/ignsdk-logo.icns
}
