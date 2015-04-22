#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T15:26:17
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COS420-BSB-InfoBox
TEMPLATE = app
INCLUDEPATH += inc
OBJECTS_DIR = obj


SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/sqlhelper.cpp \
    src/androidreciever.cpp \
    src/athread.cpp \
    src/contact.cpp

HEADERS += inc/mainwindow.h \
           inc/sqlhelper.h \
    inc/androidreciever.h \
    inc/athread.h \
    inc/contact.h

FORMS   += ui/mainwindow.ui \


Release:DESTDIR = bld/release
Release:OBJECTS_DIR = bld/release/.obj
Release:MOC_DIR = bld/release/.moc
Release:RCC_DIR = bld/release/.rcc
Release:UI_DIR = bld/release/.ui

Debug:DESTDIR = bld/debug
Debug:OBJECTS_DIR = bld/debug/.obj
Debug:MOC_DIR = bld/debug/.moc
Debug:RCC_DIR = bld/debug/.rcc
Debug:UI_DIR = bld/debug/.ui

RESOURCES += \
    graphics/bsb_logo.qrc
