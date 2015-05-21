#include <QApplication>
#include "mainWindow.h"


int main(int argc, char* tab[])
{
    QApplication app(argc, tab);

    MainWindow*  window = new MainWindow;



    window ->show();

    return app.exec();
}
