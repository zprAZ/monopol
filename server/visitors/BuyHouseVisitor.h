#ifndef BUYHOUSEVISITOR_H
#define BUYHOUSEVISITOR_H

#include "PlayerVisitor.h"
#include <memory>

class BuyHouseVisitor : public PlayerVisitor
{
public:
    BuyHouseVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createBuyHouseVisitor();
    void init(const int& placeId, const QString& question);
    void setPlaceId(const int& id);
    void setQuestion(const QString& question);
private:
    int placeId;
    QString question;
};

#endif // BUYHOUSEVISITOR_H
