#include "ClientSocket.h"
#include <QEventLoop>


quint64 ClientSocket::messageId = 0;

ClientSocket::ClientSocket(const int& id, QTcpSocket *socket, QObject* parent):
    QObject(parent), socketId(id)
{
    this->socket = socket;
    lastResponseValue = false;
    bool result1 = connect(this->socket, SIGNAL(readyRead()), this, SLOT(readClient()));
    bool result2 = connect(this->socket, SIGNAL(disconnected()),
                           this, SLOT(mySocketDosconnected()));
    Q_ASSERT(result1 && result2);
}
void ClientSocket::sendInfoMessage(const QString& inp)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('c') << quint64(messageId)  << inp;
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

bool ClientSocket::sendQuestionMessage(const QString& text)
{
    bool result = false;
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('d')  << quint64(messageId) << text;
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    if(socket->waitForBytesWritten())
    {
        QEventLoop localLoop;
        localLoop.connect(this, SIGNAL(questionResponseSignal()),&localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::AllEvents);
        result = lastResponseValue;
    }

  return result;
}

void ClientSocket::sendCurrentRoundMessage(const int& roundNumber)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('e')  << quint64(messageId) << quint32(roundNumber);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendTokenIsLeavingMessage(const int& placeId, const int& playerId)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('f')  << quint64(messageId) << quint32(placeId)
        << quint32(playerId);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendTokenIsEnteringMessage(const int& placeId, const int& playerId)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('g')  << quint64(messageId) << quint32(placeId)
        << quint32(playerId);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendMortgageFlagStatus(const int& placeId, const bool& status)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('h')  << quint64(messageId) << quint32(placeId)
        << quint8(static_cast<quint8>(status));
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendOwnershipMessage(const int& placeId, bool status, const int& playerId)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('i')  << quint64(messageId) << quint32(placeId)
        << quint8(status) << quint32(playerId);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendHotelMessage(const int& placeId, bool status)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('j')  << quint64(messageId) << quint32(placeId)
        << quint8(status);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendHouseMessage(const int& placeId, bool status)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('k')  << quint64(messageId) << quint32(placeId)
        << quint8(status);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::deleteAllHousesMessage(const int& placeId)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('m')  << quint64(messageId) << quint32(placeId);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendPrisonCardsInformation(const int& number)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('n')  << quint64(messageId) << quint32(number);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}


void ClientSocket::sendCashMessage(const double& inp)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('o')  << quint64(messageId) << qreal(inp);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::sendWealthMessage(const double& inp)
{
    ++messageId;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << quint8('p')  << quint64(messageId) << qreal(inp);
    out.device() ->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket->write(block);
    socket->waitForBytesWritten();
}

void ClientSocket::showMessage(const QString& inp)
{
        ++messageId;
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        out << quint16(0) << quint8('r') << quint64(messageId)  << inp;
        out.device() ->seek(0);
        out << quint16(block.size() - sizeof(quint16));
        socket->write(block);
        socket->waitForBytesWritten();
}

void ClientSocket::readClient()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);

    if(nextBlockSize == 0)
    {
        if(socket->bytesAvailable() < sizeof(quint16))
        {
            return;
        }
        in >> nextBlockSize;
    }
    if(socket->bytesAvailable() < nextBlockSize)
    {
        return;
    }
    quint8 type;
    in >> type;
    if(type == 'a')
    {
        emit diceSignal();
    }
    if(type == 'b')
    {
        quint8 result;
        in >> result;
        lastResponseValue = static_cast<bool>(result);
        emit questionResponseSignal();
    }
    nextBlockSize = 0;
}

void ClientSocket::mySocketDosconnected()
{
    QObject* myFactory = this->parent();
    bool callResult = QMetaObject::invokeMethod(myFactory,"deleteDisconnectedPlayer",
                      Q_ARG(int,socketId));
    socket ->deleteLater();
}

int ClientSocket::getSocketId() const
{
    return socketId;
}
