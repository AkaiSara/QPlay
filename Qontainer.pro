#-------------------------------------------------
#
# Project created by QtCreator 2019-02-18T13:10:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qontainer
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    adddialog.cpp \
    audiovisual.cpp \
    audiovisualitem.cpp \
    displaywidget.cpp \
    documentary.cpp \
    exception.cpp \
    mainwindow.cpp \
    model.cpp \
    movie.cpp \
    mywidget.cpp \
    tvserie.cpp \
    xmlio.cpp

HEADERS  += \
    audiovisualitem.h \
    container.h \
    adddialog.h \
    audiovisual.h \
    deepptr.h \
    displaywidget.h \
    documentary.h \
    exception.h \
    mainwindow.h \
    model.h \
    movie.h \
    mywidget.h \
    tvserie.h \
    xmlio.h
