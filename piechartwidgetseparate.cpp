#include "piechartwidgetseparate.h"
#include <QPainter>

piechartwidgetseparate::piechartwidgetseparate()
{

}

void PieChartWidget::setData(QVector<double> value, QVector<QColor> colors)
{
    qvValues = value;
    qvColors = colors;    repaint();
    update();
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    // Tallies minutes for each category, updates values values
    for (int i=0; i < events.size(); i++)
    {
        if(events[i].category.cat_name == "Sleep")
        {
            qvValues[0] += events.length;
        }
        else if(events[i].category.cat_name == "Work")
        {
            qvValues[1] += events.length;
        }
        else if(events[i].category.cat_name == "Eating")
        {
            qvValues[2] += events.length;
        }
        else if(events[i].category.cat_name == "School")
        {
            qvValues[3] += events.length;
        }
        else
        {
            qvValues[4] += events.length;
        }
    }


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

    for (int i=0; i<qvValues.size(); i++)
    {
        percent = qvValues[i]/sum;
        angle = percent*360;
        endAng = startAng + angle;
        painter.setBrush(qvColors[i]);
        painter.drawPie(size, startAng*16, angle*16);
        startAng = endAng;
    }
}
