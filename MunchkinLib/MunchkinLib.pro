#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T02:54:25
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = MunchkinLib
TEMPLATE = lib

DEFINES += MUNCHKINLIB_LIBRARY

SOURCES += Cards\card.cpp \
    Cards/action.cpp \
    Cards/monster.cpp

HEADERS += Cards\card.h\
        munchkinlib_global.h \
    Cards/action.h \
    Cards/monster.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
