#include "Pawn.h"
#include "visitors/Visitor.h"

Pawn::Pawn(QObject *parent) :
    QObject(parent)
{
}

void Pawn::go(const int& inp)
{
    return this->implementGo(inp);
}

int Pawn::getLastMovement() const
{
    return this->implementLastMovement();
}
bool Pawn::ifIsValid() const
{
    return this->implementValidation();
}
void Pawn::invalidate()
{
    this->implementInvalidation();
}

void Pawn::accept(Visitor& visitor)
{
    visitor.visit(*this);
}
