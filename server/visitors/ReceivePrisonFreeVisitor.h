#ifndef RECEIVEPRISONFREEVISITOR_H
#define RECEIVEPRISONFREEVISITOR_H

#include <memory>
#include "PlayerVisitor.h"

class Player;
class Pawn;

class ReceivePrisonFreeVisitor : public PlayerVisitor
{
public:
    ReceivePrisonFreeVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createReceivePrisonFreeVisitor();
};

#endif // RECEIVEPRISONFREEVISITOR_H
