#ifndef PLAYER_H
#define PLAYER_H


#include <QObject>

#include "ClientSocket.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(const int& id,
                    QPointer<ClientSocket> socketInp, QObject *parent = 0);
    void testCommunication();
    QPointer<ClientSocket> getSocketPointer();
    int getPlayerId()const;
    void sendMessageToAll(const QString& inp);
    void sendMessageToThisPlayer(const QString& inp);
    void payMoney(const double& payment);
    void collectMoney(const double& income);
    void addPrisonFreeCard();
    void takeMoneyFromOthers(const double& amount, const QString& message2others);
signals:

public slots:
   void handleDiceTest();

private:
QPointer<ClientSocket> socket;
const int playerId;
double money;
int prisonFreeCardsNumber;
};

#endif // PLAYER_H
