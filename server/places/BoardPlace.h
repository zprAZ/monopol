#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include "visitors/Visitor.h"
#include <memory>
#include <QString>

class Player;

class BoardPlace : public std::enable_shared_from_this<BoardPlace>
{
public:
    BoardPlace(const int &inp, const QString& name);
    enum class PlaceType:int {CORNER_PLACE = 0,
                              RAILWAY_PLACE = 1,
                              COUNTER_PLACE = 2,
                              CHANCE_PLACE = 3,
                              CITY_PLACE = 4};
    int getId() const {return id_m;}
    std::unique_ptr<Visitor> getVisitor(int playerId);
    virtual ~BoardPlace() {};
    int getNumberOfBuildHouses() const;
    int getNumberOfBuildHotels() const;
    void setOwnership(std::shared_ptr<Player> inp);
    void buildHouse();
    void buildHotel();
    QString getName() const;
protected:
    const int id_m;
    const QString name_m;

private:
    virtual std::unique_ptr<Visitor> createVisitor(int playerId) = 0;
    virtual int implementGetNumberOfBuildHouses() const = 0;
    virtual int implementGetNumberOfBuildHotels() const = 0;
    virtual void implementBuildHouse() = 0;
    virtual void implementBuildHotel() = 0;
    virtual void implementSetOwnership(std::shared_ptr<Player> inp) = 0;
};

#endif // BOARDPLACE_H
