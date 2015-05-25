#include "ipsettingsDialog.h"
#include "ip4Validator.h"
#include <QtGui>

IpSettingsDialog::IpSettingsDialog(const QString ip, int port, QWidget *parent) :
    QDialog(parent)
{
    ipAddressEdit = new QLineEdit;
    ipValidator = new IP4Validator;
    ipAddressEdit ->setValidator(ipValidator);
    ipAddressEdit ->setText(ip);

    ipLabel = new QLabel;
    ipLabel ->setText(tr("IP address"));
    portNumberEdit = new QLineEdit;
    portNumberEdit ->setValidator(new QIntValidator(1024, 49151));
    QString tmp;
    tmp.setNum(port);
    portNumberEdit ->setText(tmp);
    portLabel = new QLabel;
    portLabel ->setText(tr("port"));
    okButton = new QPushButton;
    okButton ->setEnabled(false);
    okButton ->setText(tr("OK"));
    cancelButton = new QPushButton;
    cancelButton ->setDefault(true);
    cancelButton ->setEnabled(true);
    cancelButton ->setText(tr("cancel"));

    bool connection1 = connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    bool connection2 = connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    bool connection3 = connect(ipAddressEdit, SIGNAL(textChanged(QString)), this, SLOT(onChange()));
    bool connection4 = connect(portNumberEdit, SIGNAL(textChanged(QString)), this, SLOT(onChange()));
    Q_ASSERT(connection1 && connection2 && connection3 && connection4);

    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout ->addWidget(ipLabel);
    topLayout ->addWidget(ipAddressEdit);
    QHBoxLayout* middleLayout = new QHBoxLayout;
    middleLayout ->addWidget(portLabel);
    middleLayout ->addWidget(portNumberEdit);
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    bottomLayout ->addWidget(okButton);
    bottomLayout ->addWidget(cancelButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout ->addLayout(topLayout);
    mainLayout ->addLayout(middleLayout);
    mainLayout ->addLayout(bottomLayout);
    setWindowTitle(tr("IP ADDRESS SETTINGS"));
   // this->setModal(true);
    setLayout(mainLayout);

}

void IpSettingsDialog::onChange()
{
    okButton ->setEnabled(ipAddressEdit->hasAcceptableInput()
                          && portNumberEdit ->hasAcceptableInput());
}

QString IpSettingsDialog::getIpAddress() const
{
    return ipAddressEdit ->text();
}
int IpSettingsDialog::getPortNumber() const
{
    QString tmp =portNumberEdit ->text();
    bool ok;
    int retValue = tmp.toInt(&ok);
    if(ok)
    {
        return retValue;
    }else
    {
        return 0;
    }
}
