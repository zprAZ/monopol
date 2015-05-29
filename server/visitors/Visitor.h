#ifndef VISITOR_H
#define VISITOR_H

class Player;
class Pawn;

class Visitor
{
public:
    Visitor();
    virtual void visit(Player& player) = 0;
    virtual void visit(Pawn& inp) = 0;
};

#endif // VISITOR_H
