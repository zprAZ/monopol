#include "BoardPlace.h"

BoardPlace::BoardPlace(const int& inp, const QString &name): id_m(inp), name_m(name)
{
}

std::unique_ptr<Visitor> BoardPlace::getVisitor(int playerId) const
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

void BoardPlace::BuildHouse()
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

