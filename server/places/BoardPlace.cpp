#include "BoardPlace.h"

BoardPlace::BoardPlace(const int& inp, const QString &name): id_m(inp), name_m(name)
{
}

std::unique_ptr<Visitor> BoardPlace::getVisitor(int playerId)
{
    return this->createVisitor(playerId);
}

int BoardPlace::getNumberOfBuildHouses() const
{
    return this->implementGetNumberOfBuildHouses();
}
int BoardPlace::getNumberOfBuildHotels() const
{
    return this->implementGetNumberOfBuildHotels();
}

void BoardPlace::buildHouse()
{
    this->implementBuildHouse();
}

void BoardPlace::buildHotel()
{
    this ->implementBuildHotel();
}

QString BoardPlace::getName() const
{
    return name_m;
}

void BoardPlace::setOwnership(std::shared_ptr<Player> inp)
{
    this->implementSetOwnership(inp);
}

