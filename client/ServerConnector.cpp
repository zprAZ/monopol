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
    if(connectionOK = tcpSocket.isValid())
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        out << quint16(0) << quint8('b') << quint8(static_cast<int>(answer));
        out.device() ->seek(0);
        out << quint16(block.size() - sizeof(quint16));
        tcpSocket.write(block);
    }else
    {
        // ZCU_TODO
        emit errorSignal(QString(tr("Connection is not valid")));
    }
}

void ServerConnector::establishConnection(const QString& ip, int port)
{
    ipAddress = ip;
    portNumber = port;
    tcpSocket.connectToHost(QHostAddress(ipAddress), portNumber);
}

void ServerConnector::establishConnection()
{
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
    if(connectionOK = tcpSocket.isValid())
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        out << quint16(0) << quint8('a');
        out.device() ->seek(0);
        out << quint16(block.size() - sizeof(quint16));
        tcpSocket.write(block);
    }
}

void ServerConnector::connectionClosedByServer()
{
    emit errorSignal(QString(tr("Connection closed by server! sorry")));
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
        quint64 messageId;
        in >>messageId;
        switch(messageType)
        {
        case 'c': // info message
            {
                QString text;
                in >>text;
                emit showInfoSignal(text);
                break;
            }
        case 'd': // question message
            {
                QString text;
                in>>text;
                emit askQuestionSignal(messageId, text);
                break;
            }
        case 'e': // round message
            {
                quint32 roundNumber;
                in >> roundNumber;
                emit displayRoundSignal(roundNumber);
                break;
            }
        case 'f': // token is leaving
            {
                quint32 placeId;
                quint32 playerId;
                in >> placeId >> playerId;
                emit tokenIsLeavingSignal(placeId, playerId);
                break;
            }
        case 'g': // token is entering
            {
                quint32 placeId;
                quint32 playerId;
                in >> placeId >> playerId;
                emit tokenIsEnteringSignal(placeId, playerId);
                break;
            }
        case 'h': // mortgage flag
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId;
                in >> boolFlag;
                emit setMortgageFlagSignal(placeId, static_cast<bool>(boolFlag));
                break;
            }
        case 'i': // ownership flag
            {
                quint32 placeId;
                quint8 boolFlag;
                quint32 playerId;
                in >> placeId >> boolFlag >> playerId;
                emit setOwnershipFlagSignal(placeId, boolFlag, playerId);
                break;
            }
        case 'j': // do hotal
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId >> boolFlag;
                emit doHotelSignal(placeId,boolFlag);
                break;
            }
        case 'k': // do house
            {
                quint32 placeId;
                quint8 boolFlag;
                in >> placeId >> boolFlag;
                emit doHouseSignal(placeId, boolFlag);
                break;
            }
        case 'm': // delete all houses
            {
                quint32 placeId;
                in >> placeId;
                emit deleteAllHousesSignal(placeId);
                break;
            }
        case 'n': // display prison cards
            {
                quint32 prisonCardsNumber;
                in >> prisonCardsNumber;
                emit displayPrisonCardsSignal(prisonCardsNumber);
                break;
            }
        case 'o': // display cash
            {
                qreal value;
                in >> value;
                emit displayCashSignal(value);
                break;
            }
        case 'p': // display wealth
            {
                qreal value;
                in >> value;
                emit displayWealthSignal(value);
                break;
            }
        case 'r': // show message to all players
            {
                QString text;
                in >>text;
                emit displayMessageSignal(text);
                break;
            }
        default:
            emit errorSignal(QString("unrecognized message type"));
            break;
        }
        nextBlockSize = 0;
    } // forever
}
