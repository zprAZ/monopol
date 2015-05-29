#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include "visitors/Visitor.h"
#include <memory>

class BoardPlace
{
public:
    BoardPlace(const int &inp);
    enum class PlaceType:int {CORNER_PLACE = 0,
                              RAILWAY_PLACE = 1,
                              COUNTER_PLACE = 2,
                              CHANCE_PLACE = 3,
                              CITY_PLACE = 4};
    int getId() const {return id_m;}
    std::unique_ptr<Visitor> getVisitor() const;
    virtual ~BoardPlace() {};

protected:
    const int id_m;

private:
    virtual std::unique_ptr<Visitor> createVisitor() const = 0;

};

#endif // BOARDPLACE_H
