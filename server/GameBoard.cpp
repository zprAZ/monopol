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
    barcelona->init(30, 100, 250, 500, 900, 1100, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(barcelona));
    // POWER STATION
    CounterPlace* electricStation = new CounterPlace(12, QString("ELECTRIC STATION"), 10, 300.0);
    placesVector.push_back(std::shared_ptr<BoardPlace>(electricStation));
    // SEWILLA
    CityPlace* sewilla = new CityPlace(13, QString("SEWILLA"),320.0);
    sewilla->init(30, 120, 300, 700, 1000, 1200, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(sewilla));
    // MADRYT
    CityPlace* madryt = new CityPlace(13, QString("MADRYT"),330.0);
    madryt->init(35, 125, 310, 800, 1100, 1300, 100, 100);
    placesVector.push_back(std::shared_ptr<BoardPlace>(madryt));
    // WEST RAILWAY

}
