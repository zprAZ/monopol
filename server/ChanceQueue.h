#ifndef CHANCEQUEUE_H
#define CHANCEQUEUE_H

#include <QObject>
#include <memory>
#include "visitors/Visitor.h"

class ChanceQueue : public QObject
{
    Q_OBJECT
public:
   explicit ChanceQueue(QObject *parent = 0);
    std::unique_ptr<Visitor> getVisitor();
    void shuffle();
signals:
public slots:

private:
    std::vector< std::unique_ptr<Visitor> > visitors;
    std::vector< std::unique_ptr<Visitor> >::const_iterator currentPosition;
};

#endif // CHANCEQUEUE_H
