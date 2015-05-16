#ifndef CORNER_WIDGET_H
#define CORNER_WIDGET_H

#include "boardWidget.h"

class cornerWidget : public boardWidget
{
    Q_OBJECT
public:
    explicit cornerWidget(int inpId, const QString& inpName = QString(),
                          boardWidget::alignment align = alignment::NOALIGNMENT, QWidget *parent = 0);
    void setName(const QString& inp);
signals:
public slots:

protected:
    QString name_m;
private:
    virtual void paintItself(QPainter &painter);
    virtual int getOwnerFrameWidth() const;
};

#endif // CORNER_WIDGET_H
