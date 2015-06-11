#ifndef CORNERPLACE_H
#define CORNERPLACE_H

#include "BoardPlace.h"
#include <memory>

class CornerPlace : public BoardPlace
{
public:
    CornerPlace(const int& inp);


private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) const;
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
};

#endif // CORNERPLACE_H
