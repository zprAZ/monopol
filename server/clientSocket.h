#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QTcpSocket>

class clientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit clientSocket(QObject *parent = 0);

signals:

public slots:

};

#endif // CLIENTSOCKET_H
