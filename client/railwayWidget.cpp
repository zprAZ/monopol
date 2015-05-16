#include "railwayWidget.h"
#include <QPainter>

const QString railwayWidget::railwayText = QString("RAILWAY");

railwayWidget::railwayWidget(int inpId, const QString &name, boardWidget::alignment inpAlign, QWidget *parent) :
    boardWidget(inpId, inpAlign, parent), name_m(name)
{
    polygon_m.push_back(QPoint(90,50)); // top right corner of locomotive
    polygon_m.push_back(QPoint(90,140));
    polygon_m.push_back(QPoint(25, 140));
    polygon_m.push_back(QPoint(25,150));
    polygon_m.push_back(QPoint(1,150));
    polygon_m.push_back(QPoint(15,140));
    polygon_m.push_back(QPoint(5,140));
    polygon_m.push_back(QPoint(5,90));
    polygon_m.push_back(QPoint(15,90));
    polygon_m.push_back(QPoint(5,70));
    polygon_m.push_back(QPoint(35,70));
    polygon_m.push_back(QPoint(25,90));
    polygon_m.push_back(QPoint(50,90));
    polygon_m.push_back(QPoint(50,50));
    polygon_m.push_back(QPoint(90,50)); // top right corner of locomotive
}


void railwayWidget::paintItself(QPainter& inp)
{
    inp.save();
    int w_width = inp.window().width();
    int w_height = inp.window().height();
    // first we need to draw owner frame
    inp.setBrush(QBrush(Qt::NoBrush));
    if(ownerPresent_m) inp.setBrush(QBrush(playerColor2QColor(frameColor_m), Qt::Dense5Pattern));
    if(mortgage_m) inp.setBrush(QBrush(Qt::gray, Qt::Dense5Pattern));
    inp.drawRect(0, 0, w_width, w_height); // outer rectangle
    inp.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    inp.drawRect(frameWidth_m, frameWidth_m, w_width-frameWidth_m,
                w_height - frameWidth_m);
        inp.drawRect(inp.window());
        inp.drawText(QRect(5,5,90,25),name_m, QTextOption(Qt::AlignTop));
        inp.drawLine(QPoint(0,30),QPoint(100,30));
        inp.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        inp.drawPolygon(polygon_m);
        inp.drawText(QRect(5,170,95,25), railwayText, QTextOption(Qt::AlignBottom));
    inp.restore();
}

int railwayWidget::getOwnerFrameWidth() const
{
    return frameWidth_m;
}

void railwayWidget::setOwnershipFlag(int id, bool flag, playerColor inp)
{
    if(id == id_m)
    {
    ownerPresent_m = flag;
    frameColor_m = inp;
    repaint();
    }
}

void railwayWidget::setMortgageFlag(int id, bool inp)
{
    if(id == id_m)
    {
    mortgage_m = inp;
    repaint();
    }
}
