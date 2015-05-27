#ifndef PLAYER_H
#define PLAYER_H

#include "ClientSocket.h"

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(ClientSocket* socketInp, QObject *parent = 0);
    void testCommunication();
signals:

public slots:
   void handleDiceTest();

private:
ClientSocket* socket;

};

#endif // PLAYER_H
