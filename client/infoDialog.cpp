#include "infoDialog.h"
#include <QtGui>

infoDialog::infoDialog(QWidget *parent) :
    QDialog(parent)
{
    okButton = new QPushButton;
    okButton -> setText(tr("OK"));
    okButton -> setDefault(true);
    okButton -> setEnabled(true);

    messageLabel = new QLabel;

    deadline = new QTimer;
    bool conn1 = QObject::connect(deadline, SIGNAL(timeout()), this, SLOT(handleDeadline()));
    bool conn2 = QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(handleOkButton()));
    Q_ASSERT(conn1);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout -> addWidget(messageLabel);
    mainLayout -> addWidget(okButton);
    this->setWindowTitle(tr("INFO DIALOG"));
    setLayout(mainLayout);
}
void infoDialog::handleDeadline()
{
    this -> hide();
}

void infoDialog::handleOkButton()
{
    this -> hide();
}

void infoDialog::showInfo(const QString& info)
{
    messageLabel -> setText(info);
    deadline -> setSingleShot(true);
    deadline -> start(5000); // 5s
    this -> show();
    this -> raise();
    this -> activateWindow();
}
