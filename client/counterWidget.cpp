#include "counterWidget.h"
#include <QPainter>

counterWidget::counterWidget(const QString &name, int inpId, alignment inpAlign, QWidget *parent) :
    boardWidget(inpId, inpAlign, parent), name_m(name)
{
    mortgage_m = false;
    ownerPresent_m = false;
    frameColor_m = playerColor::NO_COLOR;
}

void counterWidget::setOwnershipFlag(int id, bool flag, boardWidget::playerColor inp)
{
    if(id == id_m)
    {
    ownerPresent_m = flag;
    frameColor_m = inp;
    repaint();
    }
}

void counterWidget::setMortgageFlag(int id, bool inp)
{
    if(id == id_m)
    {
    mortgage_m = inp;
    repaint();
    }
}

void counterWidget::paintItself(QPainter& inp)
{
    inp.save();
        int w_width = inp.window().width();
        int w_height = inp.window().height();
        // first let's draw ownership
        inp.setBrush(QBrush(Qt::NoBrush));
        if(ownerPresent_m) inp.setBrush(QBrush(playerColor2QColor(frameColor_m), Qt::Dense5Pattern));
        if(mortgage_m) inp.setBrush(QBrush(Qt::gray, Qt::Dense5Pattern));
        inp.drawRect(0, 0, w_width, w_height); // outer rectangle
        // now we need to draw counter pattern
        inp.setBrush(QBrush(Qt::blue, Qt::VerPattern));
        QRect patternRectangle(frameWidth_m, frameWidth_m, w_width- 2*frameWidth_m,
                        w_height - 2*frameWidth_m);
        inp.drawRect(patternRectangle);
        // now we need to draw name
        inp.drawText(patternRectangle, name_m, QTextOption(Qt::AlignTop| Qt::AlignHCenter));
    inp.restore();
}















