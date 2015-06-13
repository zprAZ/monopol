#include "BuyHouseVisitor.h"
#include "Player.h"

BuyHouseVisitor::BuyHouseVisitor(): placeId(0), payment(0)
{
}

void BuyHouseVisitor::visit(Pawn& inp)
{
    // do nothing
}

void BuyHouseVisitor::visit(Player& inp)
{
    inp.askToBuyHouse(this->placeId, this->question, this->payment);
}

std::unique_ptr<Visitor>  BuyHouseVisitor::createBuyHouseVisitor()
{
    return std::unique_ptr<Visitor>(new BuyHouseVisitor);
}

void BuyHouseVisitor::init(const int& placeId, const QString &question, const double &payment)
{
    this->placeId = placeId;
    this->question = question;
    this->payment = payment;
}
void BuyHouseVisitor::setPlaceId(const int& id)
{
    this->placeId = id;
}

void BuyHouseVisitor::setQuestion(const QString& question)
{
    this->question = question;
}
std::unique_ptr<Visitor> BuyHouseVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new BuyHouseVisitor(*this));
}
