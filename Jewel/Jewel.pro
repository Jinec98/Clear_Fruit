#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T20:11:06
#
#-------------------------------------------------

QT       += core gui
RC_ICONS = resource/icon.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jewel
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    block.cpp \
    platfrom.cpp \
    fileoper.cpp \
    jewelgame.cpp

HEADERS  += gamewindow.h \
    block.h \
    platfrom.h \
    fileoper.h \
    jewelgame.h

FORMS    += gamewindow.ui

RESOURCES += \
    resource.qrc
