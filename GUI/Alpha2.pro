#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T18:48:44
#
#-------------------------------------------------
# Some code for qhoversensitivebutton.cpp taken from
# http://amin-ahmadi.com/2016/02/01/mouse-hover-over-event-qt-widget/


QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Alpha2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qhoversensitivebutton.cpp \
    release.cpp \
    functions.cpp

HEADERS += \
        mainwindow.h \
    qhoversensitivebutton.h \
    release.h \
    functions.h

FORMS += \
        mainwindow.ui \
    release.ui

RESOURCES += \
    resource.qrc
