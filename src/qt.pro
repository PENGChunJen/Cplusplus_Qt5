TEMPLATE = app
QT += qml quick widgets

CONFIG += c++11

HEADERS += \
    map.h \
    channel.h \
    agent.h \
    park.h \
    object.h

SOURCES += \
    main.cpp \
    map.cpp

RESOURCES += \
    qml.qrc
