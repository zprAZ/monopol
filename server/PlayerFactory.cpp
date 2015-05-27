#include "PlayerFactory.h"
#include <iostream>

PlayerFactory::PlayerFactory(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    server->setMaxPendingConnections(4);
    bool res1 = connect(server, SIGNAL(newConnection()), this, SLOT(createPlayer()));
    bool res2 = connect(this, SIGNAL(playerReady()), this, SLOT(test()));
    Q_ASSERT(res1);
    if(!server ->listen(QHostAddress::Any, 6178))
    {
        std::cerr<<"Failed to bind to port\n"<<std::flush;
    }
}

QVector<Player *> PlayerFactory::getPlayers()
{
    return players;
}

void PlayerFactory::createPlayer()
{
    QTcpSocket* socketTmp = server->nextPendingConnection();
    ClientSocket * socket = new ClientSocket(socketTmp, this);
    Player* player = new Player(socket, this);
    players.push_back(player);
    emit playerReady();
}

void PlayerFactory::test()
{
    for(auto i : players)
    {
        i->testCommunication();
    }
}
