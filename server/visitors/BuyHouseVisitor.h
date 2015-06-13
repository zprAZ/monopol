#ifndef BUYHOUSEVISITOR_H
#define BUYHOUSEVISITOR_H

#include "PlayerVisitor.h"
#include <memory>
#include <QString>

class BuyHouseVisitor : public PlayerVisitor
{
public:
    BuyHouseVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createBuyHouseVisitor();
    void init(const int& placeId, const QString& question, const double& payment);
    void setPlaceId(const int& id);
    void setQuestion(const QString& question);
private:
    int placeId;
    QString question;
    double payment;
};

#endif // BUYHOUSEVISITOR_H
