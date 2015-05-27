#include "Player.h"

Player::Player(ClientSocket *socketInp, QObject *parent) :
    QObject(parent)
{
    this->socket = socketInp;
    connect(socket, SIGNAL(diceSignal()), this, SLOT(handleDiceTest()));
}

void Player::testCommunication()
{
    socket->sendHotelMessage(6,true);
    socket->sendInfoMessage(QString("this is first info message"));
    socket->sendMortgageFlagStatus(9, true);
    socket->sendCashMessage(126.5765);
    socket->sendCurrentRoundMessage(120);
    socket->sendTokenIsEnteringMessage(0,1);
    socket->sendTokenIsEnteringMessage(0,2);
    socket->sendTokenIsEnteringMessage(0,3);
    socket->sendTokenIsEnteringMessage(0,4);
    socket->sendInfoMessage(QString("INFO message"));
    socket->sendPrisonCardsInformation(1);
    socket->sendTokenIsLeavingMessage(0,1);
    socket->sendTokenIsEnteringMessage(12,1);
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    socket->showMessage(QString("this is message"));
    while(true)
    {
    if(socket ->sendQuestionMessage(QString("do you really want to play?")))
    {
        socket->showMessage(QString("You said YES"));
    }
    else
    {
        socket->showMessage(QString("You said NO"));
    }
    }
   // socket->sen
}

void Player::handleDiceTest()
{
    socket->sendInfoMessage(QString("DICE"));
}
