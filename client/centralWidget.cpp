#include "centralWidget.h"
#include <QString>
#include <QtGui>


centralWidget::centralWidget(QWidget *parent) :
    QWidget(parent)
{
    // creating messages display
    QPlainTextEdit* messagesViewer = new QPlainTextEdit;
    messagesViewer -> setMaximumBlockCount(static_cast<int>(settings::MESSAGE_HISTORY));
    messagesViewer -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    messagesViewer ->setReadOnly(true);
    messagesViewer -> setMinimumSize(600,300);
    QObject::connect(this, SIGNAL(message_s(QString)), messagesViewer, SLOT(appendPlainText(QString)));
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
    QLabel *roundDisplayLabel = new QLabel;
    roundDisplayLabel ->setText("0");
    QObject::connect(this, SIGNAL(round_s(QString)), roundDisplayLabel, SLOT(setText(QString)));
    verticalLayout -> addWidget(roundDisplayLabel);
    verticalLayout ->addStretch();
    QPushButton* diceButton = new QPushButton;
    diceButton ->setText(tr("PLAY DICE"));
    diceButton ->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    QObject::connect(diceButton, SIGNAL(clicked()), this, SLOT(handleDice()));
    verticalLayout ->addWidget(diceButton);
    QGroupBox* rightBox = new QGroupBox;
    rightBox ->setLayout(verticalLayout);
    topLayout ->addWidget(rightBox);

    QHBoxLayout* bottomLayout = new QHBoxLayout;
    QVBoxLayout * propertyLayout = new QVBoxLayout;
    QVBoxLayout * moneyLayout = new QVBoxLayout;
    QVBoxLayout * prisonFreeLayout = new QVBoxLayout;
    QLabel* propertyDisplayLabel = new QLabel();
            propertyDisplayLabel->setText("0");
            bool connected = QObject::connect(this, SIGNAL(wealth_s(QString)), propertyDisplayLabel, SLOT(setText(QString)));
    QLabel* moneyDisplayLabel = new QLabel;
            moneyDisplayLabel ->setText("0");
            bool connected2 = QObject::connect(this, SIGNAL(cash_s(QString)), moneyDisplayLabel, SLOT(setText(QString)));
    QLabel* prisonFreeDisplayLabel = new QLabel;
            prisonFreeDisplayLabel ->setText("0");
            bool connected3 = QObject::connect(this, SIGNAL(prisonCards_s(QString)), prisonFreeDisplayLabel, SLOT(setText(QString)));
    Q_ASSERT(connected);
    Q_ASSERT(connected2);
    Q_ASSERT(connected3);
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
    QGroupBox* group1 = new QGroupBox;
    QGroupBox* group2 = new QGroupBox;
    QGroupBox* group3 = new QGroupBox;
    group1 ->setLayout(propertyLayout);
    group2->setLayout(moneyLayout);
    group3->setLayout(prisonFreeLayout);
    bottomLayout ->addWidget(group1);
    bottomLayout ->addStretch();
    bottomLayout ->addWidget(group2);
    bottomLayout ->addStretch();
    bottomLayout ->addWidget(group3);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout ->addLayout(topLayout);
    mainLayout ->addLayout(bottomLayout);
    setLayout(mainLayout);
}

void centralWidget::displayRound(int round)
{
    QString tmp;

    tmp.setNum(round);
    emit round_s(tmp);
}

void centralWidget::displayMessage(const QString& message)
{
    emit message_s(message);
}

void centralWidget::displayWealth(double inp)
{
    QString tmp;
    tmp.setNum(inp);
    emit wealth_s(tmp);
}

void centralWidget::displayCash(double inp)
{
    QString tmp;
    tmp.setNum(inp);
    emit cash_s(tmp);
}
void centralWidget::displayPrisonCards(int inp)
{
    QString tmp;
    tmp.setNum(inp);
    emit prisonCards_s(tmp);
}

void centralWidget::handleDice()
{
    emit dice_s();
}
