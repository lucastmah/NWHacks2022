#ifndef PIECHARTSEPARATED_H
#define PIECHARTSEPARATED_H

#include <QWidget>
#include "day.h"

class PieChartSeparated : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartSeparated(QWidget *parent = nullptr);
    void setData(Day* target);
protected:
    void paintEvent(QPaintEvent*);
private:
    Day* day;
signals:

};

#endif // PIECHARTSEPARATED_H
