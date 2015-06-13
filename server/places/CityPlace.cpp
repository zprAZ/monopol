#include "CityPlace.h"
#include "visitors/BuyHotelVisitor.h"
#include "visitors/BuyHouseVisitor.h"
#include "visitors/BuyPlaceVisitor.h"
#include "visitors/DoNothingVisitor.h"
#include "visitors/PayVisitor.h"
#include "visitors/CollectVisitor.h""

CityPlace::CityPlace(const int &inp, const QString &name, const double &priceInp):BoardPlace(inp, name),
    ownerPlayer(nullptr), price(priceInp), currentNumberOfHouses(0), hotelFlag(false)
{
}

std::unique_ptr<Visitor> CityPlace::createVisitor(int playerId)
{
    if(this->ownerPlayer.get() == nullptr)
    {
        BuyPlaceVisitor* visitor = new BuyPlaceVisitor;
        visitor ->init(QString("Would you like to buy %1").arg(this->name_m),
                       this->shared_from_this(), this->price);
        return std::unique_ptr<Visitor>(visitor);
    }
    if(ownerPlayer->getPlayerId() == playerId)
    {
        if(this->currentNumberOfHouses < MAX_HOUSES)
        {
            BuyHouseVisitor* houseVisitor = new BuyHouseVisitor;
            houseVisitor -> init(this->id_m, QString("Would you like to buy next house in %1")
                                 .arg(this->name_m),
                                 this->houseCost);
        }else
        {
            if(!this->hotelFlag)
            {
                BuyHotelVisitor* hotelVisitor = new BuyHotelVisitor;
                hotelVisitor ->init(this->id_m, QString("Would you like to buy a hotel in %1").arg(this->name_m)
                                            ,this->hotelCost );
                return std::unique_ptr<Visitor>(hotelVisitor);
            }else
            {
              return std::unique_ptr<Visitor>(new DoNothingVisitor);
            }
        }
    }else // another player
    {
        double visitPayment = 0;
        if(this->hotelFlag)
        {
            visitPayment = this->hotelPayment;
        }else
        {
            try
            {
            visitPayment = this->housePayments.at(this->currentNumberOfHouses);
            }catch(std::out_of_range& e)
            {
                visitPayment = 0;
            }
        }
        // before we return visitor we have to collect money for owner;
        CollectVisitor* receiveVisitor = new CollectVisitor;
        receiveVisitor ->init(visitPayment, QString("Plyer %1 stayed on your property named %2 "
                                               " Ypou receive %3$ money").arg(playerId)
                              .arg(this->name_m).arg(visitPayment));
        ownerPlayer->accept(std::unique_ptr<Visitor>(receiveVisitor));
        // now we can demand this money from visitor player
        PayVisitor* payVisitor = new PayVisitor;
        payVisitor ->init(visitPayment, QString("You visit player %1 city named %2."
                   " You have to pay %3$ for this visit").arg(this->ownerPlayer->getPlayerId())
                          .arg(this->name_m).arg(visitPayment));
        return std::unique_ptr<Visitor>(payVisitor);
    }
}

int CityPlace::implementGetNumberOfBuildHouses() const
{
    return this->currentNumberOfHouses;
}

int CityPlace::implementGetNumberOfBuildHotels() const
{
    if(this->hotelFlag)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void CityPlace::implementBuildHouse()
{
    if(this->currentNumberOfHouses < MAX_HOUSES)
    {
    ++(this->currentNumberOfHouses);
    }
}

void CityPlace::implementBuildHotel()
{
    if((!this->hotelFlag) && (currentNumberOfHouses == MAX_HOUSES) )
    {
     this->currentNumberOfHouses = 0;
     this->hotelFlag = true;
    }
}

void CityPlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    this->ownerPlayer = inp;
}

void CityPlace::init(double noHousesPayment, double oneHousePayment, double twoHousesPayment, double threeHousesPayment,
          double fourHousesPayment, double withHotelPayment, double houseCost, double hotelCost)
{
    this->houseCost = houseCost;
    this->hotelCost = hotelCost;
    std::pair<std::map<int, double>::iterator, bool> result0 =
            housePayments.insert(std::pair<int, double>(0,noHousesPayment));
    std::pair<std::map<int, double>::iterator, bool> result1 =
            housePayments.insert(std::pair<int, double>(1,oneHousePayment));
    std::pair<std::map<int, double>::iterator, bool> result2 =
            housePayments.insert(std::pair<int, double>(2,twoHousesPayment));
    std::pair<std::map<int, double>::iterator, bool> result3 =
            housePayments.insert(std::pair<int, double>(3,threeHousesPayment));
    std::pair<std::map<int, double>::iterator, bool> result4 =
            housePayments.insert(std::pair<int, double>(4,fourHousesPayment));
    Q_ASSERT(result0.second && result1.second && result2.second && result3.second && result4.second);
    Q_ASSERT(housePayments.size() == MAX_HOUSES + 1);
}
