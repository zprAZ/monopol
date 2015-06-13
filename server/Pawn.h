#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include <memory>
#include "visitors/Visitor.h"


class Pawn : public QObject
{
    Q_OBJECT
public:
    explicit Pawn(QObject *parent = 0);
    void goToDestination(const int& destination, const bool& startBonus, const QString& message,
                         const bool& forwardDirectionFlag);
    void move(const int & inp, const QString& message = QString(""));
    int getLastMovement() const;
    bool ifIsValid() const;
    bool ifNotInPrison() const;
    void invalidate();
    virtual void accept(std::unique_ptr<Visitor> visitor) = 0;
    void goToPrison(const int& roundNumber);
    static void updateRoundNumber();
    void payForMoves(const double& amountPerMove, const QString& playerMessage);
signals:

public slots:

protected:
    static int currentRoundNumber;
    bool valid_m = false;
    mutable bool prisonFlag = false;
    int lastPrisonRoundNumber = 0;
    int prisonTime;
    int lastMovement;
private:
    virtual void implementMovement(const int& inp, const QString& message) = 0;
    virtual void implementGoToDestination(const int& destination, const bool& startBonus, const QString& message,
                                          const bool& forwardDirectionFlag) = 0;
    virtual void implementGoToPrison(const int& roundNumber) = 0;
    virtual void implementMovePayment(const double& amountPerMove, const QString& playerMessage) = 0;
};

#endif // PAWN_H
