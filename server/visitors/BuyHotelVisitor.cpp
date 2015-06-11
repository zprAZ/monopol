#include "BuyHotelVisitor.h"
#include "Player.h"

BuyHotelVisitor::BuyHotelVisitor(): placeId(0), question(QString(""))
{
}

void BuyHotelVisitor::visit(Pawn& inp)
{
    // do nothing
}

void BuyHotelVisitor::visit(Player& inp)
{
    inp.askToBuyHotel(this->placeId, this->question);
}

std::unique_ptr<Visitor>  BuyHotelVisitor::createBuyHotelVisitor()
{
    return std::shared_ptr<Visitor>(new BuyHotelVisitor);
}

void BuyHotelVisitor::init(const int& placeId, const QString& question)
{
    this->placeId = placeId;
    this->question = question;
}

void BuyHotelVisitor::setPlaceId(const int& id)
{
        this->placeId = id;
}

void BuyHotelVisitor::setQuestion(const QString& question)
{
    this->question = question;
}
