#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core gui webkit sql

TARGET = ignsdk
TEMPLATE = app


SOURCES += main.cpp\
        ign.cpp \
    fs.cpp \
    igndownload.cpp \
    ignsql.cpp \
    ignnetwork.cpp \
    ignsystem.cpp

HEADERS  += ign.h \
    fs.h \
    igndownload.h \
    ignsql.h \
    ignnetwork.h \
    ignsystem.h

OTHER_FILES += \
    js/jquery.js \
    js/ign.js \
    examples/index.html \
    js/bootstrap.min.js \
    js/bootstrap.js \
    img/glyphicons-halflings.png \
    img/glyphicons-halflings-white.png \
    css/bootstrap.min.css \
    css/bootstrap.css \
    css/bootstrap-responsive.min.css \
    css/bootstrap-responsive.css \
    test/bootstrap/index.html \
    test/widget.ign/index.html \
    test/bootstrap.ign/index.html \
    README.md \
    css/ign.css \
    js/skulpt.js \
    js/builtin.js \
    platform/ARCH/PKGBUILD \
    platform/SPECS/ignsdk.spec \
    platform/debian/README.Debian \
    platform/debian/ignsdk-debian.dirs \
    platform/debian/ignsdk-debian-example.install \
    platform/debian/docs \
    platform/debian/copyright \
    platform/debian/control \
    platform/debian/compat \
    platform/debian/changelog \
    platform/debian/rules \
    platform/debian/source/format \
    platform/debian/patches/series \
    platform/debian/patches/buildtarget.diff \
    js/include.js

RESOURCES += \
    ign.qrc
LIBS += -L/usr/lib -lqjson

win32:CONFIG(release, debug|release): LIBS += -L/lib/mysql/release/ -lmysqlclient_r
else:win32:CONFIG(debug, debug|release): LIBS += -L/lib/mysql/debug/ -lmysqlclient_r
else:unix: LIBS += -L/lib/mysql/ -lmysqlclient_r

INCLUDEPATH += /lib/mysql
DEPENDPATH += /lib/mysql
