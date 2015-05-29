#include "BoardPlace.h"

BoardPlace::BoardPlace(const int& inp): id_m(inp)
{
}

std::unique_ptr<Visitor> BoardPlace::getVisitor() const
{
    return this->createVisitor();
}
