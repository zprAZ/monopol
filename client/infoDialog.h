#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H
#include <QDialog>
#include <QTimer>

class QPushButton;
class QLabel;

class infoDialog : public QDialog
{
    Q_OBJECT
public:
    explicit infoDialog(QWidget *parent = 0);

signals:

public slots:
    void showInfo(const QString& info);

private slots:
    void handleDeadline();
    void handleOkButton();

private:
    QPushButton* okButton;
    QLabel* messageLabel;
    QTimer* deadline;
};

#endif // MESSAGEDIALOG_H
