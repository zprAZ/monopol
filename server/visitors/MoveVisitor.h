#ifndef MOVEVISITOR_H
#define MOVEVISITOR_H

#include "PawnVisitor.h"
#include <memory>
#include <QString>

class MoveVisitor : public PawnVisitor
{
public:
    MoveVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    static std::unique_ptr<Visitor>  createGoVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    void init(const int& movement, const QString& playerMessage);
private:
    int movement;
    QString playerMessage;
};

#endif // MOVEVISITOR_H
