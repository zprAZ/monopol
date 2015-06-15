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
    explicit Token(const int& id,std::vector<std::shared_ptr<BoardPlace>>& boardRef,
                   QObject *parent = 0);
    virtual void accept(std::unique_ptr<Visitor> visitor);
    void setPlayer(std::shared_ptr<Player> inpPlayerPtr);
    void removePlayer();
    // void getPlayerId() const;
    void doNextMove();
    Token& operator=(const Token& inp) = delete;
    Token(const Token& inp) = delete;
signals:
    void startGame();
public slots:

private slots:
    void handlePlayerDiceClick();

private:
    virtual void implementMovement(const int& inp, const QString& message);
    virtual void implementGoToDestination(const int& destination, const bool& startBonus,
                         const QString& message, const bool& forwardDirectionFlag);
    virtual void implementGoToPrison(const int& roundNumber);
    virtual void implementMovePayment(const double& amountPerMove, const QString& playerMessage);

    int current_position_m;
    static int max_position_m;
    std::shared_ptr<Player> player_m;
    const int tokenId;
    std::vector<std::shared_ptr<BoardPlace>>& placesVectorReference;
    bool requestForMovementFlag;
    static bool startGameFlag;
};

#endif // TOKEN_H
