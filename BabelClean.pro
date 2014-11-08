QT       += core network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = Babel
DEPENDPATH += .
INCLUDEPATH += .
HEADERS += ui.h \
    comtcp.h \
    buffer.h \
    Protocol.h
SOURCES += main.cpp ui.cpp \
    comtcp.cpp \
    buffer.cpp
