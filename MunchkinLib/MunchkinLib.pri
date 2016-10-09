QT       += network

QT       -= gui

TARGET = MunchkinLib

DEFINES += MUNCHKINLIB_LIBRARY

SOURCES += $$PWD/Cards\card.cpp \
    $$PWD/Cards/action.cpp \
    $$PWD/Cards/monster.cpp \
    $$PWD/Cards/class.cpp \
    $$PWD/Cards/race.cpp \
    $$PWD/Cards/shmatte.cpp \
    $$PWD/Cards/onceaction.cpp \
    $$PWD/Entities/player.cpp

HEADERS += $$PWD/Cards\card.h\
        $$PWD/munchkinlib_global.h \
    $$PWD/Cards/action.h \
    $$PWD/Cards/monster.h \
    $$PWD/Cards/class.h \
    $$PWD/Cards/race.h \
    $$PWD/Cards/shmatte.h \
    $$PWD/Cards/onceaction.h \
    $$PWD/Entities/player.h
