#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:07:01
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MySystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    personal.cpp \
    mylog.cpp \
    regist.cpp

HEADERS  += widget.h \
    personal.h \
    mylog.h \
    regist.h

FORMS    += widget.ui \
    personal.ui \
    mylog.ui \
    regist.ui

RESOURCES += \
    resourse/left.qrc

DISTFILES += \
    resourse/2.jpg \
    resourse/3.jpg \
    resourse/4.jpg \
    resourse/5.jpg
