#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T02:54:25
#
#-------------------------------------------------
TEMPLATE = lib

!include( $$PWD/MunchkinLib.pri ){
    error( "Lib not included. Filename: $$PWD/includeNetwork.pri" )
}
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    MunchkinLib.pri
