
QT += network

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ClientSocket.h \
    PlayerFactory.h \
    Player.h

SOURCES += \
    ClientSocket.cpp \
    main.cpp \
    PlayerFactory.cpp \
    Player.cpp
