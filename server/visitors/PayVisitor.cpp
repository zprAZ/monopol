#include "PayVisitor.h"
#include "Player.h"
#include "Pawn.h"

PayVisitor::PayVisitor(): message(QString("")), amount(0)
{
}

std::unique_ptr<Visitor>  PayVisitor::createPayVisitor()
{
    return std::unique_ptr<Visitor>(new PayVisitor);
}

void PayVisitor::init(double amount, const QString& message)
{
    this->amount = amount;
    this->message = message;
}

void PayVisitor::setMessage(const QString& message)
{
    this->message = message;
}

void PayVisitor::setAmount(const double& inp)
{
    this->amount = inp;
}

void PayVisitor::visit(Pawn& inp)
{
    // do nothing
}

void PayVisitor::visit(Player& inp)
{
    inp.sendMessageToThisPlayer(this->message);
    inp.payMoney(this->amount);
}

std::unique_ptr<Visitor> PayVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new PayVisitor(*this));
}
