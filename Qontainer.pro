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
    documentary.cpp \
    mainwindow.cpp \
    model.cpp \
    movie.cpp \
    mywidget.cpp \
    user.cpp \
    tvserie.cpp \
    xmlio.cpp

HEADERS  += \
    container.h \
    adddialog.h \
    audiovisual.h \
    deepptr.h \
    documentary.h \
    mainwindow.h \
    model.h \
    movie.h \
    mywidget.h \
    tvserie.h \
    user.h \
    xmlio.h
