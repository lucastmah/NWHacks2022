#ifndef PIECHARTWIDGET2_H
#define PIECHARTWIDGET2_H

#include <QWidget>

class PieChartWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget2(QWidget *parent = nullptr);
    void setData(QVector<double> value, QVector<QColor> colors);
protected:
    void paintEvent(QPaintEvent*);
private:
    QVector<double> qvValues;
    QVector<QColor> qvColors;
signals:

};

#endif // PIECHARTWIDGET2_H
