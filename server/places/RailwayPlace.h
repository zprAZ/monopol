#ifndef RAILWAYPLACE_H
#define RAILWAYPLACE_H

#include "BoardPlace.h"
#include <memory>

class RailwayPlace : public BoardPlace
{
public:
    RailwayPlace(const int& inp);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) const;
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
};

#endif // RAILWAYPLACE_H
