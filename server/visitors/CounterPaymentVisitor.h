#ifndef COUNTERPAYMENTVISITOR_H
#define COUNTERPAYMENTVISITOR_H

#include "PawnVisitor.h"
#include <memory>
#include <QString>
#include "Player.h"

class CounterPaymentVisitor : public PawnVisitor
{
public:
    CounterPaymentVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    static std::unique_ptr<Visitor>  createCounterPaymentVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    void init(const double& amountPerMove, const QString& message, std::shared_ptr<Player> ownerPlayer);
private:
    double amountPerMove;
    QString message;
    std::shared_ptr<Player> ownerPlayer;
};

#endif // COUNTERPAYMENTVISITOR_H
