#ifndef RAILWAYPLACE_H
#define RAILWAYPLACE_H

#include "BoardPlace.h"
#include <memory>
#include <map>
#include "Player.h"

class RailwayPlace : public BoardPlace
{
public:
    RailwayPlace(const int& inp, const QString &name, const double &priceInp);
    static void initPayments(double one = 50.0, double two = 100.0, double three = 200.0, double four = 400.0);
private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);

    static const int MAX_RAILWAYS = 4;
    static std::map<int, double> payments;
    std::shared_ptr<Player> ownerPlayer;
    const double price;
};

#endif // RAILWAYPLACE_H
