#ifndef BUYPLACEVISITOR_H
#define BUYPLACEVISITOR_H

#include "PlayerVisitor.h"
#include "places/BoardPlace.h"
#include <memory>
#include <QString>

class BuyPlaceVisitor : public PlayerVisitor
{
public:
    BuyPlaceVisitor();
    virtual std::unique_ptr<Visitor> clone() const;
    virtual void visit(Pawn& inp);
    virtual void visit(Player& inp);
    static std::unique_ptr<Visitor>  createBuyPlaceVisitor();
    void init(const QString& question, std::shared_ptr<BoardPlace> ptr, const double& payment);
    void setQuestion(const QString& question);
    void setPlacePtr(std::shared_ptr<BoardPlace> ptr);

private:
    QString question;
    std::shared_ptr<BoardPlace> placePtr;
    double payment;
};

#endif // BUYPLACEVISITOR_H
