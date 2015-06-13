#include "GoToPrisonVisitor.h"
#include "Pawn.h"
#include "Player.h"

GoToPrisonVisitor::GoToPrisonVisitor(): roundNumber(3)
{
}

std::unique_ptr<Visitor>  GoToPrisonVisitor::createGoToPrisonVisitor()
{
    return std::unique_ptr<Visitor> (new GoToPrisonVisitor);
}

void GoToPrisonVisitor::visit(Pawn& pawn)
{
    pawn.goToPrison(this->roundNumber);
}

void GoToPrisonVisitor::visit(Player& player)
{
    // do nothing
}

void GoToPrisonVisitor::init(const int& roundNumber)
{
    this->roundNumber = roundNumber;
}

std::unique_ptr<Visitor> GoToPrisonVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new GoToPrisonVisitor(*this));
}
