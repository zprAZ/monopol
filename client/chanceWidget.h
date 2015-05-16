#ifndef CHANCEDIALOG_H
#define CHANCEDIALOG_H

#include "boardWidget.h"
#include <QString>

class chanceWidget : public boardWidget
{
    Q_OBJECT
public:
    explicit chanceWidget(int inpId, boardWidget::alignment inpAlign, QWidget *parent = 0);
signals:

public slots:

private:
    virtual void paintItself(QPainter& inp);
    virtual int getOwnerFrameWidth() const;
    static const QString name_m;

};

#endif // CHANCEDIALOG_H
