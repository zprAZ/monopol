#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QPointer>
#include <map>

#include "Player.h"

class PlayerFactory : public QObject
{
    Q_OBJECT
public:
    explicit PlayerFactory(QObject *parent = 0);
    QVector<Player*> getPlayers();
signals:
    void playerReady();

public slots:

    void createPlayer();
    void test();

private:
    static void deleteDisconnectedPlayer(const int& id);
    QTcpServer* server;
    QVector<Player*> players;
    std::map<int, bool> idAssignment;
    std::map<int, ClientSocket*> allSockets;

    friend class ClientSocket;
};

#endif // PLAYERFACTORY_H
