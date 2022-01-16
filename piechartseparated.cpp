#include "piechartseparated.h"
#include <QPainter>
#include "day.h"

PieChartSeparated::PieChartSeparated(QWidget *parent)
    : QWidget{parent}
{

}


void PieChartSeparated::setData(Day* target)
{
    day = target;
    repaint();
    update();
}

void PieChartSeparated::paintEvent(QPaintEvent *)
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


    for (unsigned long long i=0; i < day->events.size(); i++)
    {
        double startAng = day->events[i]->start, endAng = day->events[i]->end, angle;
        angle = endAng-startAng;

        if (day->events[i]->category.name == "Sleeping") {
            painter.setBrush(Qt::red);
        }
        else if (day->events[i]->category.name == "Working") {
            painter.setBrush(Qt::blue);
        }
        else if (day->events[i]->category.name == "Eating") {
            painter.setBrush(Qt::yellow);
        }
        else if (day->events[i]->category.name == "School") {
            painter.setBrush(Qt::cyan);
        }
        else{
            painter.setBrush(Qt::magenta);
        }

        painter.drawPie(size, startAng*16,angle*16);
    }


}
