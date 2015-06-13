#include "GameBoard.h"
#include "places/BoardPlace.h"
#include "places/ChancePlace.h"
#include "places/CityPlace.h"
#include "places/CornerPlace.h"
#include "places/CounterPlace.h"
#include "places/RailwayPlace.h"
#include "places/TaxPlace.h"

GameBoard::GameBoard(QObject *parent) :
    QObject(parent)
{
    // START PLACE
    std::shared_ptr<BoardPlace> start(new CornerPlace(0,QString("START")));
    placesVector.push_back(start);
    // SALONIKI
    CityPlace* saloniki = new CityPlace(1,QString("SALONIKI"),100.0);
    saloniki->init(5, 25, 50, 100, 300, 500, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(saloniki));
    // CHANCE
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(2,QString("CHANCE1"))));
    // ATENY
    CityPlace* ateny = new CityPlace(3,QString("ATENY"),120.0);
    ateny->init(10, 30, 60, 150, 400, 600, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(ateny));
    // PARKING
    TaxPlace* parking = new TaxPlace(4, QString("PARKING TAX"));
    parking->init(400.0,QString("You have to pay parking fee"));
    placesVector.push_back(std::shared_ptr<BoardPlace>(parking));
    // SOUTH RAILWAY
    RailwayPlace* southRailway = new RailwayPlace(5, QString("SOUTH RAILWAY"), 400.0);
    southRailway->initPayments();
    placesVector.push_back(std::shared_ptr<BoardPlace>(southRailway));
    // NEAPOL
    CityPlace* neapol = new CityPlace(6,QString("NEAPOL"),200.0);
    neapol->init(20, 60, 100, 300, 500, 800, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(neapol));
    // CHANCE
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(7,QString("CHANCE2"))));
    // MEDIOLAN
    CityPlace* mediolan = new CityPlace(8,QString("MEDIOLAN"),250.0);
    mediolan->init(25, 80, 150, 300, 600, 800, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(mediolan));
    // ROME
    CityPlace* rome = new CityPlace(9,QString("ROME"),290.0);
    rome->init(30, 100, 200, 350, 800, 1000, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(rome));
    // VISITING PRISON
     std::shared_ptr<BoardPlace> visiting(new CornerPlace(10,QString("FOR VISITORS")));
    placesVector.push_back(visiting);
    // BARCELONA
    CityPlace* barcelona = new CityPlace(11,QString("BARCELONA"),300.0);
    barcelona->init(30, 100, 250, 500, 900, 1200, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(barcelona));
    // POWER STATION
    CounterPlace* electricStation = new CounterPlace(12, QString("ELECTRIC STATION"), 10, 300.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(electricStation));
    // SEWILLA
    CityPlace* sewilla = new CityPlace(13, QString("SEWILLA"),320.0);
    sewilla->init(30, 120, 300, 700, 1000, 1300, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(sewilla));
    // MADRYT
    CityPlace* madryt = new CityPlace(14, QString("MADRYT"),330.0);
    madryt->init(35, 125, 310, 800, 1100, 1400, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(madryt));
    // WEST RAILWAY
    RailwayPlace* westRailway = new RailwayPlace(15, QString("WAST RAILWAY"), 400.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(westRailway));
    // LIVERPOOL
    CityPlace* liverpool = new CityPlace(16, QString("LIVERPOOL"),370.0);
    liverpool->init(35, 140, 350, 1000, 1200, 1600, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(liverpool));
    // CHANCE 3
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(17,QString("CHANCE3"))));
    // GLASGOW
    CityPlace* glasgow = new CityPlace(18, QString("GLASGOW"),380.0);
    glasgow->init(40, 150, 400, 1100, 1500, 1900, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(glasgow));
    // LONDON
    CityPlace* london = new CityPlace(19, QString("LONDON"),400.0);
    london->init(45, 160, 450, 1200, 1600, 2000, 200, 200);
    placesVector.push_back(std::shared_ptr<BoardPlace>(london));
    // FREE PARKING
    std::shared_ptr<BoardPlace> freeParking(new CornerPlace(20, QString("FREE PARKING")));
    placesVector.push_back(freeParking);
    // ROTTERDAM
    CityPlace* rotterdam = new CityPlace(21, QString("ROTTERDAM"), 440.0);
    rotterdam->init(45, 180, 500, 1300, 1700, 2100, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(rotterdam));
    // CHANCE 4
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(22,QString("CHANCE4"))));
    // BRUSSEL
    CityPlace* brussel = new CityPlace(23, QString("ROTTERDAM"), 440.0);
    brussel->init(45, 180, 550, 1350, 1750, 2200, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(brussel));
    // AMSTERDAM
    CityPlace* amsterdam = new CityPlace(24, QString("AMSTERDAM"), 480.0);
    amsterdam->init(50, 200, 600, 1400, 1800, 2250, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(amsterdam));
    // NORTH RAILWAY
    RailwayPlace* northRailway = new RailwayPlace(25, QString("NORTH RAILWAY"), 400.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(northRailway));
    // MALMO
    CityPlace* malmo = new CityPlace(26, QString("MALMO"), 520.0);
    malmo->init(50, 220, 660, 1600, 1950, 2300, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(malmo));
    // GOTEBORG
    CityPlace* goteborg = new CityPlace(27, QString("GOTEBORG"), 520.0);
    goteborg->init(50, 220, 660, 1600, 1950, 2300, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(goteborg));
    // WATERWORKS
    CounterPlace* waterworks = new CounterPlace(28, QString("WATERWORKS"), 10, 300.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(waterworks));
    // SZTOKHOLM
    CityPlace* sztokholm = new CityPlace(29, QString("SZTOKHOLM"), 550.0);
    sztokholm->init(50, 250, 700, 1800, 2000, 2400, 300, 300);
    placesVector.push_back(std::shared_ptr<BoardPlace>(sztokholm));
    // PRISON
    std::shared_ptr<BoardPlace> prison(new CornerPlace(30, QString("PRISON")));
    placesVector.push_back(prison);
    // FRANKFURT
    CityPlace* frankfurt = new CityPlace(31, QString("FRANKFURT"), 600.0);
    frankfurt->init(55, 250, 660, 1800, 2200, 2600, 400, 400);
    placesVector.push_back(std::shared_ptr<BoardPlace>(frankfurt));
    // KOLONY
    CityPlace* kolony = new CityPlace(32, QString("KOLONY"), 600.0);
    kolony->init(55, 250, 660, 1800, 2200, 2600, 400, 400);
    placesVector.push_back(std::shared_ptr<BoardPlace>(kolony));
    // CHANCE 5
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(33,QString("CHANCE5"))));
    // BONN
    CityPlace* bonn = new CityPlace(34, QString("BONN"), 650.0);
    bonn->init(60, 300, 700, 2000, 2400, 2800, 400, 400);
    placesVector.push_back(std::shared_ptr<BoardPlace>(bonn));
    // EAST RAILWAY
    RailwayPlace* eastRailway = new RailwayPlace(35, QString("EAST RAILWAY"), 400.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(eastRailway));
    // CHANCE 6
    placesVector.push_back(std::shared_ptr<BoardPlace>(new ChancePlace(36,QString("CHANCE6"))));
    // INSBRUCK
    CityPlace* insbruck = new CityPlace(37, QString("INSBRUCK"), 700.0);
    insbruck->init(70, 350, 900, 2200, 2800, 3500, 400, 400);
    placesVector.push_back(std::shared_ptr<BoardPlace>(insbruck));
    // INCOME TAX
    TaxPlace* incomeTax = new TaxPlace(38, QString("INCOME TAX"));
    parking->init(200.0,QString("You have to pay income tax"));
    placesVector.push_back(std::shared_ptr<BoardPlace>(incomeTax));
    // VIENNA
    CityPlace* vienna = new CityPlace(39, QString("VIENNA"), 800.0);
    vienna->init(100, 400, 1400, 2500, 3000, 4000, 400, 400);
    placesVector.push_back(std::shared_ptr<BoardPlace>(vienna));

    Q_ASSERT(placesVector.size() == 40);
}
