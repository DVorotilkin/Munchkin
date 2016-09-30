QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = MunchkinServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ./../MunchkinLib/Network

LIBS += "..\build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug\debug\MunchkinLib.dll"
