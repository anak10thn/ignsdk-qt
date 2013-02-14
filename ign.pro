#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T23:13:36
#
#-------------------------------------------------

QT       += network core gui webkit

TARGET = ignsdk
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
    css/ign.css

RESOURCES += \
    ign.qrc
