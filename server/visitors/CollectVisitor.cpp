#include "CollectVisitor.h"
#include "Pawn.h"
#include "Player.h"
#include <memory>

CollectVisitor::CollectVisitor() : message(QString("")), amount(0)
{
}

std::unique_ptr<Visitor>  CollectVisitor::createCollectVisitor()
{
    return std::unique_ptr<Visitor>(new CollectVisitor);
}

void CollectVisitor::init(double amount, const QString& message)
{
    this->amount = amount;
    this->message = message;
}

void CollectVisitor::setMessage(const QString& message)
{
    this->message = message;
}

void CollectVisitor::setAmount(const double& inp)
{
    this->amount = inp;
}

void CollectVisitor::visit(Pawn& inp)
{
    //do nothing
}

void CollectVisitor::visit(Player& inp)
{
    inp.sendMessageToThisPlayer(this->message);
    inp.collectMoney(this->amount);
}
