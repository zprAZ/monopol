#ifndef GOVISITOR_H
#define GOVISITOR_H

#include <memory>
#include <string>
#include "PawnVisitor.h"
#include <QString>

class GoVisitor : public PawnVisitor
{
public:
    GoVisitor();
    static std::unique_ptr<Visitor>  createGoVisitor();
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    void setStartBonus(const bool& inp);
    void setMovement(const int& inp);
    void setDisplayMessage(const QString& message);
    void init(const int& movement, const bool& startBonus = true,
              const QString& message = QString(""));
private:
    bool startBonus;
    int movement;
    QString message;
};

#endif // GOVISITOR_H
