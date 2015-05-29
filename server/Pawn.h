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
    void go(const int& inp);
    int getLastMovement() const;
    bool ifIsValid() const;
    void invalidate();
    virtual void accept(Visitor& visitor) = 0;
signals:

public slots:

private:
    virtual void implementGo(const int& inp) = 0;
    virtual int implementLastMovement() const = 0;
    virtual bool implementValidation() const = 0;
    virtual bool implementInvalidation() = 0;
};

#endif // PAWN_H
