TEMPLATE = app
TARGET = sokoban

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += \
    candle.cpp \
    main.cpp \
    player.cpp \
    map.cpp \
    game.cpp \
    cell.cpp \
    statistics.cpp

HEADERS += \
    candle.h \
    player.h \
    map.h \
    game.h \
    cell.h \
    statistics.h

RESOURCES += \
    resources.qrc
