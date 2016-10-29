#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T14:14:04
#
#-------------------------------------------------

QT       += core gui serialport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalibrator5_7
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    portszeregowy.cpp

HEADERS  += mainwindow.h \
    portszeregowy.h

FORMS    += mainwindow.ui
