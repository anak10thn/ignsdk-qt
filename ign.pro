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
    ignsql.cpp

HEADERS  += ign.h \
    fs.h \
    igndownload.h \
    ignsql.h

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
    platform/SPECS/ignsdk.spec

RESOURCES += \
    ign.qrc
LIBS += -L/usr/lib -lqjson

win32:CONFIG(release, debug|release): LIBS += -L/lib/mysql/release/ -lmysqlclient_r
else:win32:CONFIG(debug, debug|release): LIBS += -L/lib/mysql/debug/ -lmysqlclient_r
else:unix: LIBS += -L/lib/mysql/ -lmysqlclient_r

INCLUDEPATH += /lib/mysql
DEPENDPATH += /lib/mysql
