#include "centralWidget.h"
#include <QString>


centralWidget::centralWidget(QWidget *parent) :
    QWidget(parent)
{
    // creating messages display
    messagesViewer = new QPlainTextEdit;
    messagesViewer -> setMaximumBlockCount(static_cast<int>(settings::MESSAGE_HISTORY));
    messagesViewer -> setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    messagesViewer -> setMinimumSize(200,300);

    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout ->addWidget(messagesViewer);
    // creating widgets from right vertical layout
    QVBoxLayout* verticalLayout = new QVBoxLayout;
    QLabel* roundText = new QLabel;
    roundText -> setText(QString("ROUND NR:"));
    QFont labelFont;
    labelFont.setPointSize(12);
    roundText ->setFont(labelFont);
    verticalLayout -> addWidget(roundText);
    roundDisplayLabel = new QLabel;
    roundDisplayLabel ->setText("0");
    verticalLayout -> addWidget(roundDisplayLabel);
    QPushButton* diceButton = new QPushButton;
    QObject::connect(diceButton, SIGNAL(clicked()), this, SLOT(handleDice()));
    verticalLayout ->addWidget(diceButton);
    topLayout ->addLayout(verticalLayout);

    QHBoxLayout* bottomLayout = new QHBoxLayout;
    QVBoxLayout * propertyLayout = new QVBoxLayout;
    QVBoxLayout * moneyLayout = new QVBoxLayout;
    QVBoxLayout * prisonFreeLayout = new QVBoxLayout;
    QLabel* propertyDisplayLabel = new QLabel;
    QLabel* moneyDisplayLabel = new QLabel;
    QLabel* prisonFreeDisplayLabel = new QLabel;
    QLabel* propertyLabel = new QLabel;
    propertyLabel ->setText("YOUR PROPERTY");
    QLabel* moneyLabel = new QLabel;
    moneyLabel ->setText("CURRENT CASH");
    QLabel* prisonLabel = new QLabel;
    prisonLabel ->setText("PRISON FREE CARDS:");
    propertyLayout ->addWidget(propertyLabel);
    propertyLayout ->addWidget(propertyDisplayLabel);
    moneyLayout -> addWidget(moneyLabel);
    moneyLayout ->addWidget(moneyDisplayLabel);
    prisonFreeLayout ->addWidget(prisonLabel);
    prisonFreeLayout ->addWidget(prisonFreeDisplayLabel);
    bottomLayout ->addLayout(propertyLayout);
    bottomLayout ->addLayout(moneyLayout);
    bottomLayout ->addLayout(prisonFreeLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout ->addLayout(topLayout);
    mainLayout ->addLayout(bottomLayout);
    setLayout(mainLayout);
}

void centralWidget::displayRound(int round)
{
    QString tmp;
    tmp.number(round);
    roundDisplayLabel ->setText(tmp);
}

void centralWidget::displayMessage(const QString& message)
{
    messagesViewer ->appendPlainText(message);
}

void centralWidget::displayWealth(double inp)
{
    QString tmp;
    tmp.number(inp);
    propertyDisplayLabel ->setText(tmp);
}

void centralWidget::displayCash(double inp)
{
    QString tmp;
    tmp.number(inp);
    moneyDisplayLabel ->setText(tmp);
}
void centralWidget::displayPrisonCards(int inp)
{
    QString tmp;
    tmp.number(inp);
    prisonFreeDisplayLabel ->setText(tmp);
}

void centralWidget::handleDice()
{
    emit dice();
}
