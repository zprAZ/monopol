#ifndef BOARD_WIDGET_H
#define BOARD_WIDGET_H

#include <QWidget>
#include <QLinkedList>
#include <QColor>
#include <QString>

class boardWidget : public QWidget
{
    Q_OBJECT
public:
    enum class playerColor:int {RED, GREEN, BLUE, YELLOW, NO_COLOR};
    enum class alignment: int {NOALIGNMENT = 0, BOTTOM = 1, TOP = 2, LEFT = 3, RIGHT = 4};
    enum class windowSize: int {SQUARED = 200, RECTANGLE_WIDTH = 100, RECTANGLE_HEIGHT = 200};
    explicit boardWidget(int inpId, boardWidget::alignment inpAlign, QWidget *parent = 0);
    QColor playerColor2QColor(const playerColor& inp) const;
    QSize sizeHint() const;
    int getId() const;
    void setHint(const QString& inp){hint_m = inp;}
signals:

public slots:
    void tokenIsEntering(int id, boardWidget::playerColor inp);
    void tokenIsLeaving(int id, boardWidget::playerColor inp);
    void displayHint();
protected:
    void paintEvent(QPaintEvent *);
    const alignment align_m;
    const int id_m;
    QString hint_m;
    QLinkedList<playerColor> players_m;
private:
    virtual void paintItself(QPainter& inp) = 0;
    virtual int getOwnerFrameWidth() const = 0;


    static const int pawnSize = 10;
};

#endif // BOARD_WIDGET_H
