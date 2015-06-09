#ifndef VISITOR_H
#define VISITOR_H

class Player;
class Pawn;

class Visitor
{
public:
    enum class VisitorType: int{VISITOR_GO = 1,
                               VISITOR_COLLECT = 2};
    Visitor();
    virtual void visit(Player& player) = 0;
    virtual void visit(Pawn& inp) = 0;
};

#endif // VISITOR_H
