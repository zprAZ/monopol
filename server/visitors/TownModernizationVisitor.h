#ifndef TOWNMODERNIZATIONVISITOR_H
#define TOWNMODERNIZATIONVISITOR_H

#include <QString>
#include "PlayerVisitor.h"
#include <memory>


class TownModernizationVisitor : public PlayerVisitor
{
public:
    TownModernizationVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    std::unique_ptr<Visitor> createTownModernizationVisitor();
    void init(const double& houseRepairCost, const double& hotelRepairCost,
              const QString& playerMessage);
    void setPlayerMessage(const QString& message);
    void setHotelCost(const double& inp);
    void setHouseCost(const double& inp);
    virtual void visit(Player& player);
    virtual void visit(Pawn& inp);
private:
    double houseRepairCost;
    double hotelRepairCost;
    QString playerMessage;
};

#endif // TOWNMODERNIZATIONVISITOR_H
