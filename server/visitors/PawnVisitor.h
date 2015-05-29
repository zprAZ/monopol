#ifndef PAWNVISITOR_H
#define PAWNVISITOR_H

#include "Visitor.h"

class Player;
class Pawn;

class PawnVisitor : public Visitor
{
public:
    PawnVisitor();
    virtual void visit(Pawn& inp) = 0;
    virtual void visit(Player& inp) = 0;
};

#endif // PAWNVISITOR_H
