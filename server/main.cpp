
#include <QApplication>
#include "Player.h"
#include "ClientSocket.h"
#include "PlayerFactory.h"
#include "GameBoard.h"
#include <QTime>


int main(int argc, char* tab[])
{
    QApplication app(argc, tab);

    qsrand(QTime::currentTime().msec());

    GameBoard board;

    PlayerFactory factory;

    return app.exec();
}
