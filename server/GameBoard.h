#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "places/BoardPlace.h"


#include <QObject>

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);

signals:

public slots:

private:
    std::vector<std::shared_ptr<BoardPlace>> placesVector;

};

#endif // GAMEBOARD_H
