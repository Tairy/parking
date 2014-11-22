#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T17:14:15
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    in.cpp \
    out.cpp \
    admin.cpp \
    map.cpp \
    drawmap.cpp \
    tileset.cpp \
    nav.cpp \
    config.cpp \
    database.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    in.h \
    out.h \
    admin.h \
    map.h \
    drawmap.h \
    tileset.h \
    nav.h \
    config.h \
    database.h \
    dialog.h

FORMS    += mainwindow.ui \
    in.ui \
    out.ui \
    admin.ui \
    nav.ui \
    dialog.ui
