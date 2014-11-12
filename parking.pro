#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T17:14:15
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    in.cpp \
    out.cpp \
    admin.cpp

HEADERS  += mainwindow.h \
    in.h \
    out.h \
    admin.h

FORMS    += mainwindow.ui \
    in.ui \
    out.ui \
    admin.ui
