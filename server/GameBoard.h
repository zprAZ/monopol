#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "places/BoardPlace.h"
#include "Player.h"
#include "Token.h"
#include "PlayerFactory.h"


#include <QObject>

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);

signals:

public slots:
    void startGame();
    void addPlayer(std::shared_ptr<Player> newPlayer);
    void handleRemovePlayerRequest(int playerId);

private:
    std::vector<std::shared_ptr<BoardPlace>> placesVector;
    std::vector<QPointer<Token>> tokens;
    PlayerFactory playerFactory;
};

#endif // GAMEBOARD_H
