#include "mainWidget.h"
#include <QVector>

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent)
{

    // list of useful containers useful for signals-slots initialization
    QVector<cityWidget*> cities;
    QVector<boardWidget*> allPlaces;
    QVector<counterWidget*> counters;
    QVector<railwayWidget*> railways;
    // start widget
    cornerWidget* start_w = new cornerWidget(0,
                            QString("START"));
    allPlaces.push_back(start_w);
    // saloniki
    cityWidget* saloniki = new cityWidget(1, QString("SALONIKI"));
    saloniki->setCityColor(Qt::yellow);
    cities.push_back(saloniki);
    allPlaces.push_back(saloniki);
    // first chance
    chanceWidget* chance1 = new chanceWidget(2, chanceWidget::alignment::TOP);
    allPlaces.push_back(chance1);
    // ateny
    cityWidget* ateny = new cityWidget(3,QString("ATENY"));
    ateny->setCityColor(Qt::yellow);
    cities.push_back(ateny);
    allPlaces.push_back(ateny);
    // first tax
    taxWidget* parking = new taxWidget(400, QString("PAYMENT PARKING"),
                                       4, taxWidget::alignment::TOP);
    allPlaces.push_back(parking);
    // south railway
    railwayWidget* southRailway = new railwayWidget(5, QString("SOUTH RAILWAY"),
                                                    railwayWidget::alignment::TOP);
    railways.push_back(southRailway);
    allPlaces.push_back(southRailway);
    // NEAPOL
    cityWidget* neapol = new cityWidget(6, QString("NEAPOL"), cityWidget::alignment::TOP);
    neapol->setCityColor(Qt::red);
    cities.push_back(neapol);
    allPlaces.push_back(neapol);
    // chance
    chanceWidget* chance2 = new chanceWidget(7, chanceWidget::alignment::TOP);
    allPlaces.push_back(chance2);
    // mediolan
    cityWidget* mediolan = new cityWidget(8, QString("MEDIOLAN"), cityWidget::alignment::TOP);
    mediolan ->setCityColor(Qt::red);
    cities.push_back(mediolan);
    allPlaces.push_back(mediolan);
    // rome
    cityWidget* rome = new cityWidget(9, QString("ROME"), cityWidget::alignment::TOP);
    rome->setCityColor(Qt::red);
    cities.push_back(rome);
    allPlaces.push_back(rome);
    // just visiting prison
    cornerWidget* prisonVisiting = new cornerWidget(10, QString("VISITING prison"),
                                                    cornerWidget::alignment::TOP);
    allPlaces.push_back(prisonVisiting);
    // barcelona
    cityWidget* barcelona = new cityWidget(11, QString("BARCELONA"), cityWidget::alignment::RIGHT);
    barcelona->setCityColor(Qt::blue);
    cities.push_back(barcelona);
    allPlaces.push_back(barcelona);
    // power station
    counterWidget* powerStation = new counterWidget(QString("POWER STATION"),12, counterWidget::alignment::RIGHT);
    counters.push_back(powerStation);
    allPlaces.push_back(powerStation);
    // sewilla
    cityWidget* sewilla = new cityWidget(13, QString("SEWILLA"), cityWidget::alignment::RIGHT);
    sewilla ->setCityColor(Qt::blue);
    cities.push_back(sewilla);
    allPlaces.push_back(sewilla);
    // madryt
    cityWidget* madryt = new cityWidget(14, QString("MADRYT"), cityWidget::alignment::RIGHT);
    madryt -> setCityColor(Qt::blue);
    cities.push_back(madryt);
    allPlaces.push_back(madryt);
    // west railway
    railwayWidget* westRailway = new railwayWidget(15, QString("WEST"), railwayWidget::alignment::RIGHT);
    railways.push_back(westRailway);
    allPlaces.push_back(westRailway);
    // liverpol
    cityWidget* liverpol = new cityWidget(16, QString("LIVERPOL"), cityWidget::alignment::RIGHT);
    liverpol ->setCityColor(QColor(Qt::cyan));
    cities.push_back(liverpol);
    allPlaces.push_back(liverpol);
    // chance 3
    chanceWidget* chance3 = new chanceWidget(17, chanceWidget::alignment::RIGHT);
    allPlaces.push_back(chance3);
    // glasgow
    cityWidget* glasgow = new cityWidget(18, QString("GLASGOW"), cityWidget::alignment::RIGHT);
    glasgow ->setCityColor(Qt::cyan);
    cities.push_back(glasgow);
    allPlaces.push_back(glasgow);
    // london
    cityWidget* london = new cityWidget(19, QString("LONDON"), cityWidget::alignment::RIGHT);
    london -> setCityColor(Qt::cyan);
    cities.push_back(london);
    allPlaces.push_back(london);
    // free parking
    cornerWidget* freeParking = new cornerWidget(20, QString("FREE PARKING"), cornerWidget::alignment::BOTTOM);
    allPlaces.push_back(freeParking);
    // rotterdam
    cityWidget* rotterdam = new cityWidget(21, QString("ROTTERDAM"), cityWidget::alignment::BOTTOM);
    rotterdam->setCityColor(Qt::green);
    cities.push_back(rotterdam);
    allPlaces.push_back(rotterdam);
    // chance 4
    chanceWidget* chance4 = new chanceWidget(22, chanceWidget::alignment::BOTTOM);
    allPlaces.push_back(chance4);
    // brussel
    cityWidget* brussel = new cityWidget(23, QString("BRUSSEL"), cityWidget::alignment::BOTTOM);
    brussel ->setCityColor(Qt::green);
    cities.push_back(brussel);
    allPlaces.push_back(brussel);
    // amsterdam
    cityWidget* amsterdam = new cityWidget(24, QString("AMSTERDAM"), cityWidget::alignment::BOTTOM);
    amsterdam->setCityColor(Qt::green);
    cities.push_back(amsterdam);
    allPlaces.push_back(amsterdam);
    // north railways
    railwayWidget* northRailway = new railwayWidget(25, QString("NORTH RAILWAY"), cityWidget::alignment::BOTTOM);
    allPlaces.push_back(northRailway);
    // malmo
    cityWidget* malmo = new cityWidget(26, QString("MALMO"), cityWidget::alignment::BOTTOM);
    malmo ->setCityColor(Qt::magenta);
    cities.push_back(malmo);
    allPlaces.push_back(malmo);
    // goteborg
    cityWidget* goteborg = new cityWidget(27, QString("GOTEBORG"), cityWidget::alignment::BOTTOM);
    goteborg -> setCityColor(Qt::magenta);
    cities.push_back(goteborg);
    allPlaces.push_back(goteborg);
    // waterworks
    counterWidget* waterworks = new counterWidget(QString("WATERWORKS"), 28, counterWidget::alignment::BOTTOM);
    allPlaces.push_back(waterworks);
    // sztokholm
    cityWidget* sztokholm = new cityWidget(29, QString("SZTOKHOLM"), cityWidget::alignment::BOTTOM);
    sztokholm -> setCityColor(Qt::magenta);
    cities.push_back(sztokholm);
    allPlaces.push_back(sztokholm);
    // PRISON
    cornerWidget* prison = new cornerWidget(30, QString("PRISON"), cornerWidget::alignment::BOTTOM);
    allPlaces.push_back(prison);
    // FRANKFURT
    cityWidget* frankfurt = new cityWidget(31, QString("FRANKFURT"), cityWidget::alignment::LEFT);
    frankfurt ->setCityColor(QColor(205, 102, 0));
    cities.push_back(frankfurt);
    allPlaces.push_back(frankfurt);
    // KOLONY
    cityWidget* kolonia = new cityWidget(32, QString("KOLONIA"), cityWidget::alignment::LEFT);
    kolonia -> setCityColor(QColor(205, 102, 0));
    cities.push_back(kolonia);
    allPlaces.push_back(kolonia);
    // chance 5
    chanceWidget* chance5 = new chanceWidget(33, chanceWidget::alignment::LEFT);
    allPlaces.push_back(chance5);
    // BONN
    cityWidget* bonn = new cityWidget(34, QString("BONN"), cityWidget::alignment::LEFT);
    bonn ->setCityColor(QColor(205, 102, 0));
    cities.push_back(bonn);
    allPlaces.push_back(bonn);
    // east railways
    railwayWidget* eastRailways = new railwayWidget(35, QString("EAST RAILWAYS"),
                                                   railwayWidget::alignment::LEFT);
    railways.push_back(eastRailways);
    allPlaces.push_back(eastRailways);
    //chance 6
    chanceWidget* chance6 = new chanceWidget(36, chanceWidget::alignment::LEFT);
    allPlaces.push_back(chance6);
    // insbruck
    cityWidget* insbruck = new cityWidget(37, QString("INSBRUCK"), cityWidget::alignment::LEFT);
    insbruck ->setCityColor(Qt::black);
    cities.push_back(insbruck);
    allPlaces.push_back(insbruck);
    // super tax
    taxWidget* superTax = new taxWidget(200, QString("SUPER TAX"),38, taxWidget::alignment::LEFT);
    allPlaces.push_back(superTax);
    // Vienna
    cityWidget* vienna = new cityWidget(39, QString("VIENNA"), cityWidget::alignment::LEFT);
    vienna -> setCityColor(Qt::black);
    cities.push_back(vienna);
    allPlaces.push_back(vienna);

    // setting signals and slots
    // loop for all places
    for(QVector<boardWidget*>::iterator iter = allPlaces.begin(); iter != allPlaces.end(); ++iter)
    {
        QObject::connect(this, SIGNAL(tokenEntering_s(int,boardWidget::playerColor)),
                                      *iter, SLOT(tokenIsEntering(int,playerColor)));
        QObject::connect(this, SIGNAL(tokenLeaving_s(int,boardWidget::playerColor)),
                         *iter, SLOT(tokenIsLeaving(int,playerColor)));
    }
    // loop for all cities
    for(QVector<cityWidget*>::iterator iter = cities.begin(); iter != cities.end(); ++iter)
    {
    QObject::connect(this, SIGNAL(hotel_s(int,bool)), *iter, SLOT(doHotel(int,bool)));
    QObject::connect(this, SIGNAL(house_s(int,bool)), *iter, SLOT(doHouse(int,bool)));
    QObject::connect(this, SIGNAL(deleteHouses_s(int)), *iter, SLOT(deleteAllHouses(int)));
    QObject::connect(this, SIGNAL(setMortgage_s(int,bool)), *iter, SLOT(setMortgageFlag(int,bool)));
    QObject::connect(this, SIGNAL(setOwnership_s(int,bool,boardWidget::playerColor)), *iter,
                     SLOT(setOwnershipFlag(int,bool,playerColor)));
    }

    // loop for all railways
    for(QVector<railwayWidget*>::iterator iter = railways.begin(); iter != railways.end(); ++iter)
    {
        QObject::connect(this, SIGNAL(setMortgage_s(int,bool)), *iter, SLOT(setMortgageFlag(int,bool)));
        QObject::connect(this, SIGNAL(setOwnership_s(int,bool,boardWidget::playerColor)),
                         *iter, SLOT(setOwnershipFlag(int,bool,playerColor)));
    }
    for(QVector<counterWidget*>::iterator iter = counters.begin(); iter != counters.end(); ++iter)
    {
        QObject::connect(this, SIGNAL(setMortgage_s(int,bool)), *iter, SLOT(setMortgageFlag(int,bool)));
        QObject::connect(this, SIGNAL(setOwnership_s(int,bool,boardWidget::playerColor)),
                         *iter, SLOT(setOwnershipFlag(int,bool,playerColor)));
    }
    // loop for all counters

    // adding layouts
    // list of layouts
    QHBoxLayout* topLayout = new QHBoxLayout;
    QHBoxLayout* middleLayout = new QHBoxLayout;
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    QVBoxLayout* leftLayout = new QVBoxLayout;
    QVBoxLayout* rightLayout = new QVBoxLayout;
    topLayout ->addWidget(start_w);
    topLayout ->addWidget(saloniki);
    topLayout -> addWidget(chance1);
    topLayout ->addWidget(ateny);
    topLayout ->addWidget(parking);
    topLayput ->addWidget(southRailway);
    topLayout ->addWidget(neapol);
    topLayout ->addWidget(chance2);
    topLayout ->addWidget(mediolan);
    topLayout ->addWidget(rome);
    topLayout ->addWidget(prisonVisiting);

}


void mainWidget::tokenIsLeaving(int placeId, int playerId)
{
    emit tokenLeaving_s(placeId, playerId2color(playerId));
}

void mainWidget::tokenIsEntering(int placeId, int playerId)
{
    emit tokenEntering_s(placeId, playerId2color(playerId));
}

void mainWidget::displayRound(int round)
{
    emit round_s(round);
}

void mainWidget::displayMessage(const QString& message)
{
    emit sendMessage_s(message);
}

void mainWidget::displayWealth(double inp)
{
    emit wealth_s(inp);
}

void mainWidget::displayCash(double inp)
{
    emit cash_s(inp);
}

void mainWidget::displayPrisonCards(int inp)
{
    emit prisonCards_s(inp);
}

void mainWidget::doHouse(int id, bool inp)
{
    emit house_s(id, inp);
}

void mainWidget::deleteAllHouses(int id)
{
    emit deleteHouses_s(id);
}

void mainWidget::doHotel(int id, bool inp)
{
    emit hotel_s(id, inp);
}

void mainWidget::setOwnershipFlag(int id, bool flag,int  playerNumber)
{
    emit setOwnership_s(id, flag, playerId2color(playerNumber));
}

void mainWidget::setMortgageFlag(int id, bool inp)
{
    emit setMortgage_s(id, inp);
}

boardWidget::playerColor mainWidget::playerId2color(int playerId)
{
    switch(playerId)
    {
    case 1:
        return boardWidget::playerColor::RED;
        break;
    case 2:
        return boardWidget::playerColor::GREEN;
        break;
    case 3:
        return boardWidget::playerColor::BLUE;
        break;
    case 4:
        return boardWidget::playerColor::YELLOW;
        break;
    default:
        return boardWidget::playerColor::NO_COLOR;
        break;
    }
}
