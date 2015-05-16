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
        NAME_RECT_HEIGHT = 30,
        HOUSE_WIDTH = 30,
        HOUSE_HEIGHT = 25,
        HOTEL_WIDTH = 70,
        HOTEL_HEIGHT = 60
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
