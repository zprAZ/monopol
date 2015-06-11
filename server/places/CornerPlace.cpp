#include "CornerPlace.h"

CornerPlace::CornerPlace(const int &inp):BoardPlace(inp)
{
}


std::unique_ptr<Visitor> CornerPlace::createVisitor(int playerId) const
{

}

int CornerPlace::implementGetNumberOfBuildHouses() const
{
    return 0;
}

int CornerPlace::implementGetNumberOfBuildHotels() const
{
    return 0;
}

void CornerPlace::implementBuildHouse()
{
    //do nothing
}

void CornerPlace::implementBuildHotel()
{
    // do nothing
}
