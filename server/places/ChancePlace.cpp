#include "ChancePlace.h"
#include "BoardPlace.h"

ChanceQueue ChancePlace::chancesGenerator;


ChancePlace::ChancePlace(const int& inp, const QString &name):BoardPlace(inp, name)
{
}

std::unique_ptr<Visitor> ChancePlace::createVisitor(int playerId)
{
    return chancesGenerator.getVisitor();
}

int ChancePlace::implementGetNumberOfBuildHouses() const
{
    return 0;
}
int ChancePlace::implementGetNumberOfBuildHotels() const
{
    return 0;
}

void ChancePlace::implementBuildHouse()
{
    //do nothing
}

void ChancePlace::implementBuildHotel()
{
    // do nothing
}

void ChancePlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    // do nothing
}
