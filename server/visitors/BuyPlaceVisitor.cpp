#include "BuyPlaceVisitor.h"
#include "Player.h"

BuyPlaceVisitor::BuyPlaceVisitor(): placePtr(nullptr), question(QString("")), payment(0)
{
}

void BuyPlaceVisitor::visit(Pawn& inp)
{
    //do nothing
}

void BuyPlaceVisitor::visit(Player& inp)
{
    inp.askToBuyPlace(this->question, this->placePtr, this->payment);
}

std::unique_ptr<Visitor>  BuyPlaceVisitor::createBuyPlaceVisitor()
{
    return std::unique_ptr<Visitor>(new BuyPlaceVisitor);
}

void BuyPlaceVisitor::init(const QString& question, std::shared_ptr<BoardPlace> ptr, const double &payment)
{
    this->question = question;
    this->placePtr = ptr;
    this->payment = payment;
}

void BuyPlaceVisitor::setQuestion(const QString& question)
{
    this->question = question;
}

void BuyPlaceVisitor::setPlacePtr(std::shared_ptr<BoardPlace> ptr)
{
    this->placePtr = ptr;
}

std::unique_ptr<Visitor> BuyPlaceVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new BuyPlaceVisitor(*this));
}
