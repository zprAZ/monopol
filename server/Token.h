#ifndef TOKEN_H
#define TOKEN_H

#include <memory>
#include "visitors/Visitor.h"
#include "Player.h"
#include "Pawn.h"

class Token : public Pawn
{
    Q_OBJECT
public:
    explicit Token(const int& maxPos = 39, QObject *parent = 0);
    virtual void accept(Visitor& visitor);
    void setPlayer(std::shared_ptr<Player> inpPlayerPtr);
signals:

public slots:

private:

    virtual void implementGo(const int& inp) = 0;
    virtual int implementLastMovement() const = 0;
    virtual bool implementValidation() const = 0;
    virtual bool implementInvalidation() = 0;

    int current_position_m;
    static int max_position_m;
    std::shared_ptr<Player> player_m;
    bool valid_m = false;
};

#endif // TOKEN_H
