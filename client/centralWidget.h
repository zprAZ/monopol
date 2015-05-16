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
    void pause(bool flag);
    void dice();

public slots:
    void displayRound(int round);
    void displayMessage(const QString& message);
    void displayWealth(double inp);
    void displayCash(double inp);
    void displayPrisonCards(int inp);
private slots:
    void handleDice();
private:
    QPlainTextEdit* messagesViewer;
    QLabel* roundDisplayLabel;
    QLabel* propertyDisplayLabel;
    QLabel* moneyDisplayLabel;
    QLabel* prisonFreeDisplayLabel;
};

#endif // CENTRALWIDGET_H
