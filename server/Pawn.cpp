#include "Pawn.h"
#include "visitors/Visitor.h"

int Pawn::currentRoundNumber = 0;

Pawn::Pawn(QObject *parent) :
    QObject(parent)
{
}

void Pawn::goToDestination(const int& destination, const bool& startBonus, const QString& message,
              const bool& forwardDirectionFlag)
{
    this->lastMovement = 0;
    this->implementGoToDestination(destination, startBonus, message, forwardDirectionFlag);
}

int Pawn::getLastMovement() const
{
    return this->lastMovement;
}
bool Pawn::ifIsValid() const
{
    return this->valid_m;
}
void Pawn::invalidate()
{
    this->valid_m = false;
}

void Pawn::accept(std::unique_ptr<Visitor> visitor)
{
    // should not happen
}

bool Pawn::ifNotInPrison() const
{
    if(currentRoundNumber - lastPrisonRoundNumber > prisonTime)
    {
        return !(this->prisonFlag = false);
    }else
    {
        return !(this->prisonFlag = true);
    }
}

void Pawn::goToPrison(const int& roundNumber)
{
    this->prisonFlag = true;
    this->lastPrisonRoundNumber = currentRoundNumber;
    this->prisonTime = roundNumber;
    this->implementGoToPrison(roundNumber);
}

void Pawn::updateRoundNumber()
{
    ++currentRoundNumber;
}

void Pawn::payForMoves(const double& amountPerMove, const QString& playerMessage)
{
    this->implementMovePayment(amountPerMove, playerMessage);
}

void Pawn::move(const int & inp, const QString &message)
{
    this->lastMovement = std::abs(inp);
    this->implementMovement(inp, message);
}

