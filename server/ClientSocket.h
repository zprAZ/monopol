#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QTcpSocket>
#include <QSharedPointer>
#include <QPointer> // guard pointer

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(const int& id, QTcpSocket* socket,
                          QObject *parent = 0 );
    bool sendQuestionMessage(const QString& text);
    int getSocketId() const;
signals:
    void diceSignal();
    void questionResponseSignal();
public slots:
    void sendInfoMessage(const QString& inp);
    void sendCurrentRoundMessage(const int& roundNumber);
    void sendTokenIsLeavingMessage(const int& placeId, const int& playerId);
    void sendTokenIsEnteringMessage(const int& placeId, const int& playerId);
    void sendMortgageFlagStatus(const int& placeId, const bool& status);
    void sendOwnershipMessage(const int& placeId, bool status, const int& playerId);
    void sendHotelMessage(const int& placeId, bool status);
    void sendHouseMessage(const int& placeId, bool status);
    void deleteAllHousesMessage(const int& placeId);
    void sendPrisonCardsInformation(const int& number);
    void sendWealthMessage(const double& inp);
    void sendCashMessage(const double& inp);
    void showMessage(const QString& inp);

private slots:
    void readClient();
    void mySocketDosconnected();

private:
    static quint64 messageId;
    quint16 nextBlockSize = 0;
    bool lastResponseValue;
    QPointer<QTcpSocket> socket;
    QVector<QPointer<ClientSocket>> allSockets;
    const int socketId;
};




#endif // CLIENTSOCKET_H
