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
        widget.cpp \
    AudioVisual.cpp \
    notes.cpp \
    Model.cpp \
    Documentary.cpp \
    User.cpp \
    Movie.cpp \
    TVSerie.cpp \
    adddialog.cpp

HEADERS  += widget.h \
    AudioVisual.h \
    container.h \
    deepPtr.h \
    Model.h \
    Documentary.h \
    User.h \
    Movie.h \
    TVSerie.h \
    adddialog.h
