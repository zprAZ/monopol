#include "CityPlace.h"

CityPlace::CityPlace(const int &inp, const QString &name):BoardPlace(inp, name)
{
}

std::unique_ptr<Visitor> CityPlace::createVisitor(int playerId) const
{

}

int CityPlace::implementGetNumberOfBuildHouses() const
{

}

int CityPlace::implementGetNumberOfBuildHotels() const
{

}

void CityPlace::implementBuildHouse()
{

}

void CityPlace::implementBuildHotel()
{

}
