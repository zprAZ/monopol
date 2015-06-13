#include "MoveVisitor.h"
#include "Pawn.h"

MoveVisitor::MoveVisitor():movement(0), playerMessage(QString(""))
{
}

std::unique_ptr<Visitor>  MoveVisitor::createGoVisitor()
{
    return std::unique_ptr<Visitor> (new MoveVisitor);
}

void MoveVisitor::visit(Pawn& inp)
{
    inp.move(this->movement, this->playerMessage);
}

void MoveVisitor::visit(Player& inp)
{
    // do nothing
}

void MoveVisitor::init(const int& movement, const QString& playerMessage)
{
    this->movement = movement;
    this->playerMessage = playerMessage;
}

std::unique_ptr<Visitor> MoveVisitor::clone() const
{
    return std::unique_ptr<Visitor>(new MoveVisitor(*this));
}
