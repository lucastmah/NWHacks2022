#include "piechartwidget.h"
#include <QPainter>
#include "day.h"

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget{parent}
{

}

void PieChartWidget::setData(Day* target)
{
    // Grouped Implementation
    // Array Legend: [0] Sleep, [1] Work, [2] Eating, [3] School, [4] Recreation
    int categories = 5;
    QVector<int> tempTotals(categories, 0);

    // Tallies minutes for each category, updates values values
    for (unsigned long long i=0; i < target->events.size(); i++)
    {
        int currValue = target->events.at(i)->length;
        if(target->events.at(i)->category.name == "Sleeping") {
            tempTotals[0] += currValue;
        }
        else if(target->events.at(i)->category.name == "Working") {
            tempTotals[1] += currValue;

        }
        else if(target->events.at(i)->category.name == "Eating") {
            tempTotals[2] += currValue;
        }
        else if(target->events.at(i)->category.name == "School") {
            tempTotals[3] += currValue;
        }
        else {
            tempTotals[4] += currValue;

        }
    }
    totals = tempTotals;
    qvColors = {Qt::red, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta};
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
