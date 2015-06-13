#ifndef BUYHOTELVISITOR_H
#define BUYHOTELVISITOR_H

#include "PlayerVisitor.h"
#include <memory>
#include <QString>

class BuyHotelVisitor : public PlayerVisitor
{
public:
    BuyHotelVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createBuyHotelVisitor();
    void init(const int& placeId, const QString& question, const double& payment);
    void setPlaceId(const int& id);
    void setQuestion(const QString& question);
private:
    int placeId;
    QString question;
    double payment;
};

#endif // BUYHOTELVISITOR_H
