#ifndef PAYVISITOR_H
#define PAYVISITOR_H

#include "PlayerVisitor.h"
#include <memory>
#include <QString>

class Player;
class Pawn;

class PayVisitor : public PlayerVisitor
{
public:
    PayVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    static std::unique_ptr<Visitor>  createPayVisitor();
    void init(double amount, const QString& message);
    void setMessage(const QString& message);
    void setAmount(const double& inp);
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
private:
    QString message;
    double amount;
};

#endif // PAYVISITOR_H
