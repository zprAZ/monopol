#include "railwayWidget.h"
#include <QPainter>

const QString railwayWidget::railwayText = QString("RAILWAY");

railwayWidget::railwayWidget(int inpId, const QString &name, boardWidget::alignment inpAlign, QWidget *parent) :
    boardWidget(inpId, inpAlign, parent), name_m(name)
{
    int width = static_cast<double>(windowSize::RECTANGLE_WIDTH);
    int height = static_cast<double>(windowSize::RECTANGLE_HEIGHT);
    polygon_m.push_back(QPoint(static_cast<int>(90.0/100.0*width),
                               static_cast<int>(50.0/200.0*height))); // top right corner of locomotive
    polygon_m.push_back(QPoint(static_cast<int>(90.0/100.0*width),
                               static_cast<int>(140.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(25.0/100.0*width),
                               static_cast<int>(140.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(25.0/100.0*width),
                               static_cast<int>(150.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(1.0/100.0*width),
                               static_cast<int>(150.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(15.0/100.0*width),
                               static_cast<int>(140.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(5.0/100.0*width),
                               static_cast<int>(140.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(5.0/100.0*width),
                               static_cast<int>(90.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(15.0/100.0*width),
                               static_cast<int>(90.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(5.0/100.0*width),
                               static_cast<int>(70.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(35.0/100.0*width),
                               static_cast<int>(70.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(25.0/100.0*width),
                               static_cast<int>(90.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(50.0/100.0*width),
                               static_cast<int>(90.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(50.0/100.0*width),
                               static_cast<int>(50.0/200.0*height)));
    polygon_m.push_back(QPoint(static_cast<int>(90.0/100.0*width),
                               static_cast<int>(50.0/200.0*height))); // top right corner of locomotive
}


void railwayWidget::paintItself(QPainter& inp)
{
    inp.save();
    int w_width = static_cast<int>(windowSize::RECTANGLE_WIDTH);
    int w_height = static_cast<int>(windowSize::RECTANGLE_HEIGHT);
    // first we need to draw owner frame
    inp.setBrush(QBrush(Qt::NoBrush));
    if(ownerPresent_m) inp.setBrush(QBrush(playerColor2QColor(frameColor_m), Qt::Dense5Pattern));
    if(mortgage_m) inp.setBrush(QBrush(Qt::gray, Qt::Dense5Pattern));
    inp.drawRect(0, 0, w_width, w_height); // outer rectangle
    inp.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    inp.drawRect(frameWidth_m, frameWidth_m, w_width-2*frameWidth_m,
                w_height - 2*frameWidth_m);
        inp.drawRect(QRect(0,0,w_width, w_height));
        inp.drawText(QRect(5,5,w_width - 10,w_height/8),name_m, QTextOption(Qt::AlignTop |
                                                                 Qt::AlignHCenter));
        inp.drawLine(QPoint(0,w_height/6),QPoint(w_width,w_height/6));
        inp.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        inp.drawPolygon(polygon_m);
        inp.drawEllipse(w_width*0.3, w_height*0.7, w_height*0.1, w_height*0.1);
        inp.drawEllipse(w_width*0.7, w_height*0.7, w_height*0.1, w_height*0.1);
        inp.drawText(QRect(5, 17/20*w_height,w_width-10,3/20*w_height),
                     railwayText, QTextOption(Qt::AlignBottom | Qt::AlignHCenter));
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
