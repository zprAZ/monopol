#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QPainter>
#include "boardWidget.h"

class counterWidget : public boardWidget
{
    Q_OBJECT
public:
    explicit counterWidget(const QString& name, int inpId, boardWidget::alignment inpAlign, QWidget *parent = 0);

signals:

public slots:
    void setOwnershipFlag(int id, bool flag, playerColor inp);
    void setMortgageFlag(int id, bool inp);

private:
    virtual void paintItself(QPainter& inp);
    virtual int getOwnerFrameWidth() const {return 0;};
    bool mortgage_m;
    playerColor frameColor_m;
    bool ownerPresent_m;
    static const int frameWidth_m = 10;
    QString name_m;
};

#endif // COUNTERWIDGET_H
