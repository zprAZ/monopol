#include "mainWidget.h"


int main(int argc, char* tab[])
{
    QApplication app(argc, tab);

    mainWidget * window = new mainWidget;

    for(int i = 0; i< 39; ++i)
    {
        window ->tokenIsEntering(i,1);
        /*window ->tokenIsEntering(i,2);
        window ->tokenIsEntering(i,3);
        window ->tokenIsEntering(i,4);
    */
    }
    window->displayRound(100);
    window ->displayMessage(QString("MYsdfsdfsndfjslkdjflksfkljsdlkfj"
                                    "sdfsdfsdfsdfsdf\n"
                                    "sdfsdfsdfsdfsdfsd\n"));
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
           tmp.operator +=(QString("A"));
           window ->displayMessage(tmp);
       }

    window ->show();

    return app.exec();
}
