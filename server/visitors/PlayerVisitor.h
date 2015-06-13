#ifndef PLAYERVISITOR_H
#define PLAYERVISITOR_H

#include "Visitor.h"

class Pawn;
class Player;

class PlayerVisitor : public Visitor
{
public:
    PlayerVisitor();
    virtual std::unique_ptr<Visitor> clone() const = 0;
    virtual void visit(Pawn& inp) = 0;
    virtual void visit(Player& inp) = 0;
};

#endif // PLAYERVISITOR_H
