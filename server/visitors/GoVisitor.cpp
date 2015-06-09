#include "GoVisitor.h"
#include "Pawn.h"
#include "Player.h"

GoVisitor::GoVisitor():startBonus(true), movement(0),message("")
{
}

std::unique_ptr<Visitor>  createGoVisitor()
{
    return std::unique_ptr<Visitor>( new GoVisitor);
}

void GoVisitor::visit(Pawn& inp)
{
    inp.go(this->movement);

}
void GoVisitor::visit(Player& inp)
{
    if(this->movement>0)
    {
    inp.sendMessageToAll(QString("Player %1 moves forward %2 places").arg(inp.getPlayerId())
                         .arg(this->movement));
    }
    else if(this->movement < 0)
    {
    inp.sendMessageToAll(QString("Player %1 moves backward %2 places").arg(inp.getPlayerId())
                             .arg(this->movement));
    }
    if(this->message.length() > 0)
    {
    inp.sendMessageToThisPlayer(this->message);
    }
}

void GoVisitor::setStartBonus(const bool& inp)
{
    this->startBonus = inp;
}
void GoVisitor::setMovement(const int& inp)
{
    this->movement = inp;
}
void GoVisitor::setDisplayMessage(const QString& message)
{
    this->message = message;
}

void GoVisitor::init(const int& movement, const bool& startBonus, const QString &message)
{
    this->movement = movement;
    this->message = message;
    this->startBonus = startBonus;
}
