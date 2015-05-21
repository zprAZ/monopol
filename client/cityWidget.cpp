#include "cityWidget.h"
#include <QPainter>
#include <QPolygon>
#include <utility> // std::pair

cityWidget::cityWidget(int inpId, const QString &inpName, alignment align, QWidget *parent):
    boardWidget(inpId, align, parent)
{
    setName(inpName);
    numberOfHouses_m = 0;
    hotel_m = false;
    ownerPresent_m = false;
    frameColor_m = playerColor::NO_COLOR;
    mortgage_m = false;
    cityColor_m = Qt::white;
}

void cityWidget::paintItself(QPainter& inp)
{
    inp.save();
        int w_width = inp.window().width();
        int w_height = inp.window().height();
        // first let's draw ownership
        inp.setBrush(QBrush(Qt::NoBrush));
        if(ownerPresent_m) inp.setBrush(QBrush(playerColor2QColor(frameColor_m), Qt::Dense5Pattern));
        if(mortgage_m) inp.setBrush(QBrush(Qt::gray, Qt::Dense5Pattern));
        inp.drawRect(0,0, w_width, w_height); // outer rectangle
        inp.setBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
        inp.drawRect(frameWidth_m, frameWidth_m, w_width- 2*frameWidth_m,
                    w_height - 2*frameWidth_m);
        // now let's draw city color and name
        inp.setBrush(QBrush(cityColor_m, Qt::SolidPattern));
        QRect nameRectangle(frameWidth_m, frameWidth_m, w_width - 2* frameWidth_m,
                            static_cast<int>(drawParams::NAME_RECT_HEIGHT));
        inp.drawRect(nameRectangle);
        inp.drawText(nameRectangle, name_m, QTextOption(Qt::AlignHCenter));
        // now let's draw houses and hotels
        inp.drawLine(QPoint(frameWidth_m , static_cast<int>(windowSize::RECTANGLE_HEIGHT)/5*3),
                     QPoint(w_width-frameWidth_m, static_cast<int>(windowSize::RECTANGLE_HEIGHT)/5*3));

        int width_ = static_cast<int>(windowSize::RECTANGLE_WIDTH);
        int height_ = static_cast<int>(windowSize::RECTANGLE_HEIGHT);
        if(!hotel_m)
        {
            inp.setBrush(QBrush(Qt::red, Qt::Dense3Pattern));
            std::pair<int, int> houseParams = std::make_pair(static_cast<int>(drawParams::HOUSE_WIDTH),
                                                static_cast<int>(drawParams::HOUSE_HEIGHT));
            for(int i = 0; i < numberOfHouses_m; ++i)
            {
                switch(i)
                {
                case 0:
                    inp.drawRect(15.0/100.0*width_, 45.0/200.0*height_, houseParams.first,
                                 houseParams.second);
                    break;
                case 1:
                    inp.drawRect(55.0/100.0*width_, 45.0/200.0*height_, houseParams.first, houseParams.second);
                    break;
                case 2:
                    inp.drawRect(15.0/100.0*width_, 75.0/200.0*height_, houseParams.first, houseParams.second);
                    break;
                case 3:
                    inp.drawRect(55.0/100.0*width_, 75.0/200.0*height_, houseParams.first, houseParams.second);
                    break;
            }
            }
        }else
        {
            inp.setBrush(QBrush(Qt::yellow, Qt::Dense1Pattern));
            inp.drawRect(static_cast<int>(width_/2.0 - static_cast<double>(drawParams::HOTEL_WIDTH)/2),
                         static_cast<int>(50.0/200.0*height_),
                         static_cast<int>(drawParams::HOTEL_WIDTH),
                         static_cast<int>(drawParams::HOTEL_HEIGHT));
        }
    inp.restore();
}

int cityWidget::getOwnerFrameWidth() const
{
    return frameWidth_m;
}

void cityWidget::doHouse(int id, bool inp)
{
    if(id == id_m)
    if(inp && numberOfHouses_m <= maxHouses_m)
    {
        ++numberOfHouses_m;
    }
    if(!inp) --numberOfHouses_m;
    repaint();
}

void cityWidget::deleteAllHouses(int id)
{
    if(id == id_m)
    {
    numberOfHouses_m = 0;
    repaint();
    }
}

void cityWidget::doHotel(int id, bool inp)
{
    if(id == id_m)
    {
    hotel_m = inp;
    repaint();
    }
}

void cityWidget::setOwnershipFlag(int id, bool flag, boardWidget::playerColor inp)
{
    if(id == id_m)
    {
    ownerPresent_m = flag;
    frameColor_m = inp;
    repaint();
    }
}

void cityWidget::setMortgageFlag(int id, bool inp)
{
    if(id == id_m)
    {
    mortgage_m = inp;
    repaint();
    }
}

void cityWidget::setCityColor(const QColor& inp)
{
    cityColor_m = inp;
}



void cityWidget::setName(const QString& inp)
{
    name_m = inp;
}




