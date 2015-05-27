#ifndef SERVERCONNECTOR_H
#define SERVERCONNECTOR_H

#include <QObject>
#include <QString>
#include <QTcpSocket>

class ServerConnector : public QObject
{
    Q_OBJECT
public:
    explicit ServerConnector(QObject *parent = 0);

signals:
    void errorSignal(const QString& message);
    void askQuestionSignal(int id, const QString& question);
    void showInfoSignal(const QString& info);
    void tokenIsLeavingSignal(int placeId, int playerId);
    void tokenIsEnteringSignal(int placeId, int playerId);
    void displayRoundSignal(int round);
    void displayMessageSignal(const QString& message);
    void displayWealthSignal(double inp);
    void displayCashSignal(double inp);
    void displayPrisonCardsSignal(int inp);
    void doHouseSignal(int id, bool inp);
    void deleteAllHousesSignal(int id);
    void doHotelSignal(int id, bool inp);
    void setOwnershipFlagSignal(int id, bool flag,int  playerNumber);
    void setMortgageFlagSignal(int id, bool inp);

public slots:
    void sendResponse(int messageId, bool answer); // for question dialog signal
    void establishConnection(const QString& ip, int port);
    void establishConnection();
    void setTcpSettings(const QString& ip, int port);
    void closeConnection();
    void handleDiceRequest();

private slots:
    void connectionClosedByServer();
    void error(QAbstractSocket::SocketError error);
    void connectionHasBeenEstablished();
    void readDataFromSocket();
private:
    QString ipAddress;
    int portNumber;
    QTcpSocket tcpSocket;
    bool connectionOK = false;
    quint16 nextBlockSize = 0;
};

#endif // SERVERCONNECTOR_H
