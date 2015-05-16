#include "cornerWidget.h"
#include <QPainter>

cornerWidget::cornerWidget(int id, const QString& inpText, boardWidget::alignment align, QWidget *parent) :
    boardWidget(id, align, parent)
{
    setName(inpText);
}
void cornerWidget::paintItself(QPainter& painter)
{
    QRect area = painter.window();
    painter.save();
        painter.setBrush(QBrush(Qt::gray, Qt::Dense6Pattern));
        painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
        painter.drawText(area, name_m, QTextOption(Qt::AlignCenter));
    painter.restore();
}

int cornerWidget::getOwnerFrameWidth() const
{
    return 0; // corner widget does not belong to anyone
}

void cornerWidget::setName(const QString& inp)
{
    name_m = inp;
}




