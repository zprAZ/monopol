HEADERS += \
    boardWidget.h \
    cornerWidget.h \
    cityWidget.h \
    chanceWidget.h \
    railwayWidget.h \
    counterWidget.h \
    taxWidget.h \
    centralWidget.h \
    mainWidget.h \
    mainWindow.h \
    ip4Validator.h \
    questionDialog.h \
    ipsettingsDialog.h \
    infoDialog.h \
    ServerConnector.h

SOURCES += \
    boardWidget.cpp \
    cornerWidget.cpp \
    cityWidget.cpp \
    chanceWidget.cpp \
    railwayWidget.cpp \
    counterWidget.cpp \
    taxWidget.cpp \
    centralWidget.cpp \
    mainWidget.cpp \
    main.cpp \
    mainWindow.cpp \
    ip4Validator.cpp \
    questionDialog.cpp \
    ipsettingsDialog.cpp \
    infoDialog.cpp \
    ServerConnector.cpp

QT += network

QMAKE_CXXFLAGS += -std=c++11
