#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T18:42:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    network.cpp

HEADERS  += client.h \
    network.h

FORMS    += client.ui
