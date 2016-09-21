#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T11:17:24
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Undo
TEMPLATE = app


SOURCES += \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    player.cpp \
    game.cpp \
    main.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    player.h \
    health.h

RESOURCES += \
    res.qrc
