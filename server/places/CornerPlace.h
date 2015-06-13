#ifndef CORNERPLACE_H
#define CORNERPLACE_H

#include "BoardPlace.h"
#include <memory>

class CornerPlace : public BoardPlace
{
public:
    CornerPlace(const int& inp, const QString &name);


private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);
};

#endif // CORNERPLACE_H
