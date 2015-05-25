#include "ServerConnector.h"
#include <QHostAddress>
#include <QDataStream>


ServerConnector::ServerConnector(QObject *parent) :
    QObject(parent)
{
    connectionOK = false;
    bool res1 = connect(&tcpSocket, SIGNAL(connected()), this, SLOT(connectionHasBeenEstablished()));
    bool res2 = connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                        this, SLOT(error(QAbstractSocket::SocketError)));

    bool res3 = connect(&tcpSocket, SIGNAL(readyRead()),  this , SLOT(readDataFromSocket()));
    bool res4 = connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(connectionClosedByServer()));
}

void ServerConnector::sendResponse(int messageId, bool answer) // for question dialog signal
{
    if(connectionOK)
    {

    }else
    {
        // ZCU_TODO
    }
}

void ServerConnector::establishConnection(const QString& ip, int port)
{
    ipAddress = ip;
    portNumber = port;
    tcpSocket.connectToHost(QHostAddress(ipAddress), portNumber);
}

void ServerConnector::setTcpSettings(const QString& ip, int port)
{
    ipAddress = ip;
    portNumber = port;
}

void ServerConnector::closeConnection()
{
    tcpSocket.close();
}

void ServerConnector::handleDiceRequest()
{

}

void ServerConnector::connectionClosedByServer()
{

}

void ServerConnector::error(QAbstractSocket::SocketError error)
{
    connectionOK = false;
    QString description;
    switch(error)
    {
    case QAbstractSocket::ConnectionRefusedError:
        description = QString(tr("The connection was refused by the peer (or timed out).\n"));
        break;
    case QAbstractSocket::RemoteHostClosedError:
        description = QString(tr("The remote host closed the connection.\n"
                              "Note that the client socket (i.e., this socket)\n"
                              "will be closed after the remote close notification has been sent."));
        break;
    case QAbstractSocket::HostNotFoundError:
        description = QString(tr("The provided server address was not found."));
        break;
    case QAbstractSocket::SocketAccessError:
        description = QString(tr("The socket operation failed\n"
                              "because the application lacked\n"
                              "the required privileges."));
        break;
    case QAbstractSocket::SocketResourceError:
        description = QString(tr("The local system ran out of resources\n"
                                 "(e.g., too many sockets)."));
        break;
    case QAbstractSocket::SocketTimeoutError:
        description = QString(tr("The socket operation timed out"));
        break;
    case QAbstractSocket::DatagramTooLargeError:
        description = QString(tr("The datagram was larger than the operating system's limit\n"
                                 "(which can be as low as 8192 bytes)."));
        break;
    case QAbstractSocket::NetworkError:
        description = QString(tr("An error occurred with the network\n"
                                 "(e.g., the network cable was accidentally plugged out)."));
        break;
    case QAbstractSocket::AddressInUseError:
        description = QString(tr("Address ip in use error "));
        break;
    default:
        description = QString(tr("Unknown socket error has occured"));
        break;
    }
}

void ServerConnector::connectionHasBeenEstablished()
{
    connectionOK = true;
}

void ServerConnector::readDataFromSocket()
{
    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_8);

    forever
    {
        if(nextBlockSize == 0)
        {
            if(tcpSocket.bytesAvailable() < sizeof(quint16))
            {
                break;
            }
            in >> nextBlockSize;
        }
        if(nextBlockSize == 0xFFFF) break; // no more data to receive
        if(tcpSocket.bytesAvailable() < nextBlockSize) break;
        // now we can read message
        quint8 messageType;
        in >> messageType;
        qint64 messageId;
        in >>messageId;
        switch(messageType)
        {
        case 1: // info message
            {
                QString text;
                in >>text;
                emit displayMessageSignal(text);
                break;
            }
        case 2: // question message
            {
                QString text;
                in>>text;
                emit askQuestionSignal(messageId, text);
                break;
            }
        case 3: // round message
            {
                quint32 roundNumber;
                in >> roundNumber;
                emit displayRoundSignal(roundNumber);
                break;
            }
        case 4: // token is leaving
            {
                quint32 placeId;
                quint32 playerId;
                in >> placeId >> playerId;
                emit tokenIsLeavingSignal(placeId, playerId);
                break;
            }
        case 5: // token is entering
            {
                quint32 placeId;
                quint32 playerId;
                in >> placeId >> playerId;
                emit tokenIsEnteringSignal(placeId, playerId);
                break;
            }
        case 6: // mortgage flag
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId;
                in >> boolFlag;
                emit setMortgageFlagSignal(placeId, static_cast<bool>(boolFlag));
                break;
            }
        case 7: // ownership flag
            {
                quint32 placeId;
                quint8 boolFlag;
                quint32 playerId;
                in >> placeId >> boolFlag >> playerId;
                emit setOwnershipFlagSignal(placeId, boolFlag, playerId);
                break;
            }
        case 8: // do hotal
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId >> boolFlag;
                emit doHotelSignal(placeId,boolFlag);
                break;
            }
        case 9: // do house
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId >> boolFlag;
                emit doHouseSignal(placeId, boolFlag);
                break;
            }
        case 10: // delete all houses
            {
                quint32 placeId;
                in >> placeId;
                emit deleteAllHousesSignal(placeId);
                break;
            }
        case 11: // display prison cards
            {
                quint32 prisonCardsNumber;
                in >> prisonCardsNumber;
                emit displayPrisonCardsSignal(prisonCardsNumber);
                break;
            }
        case 12: // display cash
            {
                qreal value;
                in >> value;
                emit displayCashSignal(value);
                break;
            }
        case 13: // display wealth
            {
                qreal value;
                in >> value;
                emit displayWealthSignal(value);
                break;
            }
        case 14: //
        default:
            emit errorSignal(QString("unrecognized message type"));
            break;
        }

    }
}
