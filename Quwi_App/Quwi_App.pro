#-------------------------------------------------
#
# Project created by QtCreator 2020-11-20T16:45:00
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += quick
CONFIG += c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Quwi_App
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += incl

SOURCES += src/main.cpp\
    src/QuwiMainwindow.cpp \
    src/quwiRequest.cpp \
    src/quwiImageRequest.cpp \
    src/quwiloginRequest.cpp \
    src/quwilogoutRequest.cpp \
    src/quwiprjListRequest.cpp \
    src/quwiprjDataRequest.cpp \
    src/quwiChangePrjNameRequest.cpp \
    src/quwiNetworkMgr.cpp \
    src/quwiLoginView.cpp \
    src/quwiPrjsListView.cpp \
    src/quwiPrjView.cpp \
    src/checkablebutton.cpp


HEADERS  += \
    incl/QuwiMainwindow.h \
    incl/quwiRequest.h \
    incl/quwiImageRequest.h \
    incl/quwiloginRequest.h \
    incl/quwilogoutRequest.h \
    incl/quwiprjListRequest.h \
    incl/quwiprjDataRequest.h \
    incl/quwiChangePrjNameRequest.h \
    incl/quwiNetworkMgr.h \
    incl/quwiLoginView.h \
    incl/quwiPrjsListView.h \
    incl/quwiPrjView.h \
    incl/checkablebutton.h

FORMS += \
    quwimainwindow.ui

DISTFILES +=

RESOURCES += \
    res.qrc
