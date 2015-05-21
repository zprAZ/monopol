#include "boardWidget.h"
#include <QTransform>
#include <QPainter>
#include <QPen>
#include <QtGui>

boardWidget::boardWidget(int inpId, alignment inpAlign, QWidget *parent) :
    QWidget(parent), id_m(inpId), align_m(inpAlign)
{
    setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    if(inpAlign != alignment::NOALIGNMENT)
    {
        switch(inpAlign)
        {
        case alignment::BOTTOM:
        case alignment::TOP:
        setMinimumSize(static_cast<int>(windowSize::RECTANGLE_WIDTH),
                   static_cast<int>(windowSize::RECTANGLE_HEIGHT));
        break;
        case alignment::RIGHT:
        case alignment::LEFT:
        setMinimumSize(static_cast<int>(windowSize::RECTANGLE_HEIGHT),
                       static_cast<int>(windowSize::RECTANGLE_WIDTH));
        break;
        }

    }else
    {
        setMinimumSize(static_cast<int>(windowSize::SQUARED),static_cast<int>(windowSize::SQUARED));
    }

}

int boardWidget::getId() const
{
    return id_m;
}

void boardWidget::tokenIsEntering(int id, boardWidget::playerColor inp)
{
    if(id == id_m)
    {
    players_m.push_back(inp);
    repaint();
    }
}

void boardWidget::tokenIsLeaving(int id, boardWidget::playerColor inp)
{
    if(id == id_m)
    {
        if(!players_m.removeOne(inp))
        {
            // ZCU_TODO
        }
    repaint();
    }
}

void boardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
    painter.drawRect(2,2, width() -2, height() -2);
    painter.save();
    QTransform transformation; // transformation from logical coord. to physical coord;
    double scaleX = static_cast<double>(windowSize::RECTANGLE_WIDTH)/
            static_cast<double>(windowSize::RECTANGLE_HEIGHT);
            //painter.window().width()/static_cast<int>(windowSize::RECTANGLE_WIDTH);
    double scaleY = 1/scaleX;//static_cast<int>(windowSize::RECTANGLE_HEIGHT)/painter.window().height();
    switch(align_m)
    {
        case alignment::NOALIGNMENT:
            //transformation.translate()
        case alignment::BOTTOM:
            transformation.rotate(0.0);
            break;
        case alignment::LEFT:
            transformation.scale(scaleX, scaleY);
            transformation.translate(static_cast<int>(windowSize::RECTANGLE_WIDTH)/2,
                                     static_cast<int>(windowSize::RECTANGLE_HEIGHT)/2);
            transformation.rotate(+90.0);
            transformation.translate(-static_cast<int>(windowSize::RECTANGLE_WIDTH),
                                     -static_cast<int>(windowSize::RECTANGLE_HEIGHT)*3/4);
            break;
        case alignment::TOP:
        transformation.translate(static_cast<int>(windowSize::RECTANGLE_WIDTH)/2,
                                 static_cast<int>(windowSize::RECTANGLE_HEIGHT)/2);
            transformation.rotate(+180.0);
            transformation.translate(-static_cast<int>(windowSize::RECTANGLE_WIDTH)/2,
                                    -static_cast<int>(windowSize::RECTANGLE_HEIGHT)/2 );
            break;
        case alignment::RIGHT:
            transformation.scale(scaleX, scaleY);
            transformation.translate(static_cast<int>(windowSize::RECTANGLE_WIDTH)/2,
                                     static_cast<int>(windowSize::RECTANGLE_HEIGHT)/2);
            transformation.rotate(-90.0);
            transformation.translate(0,-static_cast<int>(windowSize::RECTANGLE_HEIGHT)/4);
            break;
    }

    switch(align_m)
    {
    case alignment::NOALIGNMENT:
        painter.setWindow(0, 0, static_cast<int>(windowSize::SQUARED), static_cast<int>(windowSize::SQUARED));
        break;
    case alignment::BOTTOM:
    case alignment::TOP:
        painter.setWindow(0, 0, static_cast<int>(windowSize::RECTANGLE_WIDTH),
                          static_cast<int>(windowSize::RECTANGLE_HEIGHT));
        break;
    case alignment::RIGHT:
    case alignment::LEFT:
        painter.setWindow(0, 0, static_cast<int>(windowSize::RECTANGLE_WIDTH),
                          static_cast<int>(windowSize::RECTANGLE_HEIGHT));
        break;
    }

    painter.setWorldTransform(transformation);
    paintItself(painter); // virtual function
    painter.restore();
    // we need to only draw players tokens if they are present :-)
    // we need to take alignment into account while drawing tokens.

    int counter = 0;
    for(QLinkedList<playerColor>::const_iterator iter = players_m.begin(); iter != players_m.end(); ++iter)
    {
        switch(*iter)
        {
            case playerColor::NO_COLOR:
                break;
            case playerColor::BLUE:
                painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
                break;
            case playerColor::GREEN:
                painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
                break;
            case playerColor::RED:
                painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
            case playerColor::YELLOW:
                painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        }
        if(align_m == alignment::NOALIGNMENT)
        {
            int width = painter.window().width();
            switch(counter)
            {
            case 0:
                painter.drawEllipse(QPoint(width/4, width/4), pawnSize, pawnSize);
                break;
            case 1:
                painter.drawEllipse(QPoint(width/4*3,width/4), pawnSize, pawnSize);
                break;
            case 2:
                painter.drawEllipse(QPoint(width/4,width/4*3), pawnSize, pawnSize);
                break;
            case 3:
                painter.drawEllipse(QPoint(width/4*3,width/4*3), pawnSize, pawnSize);
                break;
            }
        }else
        {
            switch(align_m)
            {
            case alignment::BOTTOM:
                painter.drawEllipse(QPoint(painter.window().width()/2,
                                       painter.window().height()
                                       - getOwnerFrameWidth() - (2 * counter + 1) * pawnSize),
                                pawnSize, pawnSize);
            break;
            case alignment::TOP:
                painter.drawEllipse(QPoint(painter.window().width()/2,
                                           + getOwnerFrameWidth() + (2 * counter + 1) * pawnSize),
                                    pawnSize, pawnSize);
            break;
            case alignment::RIGHT:
                painter.drawEllipse(QPoint(painter.window().width()
                                           - getOwnerFrameWidth() - (2 * counter + 1) * pawnSize,
                                        painter.window().height()/2),
                                    pawnSize, pawnSize);
            break;
            case alignment::LEFT:
                painter.drawEllipse(QPoint(getOwnerFrameWidth() + (2 * counter + 1) * pawnSize,
                                        painter.window().height()/2),
                                    pawnSize, pawnSize);
            break;
            }
        }
    ++counter;
    } // end for loop

}

QSize boardWidget::sizeHint() const
{
    switch(align_m)
    {
    case alignment::NOALIGNMENT:
        return QSize(static_cast<int>(windowSize::SQUARED), static_cast<int>(windowSize::SQUARED));
        break;
    case alignment::TOP:
    case alignment::BOTTOM:
        return QSize(static_cast<int>(windowSize::RECTANGLE_WIDTH), static_cast<int>(windowSize::RECTANGLE_HEIGHT));
        break;
    case alignment::LEFT:
    case alignment::RIGHT:
        return QSize(static_cast<int>(windowSize::RECTANGLE_HEIGHT), static_cast<int>(windowSize::RECTANGLE_WIDTH));
        break;
    }
    //return QSize(static_cast<int>(windowSize::RECTANGLE_WIDTH), static_cast<int>(windowSize::RECTANGLE_HEIGHT));
}

void boardWidget::displayHint()
{
    // ZCU_TODO we need to create hint dialog which will display info about particular widget.
}

QColor boardWidget::playerColor2QColor(const playerColor& inp) const
{
    switch(inp)
    {
    case playerColor::NO_COLOR:
        return Qt::white;
        break;
    case playerColor::BLUE:
        return Qt::blue;
        break;
    case playerColor::GREEN:
        return Qt::green;
        break;
    case playerColor::RED:
        return Qt::red;
        break;
    case playerColor::YELLOW:
        return Qt::yellow;
        break;
    }
    return QColor();
}
