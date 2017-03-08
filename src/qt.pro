TEMPLATE = app
QT += qml quick widgets

CONFIG += c++11

HEADERS += \
    channel.h \
    game.h \
    object.h \
    wall.h \
    car.h \
    park.h \
    position.h \
    map.h \
    data.h \
    CSVReader.h \
    agent.h \
    kbAgent.h \
    rightAgent.h \
    dfsAgent.h

SOURCES += \
    main.cpp \
    game.cpp \
    object.cpp \
    wall.cpp \
    car.cpp \
    park.cpp \
    position.cpp \
    map.cpp \
    data.cpp \
    agent.cpp \
    kbAgent.cpp \
    rightAgent.cpp \
    dfsAgent.cpp

RESOURCES += \
    qml.qrc
