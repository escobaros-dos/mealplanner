#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T17:59:46
#
#-------------------------------------------------

QT       += core gui
QT       += sql

INCLUDEPATH += /usr/include/c++/4.3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mealplanner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    recipe.cpp \
    mpdatabase.cpp \
    ingredient.cpp \
    createrecipewindow.cpp \
    recipebook.cpp \
    viewmealdetails.cpp \
    createingridientwindow.cpp

HEADERS  += mainwindow.h \
    recipe.h \
    mpdatabase.h \
    ingredient.h \
    createrecipewindow.h \
    recipebook.h \
    viewmealdetails.h \
    createingridientwindow.h

FORMS    += \
    #createmealtest.ui \
    mainwindow.ui \
    createrecipewindow.ui \
    recipebook.ui \
    viewmealdetails.ui \
    createingridientwindow.ui
