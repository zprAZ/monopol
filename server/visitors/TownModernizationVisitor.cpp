#include "TownModernizationVisitor.h"
#include "Player.h"

TownModernizationVisitor::TownModernizationVisitor(): houseRepairCost(0), hotelRepairCost(0),
    playerMessage(QString(""))
{
}

std::unique_ptr<Visitor> TownModernizationVisitor::createTownModernizationVisitor()
{
    return std::unique_ptr<Visitor>(new TownModernizationVisitor);
}

void TownModernizationVisitor::init(const double& houseRepairCost, const double& hotelRepairCost,
          const QString& playerMessage)
{
    this->houseRepairCost = houseRepairCost;
    this->hotelRepairCost = hotelRepairCost;
    this->playerMessage = playerMessage;
}

void TownModernizationVisitor::setPlayerMessage(const QString& message)
{
    this->playerMessage = message;
}

void TownModernizationVisitor::setHotelCost(const double& inp)
{
    this->hotelRepairCost = inp;
}

void TownModernizationVisitor::setHouseCost(const double& inp)
{
    this->houseRepairCost = inp;
}

void TownModernizationVisitor::visit(Player& player)
{
    int houses = player.getNumberOfHouses();
    int hotels = player.getNumberOfHotels();
    double payment = houses * this->houseRepairCost +
            hotels * this->hotelRepairCost;
    QString message = this->playerMessage + QString(" which gives %1").arg(payment);
    QString allMessage(QString("Player Nr %1 is obliged do town modernization").arg(player.getPlayerId()));
    player.sendMessageToAll(allMessage);
    player.sendMessageToThisPlayer(message);
    player.payMoney(payment);
}

void TownModernizationVisitor::visit(Pawn& inp)
{
    // do nothing
}
