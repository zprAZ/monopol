#ifndef COLLECTVISITOR_H
#define COLLECTVISITOR_H

#include "Player.h"
#include "Pawn.h"
#include "PlayerVisitor.h"

#include <QString>

class CollectVisitor : public PlayerVisitor
{
public:
    CollectVisitor();
    static std::unique_ptr<Visitor>  createCollectVisitor();
    void init(double amount, const QString& message);
    void setMessage(const QString& message);
    void setAmount(const double& inp);
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
private:
    QString message;
    double amount;
};

#endif // COLLECTVISITOR_H
