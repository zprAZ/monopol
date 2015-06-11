
QT += network



HEADERS += \
    ClientSocket.h \
    PlayerFactory.h \
    Player.h \
    GameBoard.h \
    ChanceQueue.h \
    Pawn.h \
    Token.h \
    visitors/Visitor.h \
    visitors/PawnVisitor.h \
    visitors/PlayerVisitor.h \
    places/BoardPlace.h \
    places/ChancePlace.h \
    places/CityPlace.h \
    places/CornerPlace.h \
    places/CounterPlace.h \
    places/RailwayPlace.h \
    visitors/VisitorFactory.h \
    visitors/GoVisitor.h \
    visitors/CollectVisitor.h \
    visitors/PayVisitor.h \
    visitors/ReceivePrisonFreeVisitor.h \
    visitors/CollectFromOthersVisitor.h \
    visitors/TownModernizationVisitor.h \
    visitors/BuyPlaceVisitor.h \
    visitors/BuyHouseVisitor.h \
    visitors/BuyHotelVisitor.h \
    visitors/DoNothingVisitor.h \
    places/TaxPlace.h

SOURCES += \
    ClientSocket.cpp \
    main.cpp \
    PlayerFactory.cpp \
    Player.cpp \
    GameBoard.cpp \
    ChanceQueue.cpp \
    Pawn.cpp \
    Token.cpp \
    visitors/Visitor.cpp \
    visitors/PawnVisitor.cpp \
    visitors/PlayerVisitor.cpp \
    places/BoardPlace.cpp \
    places/ChancePlace.cpp \
    places/CityPlace.cpp \
    places/CornerPlace.cpp \
    places/CounterPlace.cpp \
    places/RailwayPlace.cpp \
    visitors/VisitorFactory.cpp \
    visitors/GoVisitor.cpp \
    visitors/CollectVisitor.cpp \
    visitors/PayVisitor.cpp \
    visitors/ReceivePrisonFreeVisitor.cpp \
    visitors/CollectFromOthersVisitor.cpp \
    visitors/TownModernizationVisitor.cpp \
    visitors/BuyPlaceVisitor.cpp \
    visitors/BuyHouseVisitor.cpp \
    visitors/BuyHotelVisitor.cpp \
    visitors/DoNothingVisitor.cpp \
    places/TaxPlace.cpp



QMAKE_CXXFLAGS += -std=c++11
