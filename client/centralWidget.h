#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class centralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit centralWidget(QWidget *parent = 0);
    enum class settings:int {MESSAGE_HISTORY = 100};

signals:
    void pause_s(bool flag);
    void dice_s();
    void round_s(QString);
    void message_s(QString);
    void wealth_s(QString);
    void cash_s(QString);
    void prisonCards_s(QString);
public slots:
    void displayRound(int round);
    void displayMessage(const QString& message);
    void displayWealth(double inp);
    void displayCash(double inp);
    void displayPrisonCards(int inp);
private slots:
    void handleDice();
private:
};

#endif // CENTRALWIDGET_H
