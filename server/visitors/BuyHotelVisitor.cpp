#include "BuyHotelVisitor.h"
#include "Player.h"

BuyHotelVisitor::BuyHotelVisitor(): placeId(0), question(QString("")), payment(0)
{
}

void BuyHotelVisitor::visit(Pawn& inp)
{
    // do nothing
}

void BuyHotelVisitor::visit(Player& inp)
{
    inp.askToBuyHotel(this->placeId, this->question, this->payment);
}

std::unique_ptr<Visitor>  BuyHotelVisitor::createBuyHotelVisitor()
{
    return std::unique_ptr<Visitor>(new BuyHotelVisitor);
}

void BuyHotelVisitor::init(const int& placeId, const QString& question, const double& payment)
{
    this->placeId = placeId;
    this->question = question;
    this->payment = payment;
}

void BuyHotelVisitor::setPlaceId(const int& id)
{
        this->placeId = id;
}

void BuyHotelVisitor::setQuestion(const QString& question)
{
    this->question = question;
}

std::unique_ptr<Visitor> BuyHotelVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new BuyHotelVisitor(*this));
}
