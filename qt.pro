TEMPLATE = app
QT += qml quick widgets

CONFIG += c++11

HEADERS += \
    src/agent.h \
    src/bfsAgent.h \
    src/car.h \
    src/channel.h \
    src/CSVReader.h \
    src/data.h \
    src/dfsAgent.h \
    src/game.h \
    src/kbAgent.h \
    src/map.h \
    src/object.h \
    src/park.h \
    src/position.h \
    src/rightAgent.h \
    src/wall.h

SOURCES += \
    src/agent.cpp \
    src/bfsAgent.cpp \
    src/car.cpp \
    src/data.cpp \
    src/dfsAgent.cpp \
    src/game.cpp \
    src/kbAgent.cpp \
    src/main.cpp \
    src/map.cpp \
    src/object.cpp \
    src/park.cpp \
    src/position.cpp \
    src/rightAgent.cpp \
    src/wall.cpp

RESOURCES += \
    qml.qrc
