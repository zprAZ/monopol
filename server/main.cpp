
#include <QApplication>
#include "Player.h"
#include "ClientSocket.h"
#include "PlayerFactory.h"
#include "GameBoard.h"


int main(int argc, char* tab[])
{
    QApplication app(argc, tab);

    GameBoard board;

    PlayerFactory factory;

    return app.exec();
}
