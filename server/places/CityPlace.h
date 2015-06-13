#ifndef CITYPLACE_H
#define CITYPLACE_H

#include "BoardPlace.h"
#include <memory>
#include <map>
#include "Player.h"

class CityPlace : public BoardPlace
{
public:
    CityPlace(const int& inp, const QString& name, const double& priceInp);
    void init(double noHousesPayment, double oneHousePayment, double twoHousesPayment, double threeHousesPayment,
              double fourHousesPayment, double withHotelPayment, double houseCost, double hotelCost);
private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);


    static const int MAX_HOUSES = 4;
    int currentNumberOfHouses;
    bool hotelFlag;
    std::map<int, double> housePayments;
    double hotelPayment;
    double houseCost;
    double hotelCost;
    std::shared_ptr<Player> ownerPlayer;
    const double price;
};

#endif // CITYPLACE_H
