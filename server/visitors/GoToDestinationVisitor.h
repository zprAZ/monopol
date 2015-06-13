#ifndef GOVISITOR_H
#define GOVISITOR_H

#include <memory>
#include <string>
#include "PawnVisitor.h"
#include <QString>

class GoToDestinationVisitor : public PawnVisitor
{
public:
    GoToDestinationVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    static std::unique_ptr<Visitor>  createGoVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    void setStartBonus(const bool& inp);
    void setDestination(const int& inp);
    void setDisplayMessage(const QString& message);
    void setDirectionFlag(const bool& dirFlag);
    void init(const int& destination, const bool& startBonus = true,
              const QString& message = QString(""), bool forwardDirectionFlag = true);
private:
    bool startBonus;
    int destination;
    bool forwardDirectionFlag; // if true then forward
    QString message;
};

#endif // GOVISITOR_H
