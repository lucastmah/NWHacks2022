#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include "day.h"

/**
 * @brief The PieChartWidget class
 */
class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void setData(Day* target);
protected:
    void paintEvent(QPaintEvent*);
private:
    QVector<int> totals;
    QVector<QColor> qvColors;
signals:

};

#endif // PIECHARTWIDGET_H
