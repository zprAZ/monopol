#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtGui>
#include "boardWidget.h"
#include "centralWidget.h"
#include "chanceWidget.h"
#include "cityWidget.h"
#include "cornerWidget.h"
#include "railwayWidget.h"
#include "taxWidget.h"
#include "counterWidget.h"

class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);

signals:
    void dice_s();
    void tokenEntering_s(int placeId, boardWidget::playerColor color);
    void tokenLeaving_s(int placeId, boardWidget::playerColor color);
    void round_s(int);
    void sendMessage_s(const QString& message);
    void wealth_s(double);
    void cash_s(double);
    void prisonCards_s(int);
    void house_s(int id, bool inp);
    void deleteHouses_s(int id);
    void hotel_s(int id, bool inp);
    void setOwnership_s(int id, bool flag, boardWidget::playerColor color);
    void setMortgage_s(int id, bool inp);
public slots:
    void tokenIsLeaving(int placeId, int playerId);
    void tokenIsEntering(int placeId, int playerId);
    void displayRound(int round);
    void displayMessage(const QString& message);
    void displayWealth(double inp);
    void displayCash(double inp);
    void displayPrisonCards(int inp);
    void doHouse(int id, bool inp);
    void deleteAllHouses(int id);
    void doHotel(int id, bool inp);
    void setOwnershipFlag(int id, bool flag,int  playerNumber);
    void setMortgageFlag(int id, bool inp);
private:
    boardWidget::playerColor playerId2color(int playerId);

};

#endif // MAINWIDGET_H
