#include "DoNothingVisitor.h"

DoNothingVisitor::DoNothingVisitor()
{
}


void DoNothingVisitor::visit(Player& player)
{
    // do nothing
}

void DoNothingVisitor::visit(Pawn& inp)
{
    //do nothing
}

std::unique_ptr<Visitor> DoNothingVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new DoNothingVisitor(*this));
}
