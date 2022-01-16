#include "piechartwidget2.h"
#include <QPainter>

PieChartWidget2::PieChartWidget2(QWidget *parent)
    : QWidget{parent}
{

}

void PieChartWidget2::setData(QVector<double> value, QVector<QColor> colors)
{
    qvValues = value;
    qvColors = colors;
    repaint();
    update();
}

void PieChartWidget2::paintEvent(QPaintEvent *)
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
    double angle, endAng, percent, startAng;

    for (int i=0; i<qvValues.size(); i++)
    {

        startAng = events[i].start;
        percent = events[i].length;
        angle = percent*360;
        endAng = startAng + angle;
        if(events[i].category.cat_name == "Sleep") {
            painter.setBrush(Qt::red);
        }
        else if(events[i].category.cat_name == "Work") {
            painter.setBrush(Qt::blue);
        }
        else if(events[i].category.cat_name == "Eating") {
            painter.setBrush(Qt::yellow);
        }
        else if(events[i].category.cat_name == "School") {
            painter.setBrush(Qt::cyan);
        }
        else(events[i].category.cat_name == "Recreation") {
            painter.setBrush(Qt::magenta);
        }
        painter.drawPie(size, startAng*16, angle*16);
    }
}
