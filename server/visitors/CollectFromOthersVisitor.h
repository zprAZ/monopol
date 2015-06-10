#ifndef COLLECTFROMOTHERSVISITOR_H
#define COLLECTFROMOTHERSVISITOR_H

#include <memory>
#include <QString>
#include "PlayerVisitor.h"

class Player;
class Pawn;

class CollectFromOthersVisitor : public PlayerVisitor
{
public:
    CollectFromOthersVisitor();
    static std::unique_ptr<Visitor>  createCollectFromOthersVisitor();
    void init(double amount, const QString& messageCollector, const QString& messageAll);
    void setMessage2Others(const QString& message);
    void setMessage2Collector(const QString& message);
    void setAmount(const double& inp);
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
private:
    QString messageToOthers;
    QString messageToCollector;
    double amount;
};

#endif // COLLECTFROMOTHERSVISITOR_H
