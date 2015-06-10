#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QPointer>
#include <map>

class Player;
class ClientSocket;

class PlayerFactory : public QObject
{
    Q_OBJECT
public:
    explicit PlayerFactory(QObject *parent = 0);
    QVector<Player*> getPlayers();
    void handlePlayerBankruptcy(const int& playerId);
    void doManyToOneTransaction(const int& playerId, const double& amount, const QString &message);
signals:
    void playerReady();
    void removePlayerFromBoard(int playerId);
public slots:

    void createPlayer();
    void test();
    void deleteDisconnectedPlayer(const int& id);
    void sendMessageToAllSockets(const QString& inp);
private:

    QTcpServer* server;
    QVector<Player*> players;
    std::map<int, bool> idAssignment;
    std::map<int, ClientSocket*> allSockets;

    friend class ClientSocket;
};

#endif // PLAYERFACTORY_H
