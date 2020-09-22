#-------------------------------------------------
#
# Project created by QtCreator 2019-08-17T10:51:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widget_my
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    Title.cpp \
        widget.cpp \
    test.cpp

HEADERS  += widget.h \
    Title.h \
    test.h

FORMS    +=

RESOURCES += \
    image.qrc
