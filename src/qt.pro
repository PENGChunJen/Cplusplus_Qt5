TEMPLATE = app
QT += qml quick widgets

CONFIG += c++11

HEADERS += \
    map.h \
    channel.h \
    agent.h \
    park.h \
    object.h \
    car.h \
    game.h \
    position.h \
    randomAgent.h \
    wall.h \
    kbAgent.h \
    data.h \
    CSVReader.h

SOURCES += \
    main.cpp \
    map.cpp \
    agent.cpp \
    car.cpp \
    game.cpp \
    object.cpp \
    park.cpp \
    position.cpp \
    randomAgent.cpp \
    wall.cpp \
    kbAgent.cpp \
    data.cpp

RESOURCES += \
    qml.qrc
