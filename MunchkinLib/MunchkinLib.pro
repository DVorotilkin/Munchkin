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
    Cards/monster.cpp \
    Cards/class.cpp \
    Cards/race.cpp \
    Cards/shmatte.cpp \
    Cards/onceaction.cpp \
    Entities/player.cpp \
    Network/network.cpp \
    Network/servernetwork.cpp \
    Network/clientnetwork.cpp

HEADERS += Cards\card.h\
        munchkinlib_global.h \
    Cards/action.h \
    Cards/monster.h \
    Cards/class.h \
    Cards/race.h \
    Cards/shmatte.h \
    Cards/onceaction.h \
    Entities/player.h \
    Network/network.h \
    Network/servernetwork.h \
    Network/clientnetwork.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
