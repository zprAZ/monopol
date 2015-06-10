#include "CollectFromOthersVisitor.h"
#include "Player.h"
#include "Pawn.h"

CollectFromOthersVisitor::CollectFromOthersVisitor():amount(0),messageToOthers(QString("")),
    messageToCollector(QString(""))
{
}

static std::unique_ptr<Visitor>  createCollectFromOthersVisitor()
{
    return std::unique_ptr<Visitor>(new CollectFromOthersVisitor);
}

void CollectFromOthersVisitor::init(double amount, const QString& messageCollector,
                                    const QString& messageAll)
{
    this->amount = amount;
    this->messageToCollector = messageCollector;
    this->messageToOthers = messageAll;
}

void CollectFromOthersVisitor::setMessage2Others(const QString& message)
{
    this->messageToOthers = message;
}

void CollectFromOthersVisitor::setMessage2Collector(const QString& message)
{
    this->messageToCollector = message;
}

void CollectFromOthersVisitor::setAmount(const double& inp)
{
    this->amount = inp;
}

void CollectFromOthersVisitor::visit(Pawn& inp)
{
    // do nothing
}

void CollectFromOthersVisitor::visit(Player& inp)
{
    inp.sendMessageToThisPlayer(this->messageToCollector);
    inp.takeMoneyFromOthers(this->amount, this->messageToOthers);
}
