#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T13:52:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViGi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    table.cpp \
    topic.cpp \
    businesstopic.cpp \
    contactstopic.cpp \
    notestopic.cpp \
    sqlstoredprocedures.cpp \
    databasedriver.cpp

HEADERS  += mainwindow.h \
    table.h \
    topic.h \
    businesstopic.h \
    contactstopic.h \
    notestopic.h \
    sqlstoredprocedures.h \
    databasedriver.h

FORMS    += mainwindow.ui
