#ifndef CITYWIDGET_H
#define CITYWIDGET_H

#include<QString>

#include "boardWidget.h"

class cityWidget : public boardWidget
{
        Q_OBJECT
public:
    cityWidget(int inpId, const QString& inpName = QString(),
               boardWidget::alignment align = alignment::BOTTOM, QWidget *parent = 0);
    void setName(const QString& inp);
    enum class drawParams:int {
        NAME_RECT_HEIGHT = static_cast<int>(30./200.0*static_cast<double>(windowSize::RECTANGLE_HEIGHT)),
        HOUSE_WIDTH = static_cast<int>(30.0/100.0*static_cast<double>(windowSize::RECTANGLE_WIDTH)),
        HOUSE_HEIGHT = static_cast<int>(25.0/200.0*static_cast<double>(windowSize::RECTANGLE_HEIGHT)),
        HOTEL_WIDTH = static_cast<int>(50.0/100.0*static_cast<double>(windowSize::RECTANGLE_WIDTH)),
        HOTEL_HEIGHT = static_cast<int>(60.0/200.0*static_cast<double>(windowSize::RECTANGLE_HEIGHT))
        // ZCU_TODO
        // arbirary numbers should be replaced by window size depending variables
    };
    void setCityColor(const QColor& inp);
signals:

public slots:
    void doHouse(int id, bool inp);
    void deleteAllHouses(int id);
    void doHotel(int id, bool inp);
    void setOwnershipFlag(int id, bool flag, boardWidget::playerColor inp);
    void setMortgageFlag(int id, bool inp);
private:
    virtual void paintItself(QPainter& inp);
    virtual int getOwnerFrameWidth() const;
    int numberOfHouses_m;
    bool hotel_m;
    bool ownerPresent_m;
    playerColor frameColor_m;
    bool mortgage_m;
    static const int frameWidth_m = 10;
    static const int maxHouses_m = 4;
    QColor cityColor_m;
    QString name_m;
};

#endif // CITYWIDGET_H
