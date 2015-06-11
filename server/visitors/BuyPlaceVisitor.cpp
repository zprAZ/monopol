#include "BuyPlaceVisitor.h"
#include "Player.h"

BuyPlaceVisitor::BuyPlaceVisitor(): placePtr(nullptr), question(QString(""))
{
}

void BuyPlaceVisitor::visit(Pawn& inp)
{
    //do nothing
}

void BuyPlaceVisitor::visit(Player& inp)
{
    inp.askToBuyPlace(this->question, this->placePtr);
}

std::unique_ptr<Visitor>  BuyPlaceVisitor::createBuyPlaceVisitor()
{
    return std::unique_ptr<Visitor>(new BuyPlaceVisitor);
}

void BuyPlaceVisitor::init(const QString& question, std::shared_ptr<BoardPlace> ptr)
{
    this->question = question;
    this->placePtr = ptr;
}

void BuyPlaceVisitor::setQuestion(const QString& question)
{
    this->question = question;
}

void BuyPlaceVisitor::setPlacePtr(std::shared_ptr<BoardPlace> ptr)
{
    this->placePtr = ptr;
}
