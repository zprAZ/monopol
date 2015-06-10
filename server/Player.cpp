#include "Player.h"

Player::Player(const int &id, QPointer<ClientSocket> socketInp, QObject *parent) :
    QObject(parent), playerId(id), money(0), prisonFreeCardsNumber(0)
{
    this->socket = socketInp;
    connect(socket, SIGNAL(diceSignal()), this, SLOT(handleDiceTest()));
}

void Player::testCommunication()
{
    Q_ASSERT(this->playerId == socket->getSocketId());
    socket->sendHotelMessage(6,true);
    socket->sendHotelMessage(6,false);
    socket->sendInfoMessage(QString("this is first info message %1").arg(playerId));
    socket->sendMortgageFlagStatus(9, true);
    socket->sendCashMessage(126.5765);
    socket->sendCurrentRoundMessage(120*this->playerId);
    socket->sendTokenIsEnteringMessage(0,1);
    socket->sendTokenIsEnteringMessage(0,2);
    socket->sendTokenIsEnteringMessage(0,3);
    socket->sendTokenIsEnteringMessage(0,4);
    socket->sendInfoMessage(QString("INFO message %1").arg(playerId));
    socket->sendPrisonCardsInformation(1);
    socket->sendTokenIsLeavingMessage(0,1);
    socket->sendTokenIsEnteringMessage(12,1);
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
    socket->showMessage(QString("this is message %1").arg(playerId));
   /* while(true)
    {
    if(socket ->sendQuestionMessage(QString("do you really want to play?")))
    {
        socket->showMessage(QString("You said YES"));
    }
    else
    {
        socket->showMessage(QString("You said NO"));
    }
    }*/
   // socket->sen
}

void Player::handleDiceTest()
{
    socket->sendInfoMessage(QString("DICE"));
}

QPointer<ClientSocket> Player::getSocketPointer()
{
    return socket;
}

int Player::getPlayerId()const
{
    return playerId;
}

void Player::sendMessageToAll(const QString& inp)
{
    this->socket->sendToAll(inp);
}

void Player::sendMessageToThisPlayer(const QString& inp)
{
    this->socket->sendInfoMessage(inp);
}

void Player::payMoney(const double& payment)
{
    if(!this->money < payment)
    {
    this->money -=payment;
    }else
    {
        this->sendMessageToThisPlayer(QString("You are bankrupt!"));
        this->sendMessageToAll(QString("Player %1 has lost the game!").arg(this->playerId));
        QObject* myFactory = this->parent();
        bool callResult = QMetaObject::invokeMethod(myFactory,"handlePlayerBankruptcy",
                                                Q_ARG(int, this->playerId));
        if(!callResult)
        {
            // ZCU_TODO
        }
    }
}

void Player::collectMoney(const double& income)
{
    this->money += income;
}

void Player::addPrisonFreeCard()
{
    ++prisonFreeCardsNumber;
}

void Player::takeMoneyFromOthers(const double& amount, const QString& message2others)
{
    QObject* myFactory = this->parent();
    bool callResult = QMetaObject::invokeMethod(myFactory,"doManyToOneTransaction",
                                            Q_ARG(int, this->playerId),
                                            Q_ARG(double, amount),
                                            Q_ARG(QString, message2others));
    if(!callResult)
    {
        // ZCU_TODO
    }
}
