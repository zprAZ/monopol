#ifndef DONOTHINGVISITOR_H
#define DONOTHINGVISITOR_H

#include <memory>
#include "Visitor.h"

class DoNothingVisitor : public Visitor
{
public:
    DoNothingVisitor();

    virtual void visit(Player& player);
    virtual void visit(Pawn& inp);
    std::unique_ptr<Visitor> createDoNothingVisitor();
};

#endif // DONOTHINGVISITOR_H
