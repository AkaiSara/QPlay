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
    model.cpp \
    movie.cpp \
    user.cpp \
    tvserie.cpp \
    view.cpp

HEADERS  += \
    container.h \
    adddialog.h \
    audiovisual.h \
    deepptr.h \
    documentary.h \
    model.h \
    movie.h \
    tvserie.h \
    user.h \
    view.h
