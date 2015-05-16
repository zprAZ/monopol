#ifndef TAXWIDGET_H
#define TAXWIDGET_H

#include "boardWidget.h"
#include<QString>

class taxWidget : public boardWidget
{
    Q_OBJECT
public:
    explicit taxWidget(int value, const QString& name, int inpId,
                       boardWidget::alignment inpAlign, QWidget *parent = 0);

signals:

public slots:

private:
    virtual void paintItself(QPainter& inp);
    virtual int getOwnerFrameWidth() const{return 0;};
    QString name_m;
    int value_m;
};

#endif // TAXWIDGET_H
