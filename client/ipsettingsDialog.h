#ifndef IPSETTINGSWIDGET_H
#define IPSETTINGSWIDGET_H

#include <QWidget>
#include <QDialog>

class QLineEdit;
class QPushButton;
class QLabel;
class IP4Validator;

class IpSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit IpSettingsDialog(const QString ip = QString(""), int port = 0, QWidget *parent = 0);
    QString getIpAddress() const;
    int getPortNumber() const;

signals:

public slots:

private slots:
    void onChange();
private:
    QLineEdit* ipAddressEdit;
    QLabel* ipLabel;
    QLineEdit* portNumberEdit;
    QLabel* portLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;
    IP4Validator* ipValidator;
};

#endif // IPSETTINGSWIDGET_H
