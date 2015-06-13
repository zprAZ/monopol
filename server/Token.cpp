#include "Token.h"

int Token::max_position_m = 39;

Token::Token(const int &id, QObject *parent) : tokenId(id),
    Pawn(parent)
{
}

void Token::accept(std::unique_ptr<Visitor> visitor)
{
    // IMPORTANT first we visit pawn and then player!
    visitor->visit(*this);
    visitor->visit(*player_m);
}

void Token::implementGoToDestination(const int& destination, const bool& startBonus,
                                     const QString& message, const bool& forwardDirectionFlag)
{
    if(message.length() > 0)
    {
    player_m -> sendMessageToThisPlayer(message);
    }
    if(!(destination < 0) && !(destination > max_position_m))
    {
        QPointer<ClientSocket> socketPtr = player_m ->getSocketPointer();
        socketPtr ->sendTokenIsLeavingMessage(this->current_position_m, player_m->getPlayerId());
        this->current_position_m = destination;
        socketPtr->sendTokenIsEnteringMessage(destination, player_m->getPlayerId());
    player_m -> sendMessageToAll(QString("Player %1 moves to place number %2")
                                 .arg(player_m->getPlayerId())
                         .arg(destination));
    }else
    {
        // ZCU_TODO error  wrond destination
    }

}

void Token::implementMovement(const int& inp, const QString& message)
{
    if(message.length() > 0)
    {
    player_m -> sendMessageToThisPlayer(message);
    }
    QPointer<ClientSocket> socketPtr = player_m ->getSocketPointer();
    socketPtr ->sendTokenIsLeavingMessage(this->current_position_m, player_m->getPlayerId());
    if(!inp<0)
    {
    this->current_position_m = (this->current_position_m + inp) % max_position_m;
    }else
    {
        int tmp = this->current_position_m + inp;
        if(!tmp<0)
        {
            this->current_position_m = tmp;
        }else
        {
            this->current_position_m = tmp + max_position_m;
        }
    }
    socketPtr ->sendTokenIsEnteringMessage(this->current_position_m, player_m->getPlayerId());
    player_m -> sendMessageToAll(QString("Player %1 moves to place number %2")
                                 .arg(player_m->getPlayerId())
                         .arg(this->current_position_m));
}

void Token::implementGoToPrison(const int& roundNumber)
{

}

void Token::implementMovePayment(const double& amountPerMove, const QString& playerMessage)
{
    int movesNumber = this->getLastMovement();
    double payment = amountPerMove * movesNumber;
    player_m ->sendMessageToThisPlayer(playerMessage + QString("Payment: %1").arg(payment));
    player_m ->payMoney(payment);
}
