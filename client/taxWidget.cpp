#include "taxWidget.h"
#include <QPainter>
#include <QFont>

taxWidget::taxWidget(int value, const QString &name, int inpId, boardWidget::alignment inpAlign, QWidget *parent) :
    boardWidget(inpId, inpAlign, parent),
    name_m(name), value_m(value)
{
}

void taxWidget::paintItself(QPainter& inp)
{
    inp.save();
        inp.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        inp.drawRect(inp.window());
        inp.setPen(QPen(Qt::white));
        inp.drawText(inp.window(), name_m, QTextOption(Qt::AlignHCenter | Qt::AlignTop));
        inp.drawText(inp.window(), QString(value_m) + QString("$"),
                     QTextOption(Qt::AlignBottom | Qt::AlignHCenter));
        QFont dolarFont;
        dolarFont.setPointSize(30);
        inp.setFont(QFont(dolarFont));
        inp.drawText(inp.window(),QString("$"), QTextOption(Qt::AlignCenter));
    inp.restore();
}

