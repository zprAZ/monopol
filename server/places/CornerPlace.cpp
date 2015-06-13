#include "CornerPlace.h"
#include "visitors/DoNothingVisitor.h"

CornerPlace::CornerPlace(const int &inp, const QString& name):BoardPlace(inp, name)
{
}


std::unique_ptr<Visitor> CornerPlace::createVisitor(int playerId)
{
    return std::unique_ptr<Visitor>(new DoNothingVisitor);
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

void CornerPlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    // do nothing
}
