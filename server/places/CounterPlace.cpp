#include "CounterPlace.h"
#include "visitors/CounterPaymentVisitor.h"
#include "visitors/DoNothingVisitor.h"
#include "visitors/BuyPlaceVisitor.h"
#include "visitors/CollectVisitor.h"

CounterPlace::CounterPlace(const int &inp, const QString& name, const double& amountPerMoveInp,
                           const double &priceInp):
    BoardPlace(inp, name), amountPerMove(amountPerMoveInp), ownerPlayer(nullptr), price(priceInp)
{
}


std::unique_ptr<Visitor> CounterPlace::createVisitor(int playerId)
{
    if(ownerPlayer.get() == nullptr)
    {
        BuyPlaceVisitor* visitor = new BuyPlaceVisitor;
        visitor ->init(QString("Would you like to buy %1").arg(this->name_m),
                       this->shared_from_this(),this->price);
        return std::unique_ptr<Visitor>(visitor);
    }
    if(ownerPlayer->getPlayerId() == playerId)
    {
           return std::unique_ptr<Visitor>(new DoNothingVisitor);
    }else
    {
    CounterPaymentVisitor* visitor = new CounterPaymentVisitor;
    visitor -> init(this->amountPerMove, QString("You stay on player % property named %2"
                        "You have to pay him %3 for every move which gives:")
                    .arg(ownerPlayer->getPlayerId()).arg(this->name_m).arg(this->amountPerMove),
                    this->ownerPlayer);
    return std::unique_ptr<Visitor>(visitor);
        // now owner is collecting money but it's impossible here :-(
    }
}

int CounterPlace::implementGetNumberOfBuildHouses() const
{
    return 0;
}

int CounterPlace::implementGetNumberOfBuildHotels() const
{
    return 0;
}

void CounterPlace::implementBuildHouse()
{
    //do nothing
}

void CounterPlace::implementBuildHotel()
{
    // do nothing
}

void CounterPlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    this->ownerPlayer = inp;
}
