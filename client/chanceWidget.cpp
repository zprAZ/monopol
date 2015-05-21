#include "chanceWidget.h"
#include <QRect>
#include <QPainter>
#include <QFont>

const QString chanceWidget::name_m = QString("CHANCE");

chanceWidget::chanceWidget(int inpId, boardWidget::alignment inpAlign, QWidget *parent) :
    boardWidget(inpId, inpAlign, parent)
{
}
void chanceWidget::paintItself(QPainter& inp)
{
    inp.save();
    QRect window = inp.window();
        inp.drawText(window, name_m, QTextOption(Qt::AlignTop | Qt::AlignHCenter));
        QTextOption option;
        option.setAlignment(Qt::AlignCenter);
        QFont font;
        font.setBold(true);
        font.setPointSize(static_cast<int>(windowSize::RECTANGLE_HEIGHT)/4);
        inp.setFont(font);
        inp.setPen(QPen(Qt::blue));
        inp.drawText(window, QString("?"), QTextOption(option));
    inp.restore();
}

int chanceWidget::getOwnerFrameWidth() const
{
    return 0;
}
