#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class mainWidget; // forward declaration

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private:
mainWidget * window;

};

#endif // MAINWINDOW_H
