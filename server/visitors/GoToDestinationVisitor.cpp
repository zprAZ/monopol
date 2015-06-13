#include "GoToDestinationVisitor.h"
#include "Pawn.h"
#include "Player.h"

GoToDestinationVisitor::GoToDestinationVisitor():startBonus(true), destination(0),message(""),
    forwardDirectionFlag(true)
{
}

std::unique_ptr<Visitor>  createGoToDestinationVisitor()
{
    return std::unique_ptr<Visitor>( new GoToDestinationVisitor);
}

void GoToDestinationVisitor::visit(Pawn& inp)
{
    inp.goToDestination(this->destination, this->startBonus, this->message, this->forwardDirectionFlag);
}
void GoToDestinationVisitor::visit(Player& inp)
{
    // do nothing
}

void GoToDestinationVisitor::setStartBonus(const bool& inp)
{
    this->startBonus = inp;
}
void GoToDestinationVisitor::setDestination(const int& inp)
{
    this->destination = inp;
}
void GoToDestinationVisitor::setDisplayMessage(const QString& message)
{
    this->message = message;
}

void GoToDestinationVisitor::setDirectionFlag(const bool& dirFlag)
{
    this->forwardDirectionFlag = dirFlag;
}

void GoToDestinationVisitor::init(const int& destination, const bool& startBonus, const QString &message,
                                  bool forwardDirectionFlag)
{
    this->destination = destination;
    this->message = message;
    this->startBonus = startBonus;
    this->forwardDirectionFlag = forwardDirectionFlag;
}

std::unique_ptr<Visitor> GoToDestinationVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new GoToDestinationVisitor(*this));
}
