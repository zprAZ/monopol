
#include <QApplication>
#include "Player.h"
#include "ClientSocket.h"
#include "PlayerFactory.h"


int main(int argc, char* tab[])
{
    QApplication app(argc, tab);

    PlayerFactory factory;

    return app.exec();
}
