#ifndef RAILWAYWIDGET_H
#define RAILWAYWIDGET_H

#include "boardWidget.h"

#include<QString>
#include<QVector>
#include<QPoint>
#include<QString>

class railwayWidget : public boardWidget
{
    Q_OBJECT
public:
    explicit railwayWidget(int inpId, const QString& name, boardWidget::alignment inpAlign, QWidget *parent = 0);

signals:

public slots:
    void setOwnershipFlag(int id, bool flag, boardWidget::playerColor inp);
    void setMortgageFlag(int id, bool inp);
private:
    virtual void paintItself(QPainter& inp);
    virtual int getOwnerFrameWidth() const;
    QString name_m;
    QVector<QPoint> polygon_m;
    static const QString railwayText;
    bool ownerPresent_m;
    playerColor frameColor_m;
    bool mortgage_m;
    static const int frameWidth_m = 10;
};

#endif // RAILWAYWIDGET_H
