#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<QColor> colors(5);
    QVector<double> values(5);
    colors[0] = Qt::red, colors[1] = Qt::blue, colors[2] = Qt::green, colors[3] = Qt::yellow, colors[4] = Qt::magenta;
    values[0] = 70, values[1] = 480, values[2] = 50, values[3] = 0, values[4] = 120;

    ui->widget->setData(values, colors);
}

MainWindow::~MainWindow()
{
    delete ui;
}

