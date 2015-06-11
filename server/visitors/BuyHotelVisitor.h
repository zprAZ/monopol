#ifndef BUYHOTELVISITOR_H
#define BUYHOTELVISITOR_H

#include "PlayerVisitor.h"
#include <memory>

class BuyHotelVisitor : public PlayerVisitor
{
public:
    BuyHotelVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createBuyHotelVisitor();
    void init(const int& placeId, const QString& question);
    void setPlaceId(const int& id);
    void setQuestion(const QString& question);
private:
    int placeId;
    QString question;
};

#endif // BUYHOTELVISITOR_H
