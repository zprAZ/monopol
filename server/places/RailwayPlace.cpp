#include "RailwayPlace.h"
#include "visitors/BuyPlaceVisitor.h"
#include "visitors/PayVisitor.h"
#include "visitors/CollectVisitor.h"
#include "visitors/DoNothingVisitor.h"

std::map<int, double> RailwayPlace::payments;

RailwayPlace::RailwayPlace(const int &inp, const QString& name, const double& priceInp):BoardPlace(inp, name),
    ownerPlayer(nullptr), price(priceInp)
{
}

std::unique_ptr<Visitor> RailwayPlace::createVisitor(int playerId)
{
    if(ownerPlayer.get() == nullptr)
    {
        BuyPlaceVisitor* visitor = new BuyPlaceVisitor;
        visitor ->init(QString("Would you like to buy %1").arg(this->name_m),
                       this->shared_from_this(), this->price);
        return std::unique_ptr<Visitor>(visitor);
    }
    if(ownerPlayer->getPlayerId() == playerId)
    {
           return std::unique_ptr<Visitor>(new DoNothingVisitor);
    }else
    {
        PayVisitor* visitor = new PayVisitor;
        int railwayNumber = ownerPlayer->giveNumberOfRailwaysOwned();
        double payment = 0;
        if((!railwayNumber < 0) && (!railwayNumber > MAX_RAILWAYS))
        {
            try{
                payment = payments.at(railwayNumber);
            }catch(std::out_of_range& exception)
            {

            }
        }
        visitor -> init(payment, QString("You stay on player %1 property named %2,"
                                         "You have to pay him %3 money").arg(ownerPlayer->getPlayerId())
                        .arg(this->name_m).arg(payment));
        // before we return visitor we have to collect money for owner;
        CollectVisitor* receiveVisitor = new CollectVisitor;
        receiveVisitor ->init(payment, QString("Plyer %1 stayed on your property named %2 "
                                               " Ypou receive %3$ money").arg(playerId)
                              .arg(this->name_m).arg(payment));
        ownerPlayer->accept(std::unique_ptr<Visitor>(receiveVisitor));
        // now we are ready to return
        return std::unique_ptr<Visitor>(visitor);
    }
}

int RailwayPlace::implementGetNumberOfBuildHouses() const
{
    return 0;
}

int RailwayPlace::implementGetNumberOfBuildHotels() const
{
    return 0;
}

void RailwayPlace::implementBuildHouse()
{
    // do nothing maybe display error
}
void RailwayPlace::implementBuildHotel()
{
    // do nothing maybe display error
}

void RailwayPlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    this->ownerPlayer = inp;
}

void RailwayPlace::initPayments(double one, double two, double three, double four)
{
   std::pair<std::map<int, double>::iterator, bool> result1 =
           payments.insert(std::pair<int, double>(1,one));
   std::pair<std::map<int, double>::iterator, bool> result2 =
           payments.insert(std::pair<int, double>(2,two));
   std::pair<std::map<int, double>::iterator, bool> result3 =
           payments.insert(std::pair<int, double>(3,three));
   std::pair<std::map<int, double>::iterator, bool> result4 =
           payments.insert(std::pair<int, double>(4,four));
   Q_ASSERT(result1.second && result2.second && result3.second && result4.second);
   Q_ASSERT(payments.size() == MAX_RAILWAYS);
}
