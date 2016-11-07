#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T13:52:39
#
#-------------------------------------------------

QT       += core gui sql

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
    databasedriver.cpp \
    blankforbusinessitem.cpp \
    blankforcontactsitem.cpp \
    blankfornotesitem.cpp

HEADERS  += mainwindow.h \
    table.h \
    topic.h \
    businesstopic.h \
    contactstopic.h \
    notestopic.h \
    sqlstoredprocedures.h \
    databasedriver.h \
    blankforbusinessitem.h \
    blankforcontactsitem.h \
    blankfornotesitem.h

FORMS    += mainwindow.ui
