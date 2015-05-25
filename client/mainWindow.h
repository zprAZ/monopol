#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class IpSettingsDialog;
class questionDialog;
class infoDialog;
class mainWidget; // forward declaration
class ServerConnector;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent* event);

signals:

public slots:

private slots:
    void connectToServer();
    void disconnectFromServer();
    void setServerSettings();
    void about();
    void closeApplication();
    void displayErrorMessage(const QString& error);

private:
    void createActions();
    void createMenus();
    void createStatusBar();


    mainWidget * window;

    QAction* aboutAction;
    QAction* connectAction;
    QAction* disconnectAction;
    QAction* setServerSettingsAction;
    QAction* exitAction;

    QMenu* serverMenu;
    QMenu* connectionMenu;
    QMenu* applicationMenu;
    QMenu* helpMenu;

    QString ipAddress;
    int portNumber;
    questionDialog* askQuestion = nullptr;
    infoDialog* showInfo = nullptr;
    ServerConnector* tcpClient;
};

#endif // MAINWINDOW_H
