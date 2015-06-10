#include "ReceivePrisonFreeVisitor.h"
#include "Player.h"
#include "Pawn.h"

ReceivePrisonFreeVisitor::ReceivePrisonFreeVisitor()
{
}

void ReceivePrisonFreeVisitor::visit(Pawn& inp)
{
    // do nothing
}

void ReceivePrisonFreeVisitor::visit(Player& inp)
{
    inp.addPrisonFreeCard();
}

std::unique_ptr<Visitor>  ReceivePrisonFreeVisitor::createReceivePrisonFreeVisitor()
{
    return std::unique_ptr<Visitor>(new ReceivePrisonFreeVisitor);
}
