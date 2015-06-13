#ifndef COUNTERPLACE_H
#define COUNTERPLACE_H

#include "BoardPlace.h"
#include <memory>
#include "Player.h"

class CounterPlace : public BoardPlace
{
public:
    CounterPlace(const int& inp, const QString& name, const double& amountPerMoveInp,
                 const double& priceInp);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);
    std::shared_ptr<Player> ownerPlayer;
    const double amountPerMove;
    const double price;
};

#endif // COUNTERPLACE_H
