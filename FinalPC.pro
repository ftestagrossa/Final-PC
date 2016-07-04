#-------------------------------------------------
#
# Project created by QtCreator 2016-07-02T16:22:52
#
#-------------------------------------------------

QT       += core gui  widgets sql
QMAKE_CXXFLAGS += -fopenmp
QMAKE_CFLAGS_DEBUG += -fopenmp
LIBS += -fopenmp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalPC
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    controladorcalcular.cpp \
    factoryfuncion.cpp \
    factorymetodo.cpp \
    admindb.cpp \
    metodosimpson.cpp \
    metodotrapecio.cpp \
    metodorectangulo.cpp \
    metodopuntomedio.cpp

HEADERS  += mainwidget.h \
    metodorectangulo.h \
    factorymetodo.h \
    funcionseno.h \
    factoryfuncion.h \
    abstractfuncion.h \
    abstractmetodo.h \
    controladorcalcular.h \
    admindb.h \
    metodotrapecio.h \
    metodosimpson.h \
    metodopuntomedio.h

FORMS    += mainwidget.ui
