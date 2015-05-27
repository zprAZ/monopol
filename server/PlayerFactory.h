#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

#include "Player.h"

class ClientSocket;

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
    QTcpServer* server;
    QVector<Player*> players;
};

#endif // PLAYERFACTORY_H
