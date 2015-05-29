#include "ChancePlace.h"
#include "BoardPlace.h"


ChancePlace::ChancePlace(const int& inp):BoardPlace(inp)
{
}

std::unique_ptr<Visitor> ChancePlace::createVisitor() const
{

}
