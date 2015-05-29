#include "PlayerFactory.h"
#include <iostream>
#include <algorithm>

PlayerFactory::PlayerFactory(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    server->setMaxPendingConnections(4);
    bool res1 = connect(server, SIGNAL(newConnection()), this, SLOT(createPlayer()));
    bool res2 = connect(this, SIGNAL(playerReady()), this, SLOT(test()));
    Q_ASSERT(res1);
    idAssignment.insert(std::pair<int, bool>(1,true)); // true indicates
    idAssignment.insert(std::pair<int, bool>(2,true));// that assignment is possible
    idAssignment.insert(std::pair<int, bool>(3,true));
    idAssignment.insert(std::pair<int, bool>(4,true));
    Q_ASSERT(idAssignment.size() == 4);
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

    std::map<int, bool>::const_iterator result = std::find_if(idAssignment.begin(),
                                                        idAssignment.end(),
                         [](const std::pair<int, bool>& inp){return inp.second;});


    if(result != idAssignment.end())
    {
    int id  = result->first;
    QTcpSocket* socketTmp = server->nextPendingConnection();
    ClientSocket * socket = new ClientSocket(id ,socketTmp, &this->deleteDisconnectedPlayer,this);
    allSockets.insert(std::pair<int, ClientSocket*>(id, socket));
    Player* player = new Player(result->first, socket, this);
    players.push_back(player);
    emit playerReady();
    }else
    {
        //ZCU_TODO
    }
}

void PlayerFactory::test()
{
    for(auto i : players)
    {
        i->testCommunication();
    }
}

void PlayerFactory::deleteDisconnectedPlayer(const int &id)
{
    std::map<int, ClientSocket*>::iterator iter;
    iter = allSockets.find(id);
    allSockets.erase(iter);
    std::for_each(allSockets.begin(), allSockets.end(),
                  [&](std::pair<int, ClientSocket*>& a)
    {
  a.second->sendInfoMessage(QString(tr("Player with id = %1 stoped playing")).
                               arg(id));
    });
}
