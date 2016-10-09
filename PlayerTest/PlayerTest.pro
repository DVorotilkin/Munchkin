QT += core
QT -= gui

CONFIG += c++11

TARGET = PlayerTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \

!include( $$PWD/../MunchkinLib/MunchkinLib.pri ){
    error( "includeDirs not included. Filename: $$PWD/includeNetwork.pri" )
}


