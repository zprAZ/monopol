#ifndef TAXPLACE_H
#define TAXPLACE_H

#include "BoardPlace.h"
#include <memory>

class TaxPlace : public BoardPlace
{
public:
    TaxPlace(const int& id);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) const;
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
};

#endif // TAXPLACE_H
