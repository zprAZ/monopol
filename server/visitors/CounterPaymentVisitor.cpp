#include "CounterPaymentVisitor.h"
#include "Player.h"
#include "Pawn.h"
#include "visitors/CollectVisitor.h"

CounterPaymentVisitor::CounterPaymentVisitor():amountPerMove(0), message(QString(""))
{
}

std::unique_ptr<Visitor>  CounterPaymentVisitor::createCounterPaymentVisitor()
{
    return std::unique_ptr<Visitor>(new CounterPaymentVisitor);
}

void CounterPaymentVisitor::visit(Pawn& inp)
{
    int movements = inp.getLastMovement();
    CollectVisitor* visitor = new CollectVisitor;
    double payment = this->amountPerMove * movements;
    visitor->init(payment, QString("Other player is now staying on one of your"
                   "counter places like electricity or waterworks. Receive %").arg(payment));
    (this->ownerPlayer)->accept(std::unique_ptr<Visitor>(visitor));
    inp.payForMoves(this->amountPerMove, this->message);
}

void CounterPaymentVisitor::visit(Player& inp)
{
    //do nothing
}

void CounterPaymentVisitor::init(const double& amountPerMove, const QString& message, std::shared_ptr<Player> ownerPlayer)
{
    this->amountPerMove = amountPerMove;
    this->message = message;
    this->ownerPlayer = ownerPlayer;
}

std::unique_ptr<Visitor> CounterPaymentVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new CounterPaymentVisitor(*this));
}
