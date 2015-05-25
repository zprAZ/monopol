#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QDialog>
#include <QTimer>

class QPushButton;
class QLabel;

class questionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit questionDialog(QWidget *parent = 0);

signals:
    void responseSignal(int messageId, bool answer);

public slots:
    void setQuestion(const int id, const QString &question);

private slots:
    void handleDeadline();
    void handleYesButton();
    void handleNoButton();

private:
    QPushButton* acceptButton;
    QPushButton* rejectButton;
    QLabel* message;
    QTimer* deadline;
    int messageId;
};

#endif // QUESTIONDIALOG_H
