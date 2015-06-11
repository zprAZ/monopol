#ifndef COUNTERPLACE_H
#define COUNTERPLACE_H

#include "BoardPlace.h"
#include <memory>

class CounterPlace : public BoardPlace
{
public:
    CounterPlace(const int& inp);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) const;
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
};

#endif // COUNTERPLACE_H
