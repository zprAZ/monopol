#ifndef GOTOPRISONVISITOR_H
#define GOTOPRISONVISITOR_H

#include "PawnVisitor.h"
#include <memory>
#include <QString>

class GoToPrisonVisitor : public PawnVisitor
{
public:
    GoToPrisonVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    static std::unique_ptr<Visitor>  createGoToPrisonVisitor();
    virtual void visit(Pawn& pawn);
    virtual void visit(Player& player);
    void init(const int& roundNumber);

private:
    int roundNumber;
};

#endif // GOTOPRISONVISITOR_H
