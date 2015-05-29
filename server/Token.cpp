#include "Token.h"

Token::Token(const int &maxPos, QObject *parent) :
    Pawn(parent)
{

}

void Token::accept(Visitor &visitor)
{
    visitor.visit(*this);
    visitor.visit(*player_m);
}

void Token::implementGo(const int& inp)
{

}

int Token::implementLastMovement() const
{

}
bool Token::implementValidation() const
{

}
bool Token::implementInvalidation()
{

}
