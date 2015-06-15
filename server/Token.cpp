#include "Token.h"

int Token::max_position_m = 39;

bool Token::startGameFlag = false;

Token::Token(const int &id, std::vector<std::shared_ptr<BoardPlace> > &boardRef,
             QObject *parent) : tokenId(id), placesVectorReference(boardRef), Pawn(parent),
    requestForMovementFlag(false)
{
}

void Token::accept(std::unique_ptr<Visitor> visitor)
{
    // IMPORTANT first we visit player and then pawn
    visitor->visit(*player_m);
    visitor->visit(*this);
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

void Token::setPlayer(std::shared_ptr<Player> inpPlayerPtr)
{
    this->player_m = inpPlayerPtr;
    this->valid_m = true;
    this->current_position_m = 0;
    this->currentRoundNumber = 1;
    QPointer<ClientSocket> socket = player_m->getSocketPointer();
    socket ->sendCurrentRoundMessage(this->currentRoundNumber);
    socket ->sendTokenIsEnteringMessage(0, player_m->getPlayerId());
    // WE NEED TO CONNECT PLAYER AND TOKEN SIGNALS AND SLOTS
    QObject::connect(player_m.get(),SIGNAL(playerClickedDice()), this, SLOT(handlePlayerDiceClick()));
}

void Token::doNextMove()
{
    this->requestForMovementFlag = true;
    // we need to start device which will emit dice signal in case user forgot.
    //QObject::disconnect()
    this->player_m->requestForDice();
}

void Token::removePlayer()
{
    // WE NEED TO DISCONNECT SIGNALS AND SLOTS
    this->player_m = nullptr;
}

void Token::handlePlayerDiceClick()
{
    if(!startGameFlag)
    {
        emit startGame();
    }else
    {
        if(this->requestForMovementFlag)
        {
            this->requestForMovementFlag = false;
            int movement  = qrand()%12 +1;
            this->move(movement, QString("Player %1 moves % steps forward").
                       arg(player_m->getPlayerId()).arg(movement));
        }
    }

}
