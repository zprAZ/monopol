#include "mainWindow.h"
#include "mainWidget.h"
#include "ipsettingsDialog.h"
#include "questionDialog.h"
#include "infoDialog.h"
#include "ServerConnector.h"

#include <QtGui>
#include <QScopedPointer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ipAddress = QString("127.0.0.1");
    portNumber = 6178;

    mainWidget* window = new mainWidget;
    QScrollArea* area = new QScrollArea;
    area ->setWidget(window);
    area->viewport()->setBackgroundRole(QPalette::Mid);
    area->viewport()->setAutoFillBackground(true);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(area);

    this->createActions();
    this->createMenus();
    showInfo = new infoDialog(this);
    askQuestion = new questionDialog(this);
    tcpClient = new ServerConnector(this);
    bool c1 = connect(tcpClient, SIGNAL(displayMessageSignal(QString)), window, SLOT(displayMessage(QString)));
    bool c2 = connect(tcpClient, SIGNAL(displayCashSignal(double)), window, SLOT(displayCash(double)));
    bool c3 = connect(tcpClient, SIGNAL(displayPrisonCardsSignal(int)), window, SLOT(displayPrisonCards(int)));
    bool c4 = connect(tcpClient, SIGNAL(displayRoundSignal(int)), window, SLOT(displayRound(int)));
    bool c5 = connect(tcpClient, SIGNAL(displayWealthSignal(double)), window, SLOT(displayWealth(double)));
    bool c6 = connect(tcpClient, SIGNAL(doHotelSignal(int,bool)), window, SLOT(doHotel(int,bool)));
    bool c7 = connect(tcpClient, SIGNAL(doHouseSignal(int,bool)), window, SLOT(doHouse(int,bool)));
    bool c8 = connect(tcpClient, SIGNAL(setMortgageFlagSignal(int,bool)), window, SLOT(setMortgageFlag(int,bool)));
    bool c9 = connect(tcpClient, SIGNAL(setOwnershipFlagSignal(int,bool,int)),
                      window, SLOT(setOwnershipFlag(int,bool,int)));
    bool c10 = connect(tcpClient, SIGNAL(tokenIsEnteringSignal(int,int)), window, SLOT(tokenIsEntering(int,int)));
    bool c11 = connect(tcpClient, SIGNAL(tokenIsLeavingSignal(int,int)), window, SLOT(tokenIsLeaving(int,int)));
    bool c12 = connect(tcpClient, SIGNAL(deleteAllHousesSignal(int)), window, SLOT(deleteAllHouses(int)));
    bool c13 = connect(tcpClient, SIGNAL(errorSignal(QString)), this, SLOT(displayErrorMessage(QString)));
    bool c14 = connect(tcpClient, SIGNAL(askQuestionSignal(int,QString)), askQuestion, SLOT(setQuestion(int,QString)));
    bool c15 = connect(tcpClient, SIGNAL(showInfoSignal(QString)), showInfo, SLOT(showInfo(QString)));
    bool c16 = connect(askQuestion, SIGNAL(responseSignal(int,bool)), tcpClient, SLOT(sendResponse(int,bool)));
    Q_ASSERT(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10
             && c11 && c12 && c13 && c14 && c15 && c16);

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

void MainWindow::createActions()
{
    aboutAction = new QAction(tr("ABOUT"), this);
    aboutAction -> setStatusTip(tr("click to receive information about this software"));
    QObject::connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    connectAction = new QAction(tr("CONNECT"), this);
    connectAction ->setStatusTip(tr("connect to game server"));
    QObject::connect(connectAction, SIGNAL(triggered()), this, SLOT(connectToServer()));

    disconnectAction = new QAction(tr("DISCONNECT"), this);
    disconnectAction ->setStatusTip(tr("disconnect from game server"));
    QObject::connect(disconnectAction, SIGNAL(triggered()), this, SLOT(disconnectFromServer()));

    setServerSettingsAction = new QAction(tr("SERVER settings"), this);
    setServerSettingsAction ->setStatusTip(tr("adjust server settings"));
    QObject::connect(setServerSettingsAction, SIGNAL(triggered()), this, SLOT(setServerSettings()));

    exitAction = new QAction(tr("exit"), this);
    exitAction ->setStatusTip(tr("close application"));
    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(closeApplication()));
}

void MainWindow::createMenus()
{
    applicationMenu = menuBar() ->addMenu(tr("application"));
    applicationMenu ->addAction(exitAction);

    connectionMenu = menuBar()->addMenu(tr("connection"));
    connectionMenu ->addAction(connectAction);
    connectionMenu ->addSeparator();
    connectionMenu ->addAction(disconnectAction);
    connectionMenu ->addSeparator();

    serverMenu = menuBar() ->addMenu(tr("server settings"));
    serverMenu ->addAction(setServerSettingsAction);

    menuBar() ->addSeparator();
    helpMenu = menuBar()->addMenu(tr("help"));
    helpMenu ->addAction(aboutAction);
}

void MainWindow::createStatusBar()
{

}

void MainWindow::connectToServer()
{
    tcpClient ->establishConnection(this->ipAddress, this->portNumber);
}

void MainWindow::disconnectFromServer()
{
    tcpClient->closeConnection();
}

void MainWindow::setServerSettings()
{
        QScopedPointer<IpSettingsDialog> dialog(new IpSettingsDialog(ipAddress, portNumber, this));
        dialog->setModal(true);
        if(dialog->exec())
        {
            this->ipAddress = dialog->getIpAddress();
            this->portNumber = dialog ->getPortNumber();
        }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About this application"), tr(""
            "this is a client server application designed for fans of monopoly game"));
}

void MainWindow::closeApplication()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    close();
}

void MainWindow::displayErrorMessage(const QString& error)
{
    QErrorMessage errorDialog(this);
    errorDialog.setModal(true);
    errorDialog.showMessage(error);
    if(errorDialog.exec())
    {
    }
}
