#include "mainWindow.h"
#include "mainWidget.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mainWidget* window = new mainWidget;
    QScrollArea* area = new QScrollArea;
    area ->setWidget(window);
    area->viewport()->setBackgroundRole(QPalette::Mid);
    area->viewport()->setAutoFillBackground(true);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(area);

    // debuging and testing
    for(int i = 0; i< 39; ++i)
    {
        window ->tokenIsEntering(i,1);
        /*window ->tokenIsEntering(i,2);
        window ->tokenIsEntering(i,3);
        window ->tokenIsEntering(i,4);
    */
    }
    window->displayRound(100);
    window ->displayCash(123);
    window ->displayPrisonCards(1);
    window ->displayWealth(23456778.658768);
 /*   for(int i = 0; i< 39; ++i)
    {
        window ->doHotel(i,true);

    }
*/
    QString tmp;
    for(int i = 0; i< 39; ++i)
       {
           window ->doHouse(i,true);
            window ->doHouse(i,true);
            window ->doHouse(i,true);
           window ->doHouse(i,true);
           tmp.operator +=(QString("_Message_"));
           window ->displayMessage(tmp);
       }
    window->setOwnershipFlag(1,true,1);
    window->setOwnershipFlag(11,true,2);
    window->setOwnershipFlag(23,true,3);
}
