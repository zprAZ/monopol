#ifndef VISITOR_H
#define VISITOR_H

#include <memory>

class Player;
class Pawn;

class Visitor
{
public:
    enum class VisitorType: int{VISITOR_GO = 1,
                               VISITOR_COLLECT = 2,
                               VISITOR_PAY = 3,
                               VISITOR_DO_NOTHING = 4,
                               VISITOR_TOWN_MODERNIZATION = 5,
                               VISITOR_RECEIVE_PRISON_FREE = 6,
                               VISITOR_COLLECT_FROM_OTHERS = 7,
                               VISITOR_BUY_PLACE = 8,
                               VISITOR_BUY_HOUSE = 9,
                               VISITOR_BUY_HOTEL = 10
                               };
    Visitor();
    virtual void visit(Player& player) = 0;
    virtual void visit(Pawn& inp) = 0;
    virtual std::unique_ptr<Visitor> clone() const = 0;
};

#endif // VISITOR_H
