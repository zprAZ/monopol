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
signals:

public slots:
   void handleDiceTest();

private:
QPointer<ClientSocket> socket;
const int playerId;
};

#endif // PLAYER_H
