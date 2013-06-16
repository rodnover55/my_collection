#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T14:18:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my_collection
TEMPLATE = app


SOURCES += main.cpp\
    view/fartistsadd.cpp \
    view/falbumadd.cpp \
    view/fcollection.cpp \
    model/album.cpp

HEADERS  += \
    view/fartistsadd.h \
    view/falbumadd.h \
    view/fcollection.h \
    model/album.h

FORMS    += \
    view/fartistsadd.ui \
    view/falbumadd.ui \
    view/fcollection.ui
