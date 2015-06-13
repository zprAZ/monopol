#include "PlayerFactory.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

PlayerFactory::PlayerFactory(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    server->setMaxPendingConnections(4);
    bool res1 = connect(server, SIGNAL(newConnection()), this, SLOT(createPlayer()));
    bool res2 = connect(this, SIGNAL(playerReady()), this, SLOT(test()));
    Q_ASSERT(res1 && res2);
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

QVector<std::shared_ptr<Player> > PlayerFactory::getPlayers()
{
    return players;
}

void PlayerFactory::createPlayer()
{

    std::map<int, bool>::const_iterator result = std::find_if(idAssignment.begin(),
                                                        idAssignment.end(),
                         [](const std::pair<int, bool>& inp)->bool {return inp.second;});


    if(result != idAssignment.end())
    {
    int id  = result->first;
    QTcpSocket* socketTmp = server->nextPendingConnection();
    ClientSocket * socket = new ClientSocket(id ,socketTmp,this);
    allSockets.insert(std::pair<int, ClientSocket*>(id, socket));
    std::shared_ptr<Player> player(new Player(result->first, socket, this));
    players.push_back(player);
    std::map<int, bool>::iterator innerResult = std::find_if(idAssignment.begin(),
                                                        idAssignment.end(),
                         [&id](const std::pair<int, bool>& inp)->bool
                            {return inp.first == id;});
        if(innerResult != idAssignment.end())
        {
            innerResult->second = false;
        }else
        {
            // we need to close application
        }
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
    // here we need to emit proper signals to pawns container

    // we need to preserve invariant
    std::map<int, bool>::iterator iterAssignment = std::find_if(idAssignment.begin(),
                                                        idAssignment.end(),
                         [&id](const std::pair<int, bool>& inp)->bool
                            {return inp.first == id;});
    if(iterAssignment != idAssignment.end())
    {
        iterAssignment->second = true;
    }else
    {
        // we need to stop application
    }

    // we need to remove socket from group communication
    std::map<int, ClientSocket*>::iterator iter;
    int tmpId = id;
    iter = allSockets.find(tmpId);
    allSockets.erase(iter);
    std::for_each(allSockets.begin(), allSockets.end(),
                  [&tmpId](std::pair<int, ClientSocket*> a)
    {
        a.second->sendInfoMessage(QString(tr("Player with id = %1 stoped playing")).
                               arg(tmpId));
    });
}

void PlayerFactory::sendMessageToAllSockets(const QString& inp)
{
    std::for_each(allSockets.begin(), allSockets.end(),
                  [&inp](std::pair<int, ClientSocket*> a)
    {
        a.second->sendInfoMessage(inp);
    });
}

void PlayerFactory::doManyToOneTransaction(const int& playerId, const double& amount
                                           ,const QString& message)
{
    auto collector = std::find_if(players.begin(), players.end(),
                                  [&playerId](std::shared_ptr<Player> a)->bool
    {return a->getPlayerId() == playerId; });
    if(collector != players.end())
    {
        int counter = 0;
        std::for_each(players.begin(), players.end(),
                      [&](std::shared_ptr<Player> a)
        {
            if(a->getPlayerId() != playerId)
            {
                ++counter;
                a->sendMessageToThisPlayer(message);
                a->payMoney(amount);
            }

        });
        (*collector)->collectMoney(counter * amount);
    }else
    {
        // ZCU_TODO
    }
}

void PlayerFactory::handlePlayerBankruptcy(const int& playerId)
{
    // ZCU_TODO
}


