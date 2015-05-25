#include "questionDialog.h"
#include <QtGui>

questionDialog::questionDialog( QWidget *parent) :
    QDialog(parent)
{
    this->messageId = messageId;
    acceptButton = new QPushButton;
    acceptButton ->setText(tr("YES"));
    acceptButton ->setDefault(false);
    rejectButton = new QPushButton;
    rejectButton ->setText(tr("NO"));
    rejectButton ->setDefault(true);

    message = new QLabel;
    deadline = new QTimer(this);

    bool conn1 = QObject::connect(deadline, SIGNAL(timeout()), this, SLOT(handleDeadline()));
    bool conn2 = QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(handleYesButton()));
    bool conn3 = QObject::connect(rejectButton, SIGNAL(clicked()), this, SLOT(handleNoButton()));
    Q_ASSERT(conn1 && conn2 && conn3);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout ->addWidget(acceptButton);
    buttonsLayout ->addWidget(rejectButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout ->addWidget(message);
    mainLayout ->addLayout(buttonsLayout);
    this->setWindowTitle(tr("QUESTION DIALOG"));

    setLayout(mainLayout);
}

void questionDialog::handleDeadline()
{
    // we need to close the dialog. without user input we use default option.
    emit responseSignal(messageId, false);
    this->hide();
}

void questionDialog::setQuestion(const int id, const QString &question)
{
    this->messageId = id;
    message->setText(question);
    deadline ->setSingleShot(true);
    deadline->start(5000); // 5s
    this->show();
    this->raise();
    this->activateWindow();
}

void questionDialog::handleYesButton()
{
    emit responseSignal(messageId, true);
    this->hide();
}

void questionDialog::handleNoButton()
{
    emit responseSignal(messageId, false);
    this->hide();
}
