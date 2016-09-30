#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T23:47:13
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MunchkinClient
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug/release/ -lMunchkinLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug/ -lMunchkinLib
else:unix: LIBS += -L$$PWD/../build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ -lMunchkinLib

INCLUDEPATH += $$PWD/../build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../build-MunchkinLib-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug
