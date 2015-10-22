#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T17:59:46
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += /usr/include/c++/4.3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mealplanner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    recipe.cpp \
    meal.cpp \
    mealplan.cpp \
    mpdatabase.cpp \
    createmealwindow.cpp

HEADERS  += mainwindow.h \
    recipe.h \
    meal.h \
    mealplan.h \
    mpdatabase.h \
    createmealwindow.h

FORMS    += \
    createmealtest.ui \
    mainwindow.ui \
    createmealwindow.ui
