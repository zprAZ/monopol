#ifndef CITYPLACE_H
#define CITYPLACE_H

#include "BoardPlace.h"
#include <memory>

class CityPlace : public BoardPlace
{
public:
    CityPlace(const int& inp, const QString& name);

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) const;
    virtual int implementGetNumberOfBuildHouses() const;
    virtual int implementGetNumberOfBuildHotels() const;
    virtual void implementBuildHouse();
    virtual void implementBuildHotel();
};

#endif // CITYPLACE_H
