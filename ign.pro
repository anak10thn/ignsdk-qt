#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core webkitwidgets sql printsupport serialport

TARGET = ignsdk
TEMPLATE = app
CONFIG += qt

DEFINES *= _FORTIFY_SOURCE=2
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -O3 -Wformat -Wformat-security -fstack-protector
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3 -Wformat -Wformat-security -fstack-protector
QMAKE_LFLAGS_RELEASE -= -Wl,-O1
QMAKE_LFLAGS_RELEASE += -Wl,-O3 -Wl,-z,relro -Wl,-z,now -pie

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
    src/ignserial.h \
    src/winopt.h

RESOURCES += \
    ign.qrc

macx{
ICON += icon/ignsdk-logo.icns
}

OTHER_FILES += \
    bar-descriptor.xml

OBJECTS_DIR = ./build
MOC_DIR = ./build
RCC_DIR = ./build
DESTDIR = ./bin

DISTFILES += \
    LICENSE.BSD
