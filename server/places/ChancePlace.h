#ifndef CHANCEPLACE_H
#define CHANCEPLACE_H

#include <memory>
#include "BoardPlace.h"
#include ""

class ChancePlace : public BoardPlace
{
public:
    ChancePlace(const int& inp);

private:
    virtual std::unique_ptr<Visitor> createVisitor() const;
};

#endif // CHANCEPLACE_H
