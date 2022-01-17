#include "piechartwidget.h"
#include <QPainter>
#include "day.h"
#include <iostream>

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget{parent}
{

}

void PieChartWidget::setData(Day* target)
{
    // Grouped Implementation
    // Array Legend: [0] Sleep, [1] Work, [2] Eating, [3] School, [4] Recreation

    int numCategories = Category::cats.size();
    QVector<int> tempTotals(numCategories, 0);


    for (unsigned long long i=0; i < target->events.size(); i++)
    {
        for (int j=0; j < numCategories; j++){
            if (target->events.at(i)->category.name == Category::cats[j].name) {
                tempTotals[j] += target->events.at(i)->length;
            }
        }
    }

    totals = tempTotals;
    qvColors = {Qt::red, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta, Qt::darkRed,
                Qt::darkBlue,Qt::darkYellow,Qt::darkCyan,Qt::darkMagenta};
    repaint();
    update();
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QRectF size;

    // Divider Size
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    // Setting size
    if (this->height() > this->width())
    {
        size = QRectF(5, 5, this->width()-10, this->width()-10);
    }
    else
    {
        size = QRectF(5, 5, this->height()-10, this->height()-10);
    }

    // Base Circle (Free time)
    painter.setBrush(Qt::green);
    painter.drawPie(size, 0, 360*16);

    double sum = 1440;
    double startAng = 0.0;
    double angle, endAng, percent;

    for (int i=0; i<totals.size(); i++)
    {
        percent = totals[i]/sum;
        angle = percent*360;
        endAng = startAng + angle;
        painter.setBrush(qvColors[i]);
        painter.drawPie(size, startAng*16, angle*16);
        startAng = endAng;
    }
}
