#ifndef CHANCEPLACE_H
#define CHANCEPLACE_H

#include <memory>
#include "BoardPlace.h"
#include "ChanceQueue.h"

class ChancePlace : public BoardPlace
{
public:
    ChancePlace(const int& inp, const QString& name);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);
    static ChanceQueue chancesGenerator;
};

#endif // CHANCEPLACE_H
