#ifndef TAXPLACE_H
#define TAXPLACE_H

#include "BoardPlace.h"
#include <memory>

class TaxPlace : public BoardPlace
{
public:
    TaxPlace(const int& id, const QString &name);
    void init(const double& tax, const QString& message);
private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId);
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
    virtual void implementSetOwnership(std::shared_ptr<Player> inp);
    double taxValue;
    QString message;
};

#endif // TAXPLACE_H
