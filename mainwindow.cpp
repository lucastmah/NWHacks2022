#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "day.h"

#include "home.h"
#include "stats.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< Updated upstream
    QVector<QColor> colors(5);
    QVector<double> values(5);
    colors[0] = Qt::red, colors[1] = Qt::blue, colors[2] = Qt::green, colors[3] = Qt::yellow, colors[4] = Qt::magenta;
    values[0] = 70, values[1] = 480, values[2] = 50, values[3] = 0, values[4] = 120;

    ui->widget->setData(values, colors);
=======

    //Connect to SQLite DB
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("/Users/jonathanYSA/Qt_Projects/Test_project_2/test_db.db");
    //TODO: Relative path should be used here

    //Display whether connected to the database
    if(!sqldb.open()){
        QMessageBox::information(this,"Not Connected", "Database not connected");
    }else{
        QMessageBox::information(this,"Connected", "Database connected");
    //TODO: should Exit here
    }

    Day* temp(0);
    temp->weekday = 0;
    vector<Event> events(5);

    // Grouped Implementation
    ui->piechartgrouped->setData(temp);

>>>>>>> Stashed changes

    QPushButton *homeRefresh = MainWindow::findChild<QPushButton *>("homeRefresh");
    connect(homeRefresh, SIGNAL(released()), this, SLOT(editHomeText()));
    QPushButton *statsRefresh = MainWindow::findChild<QPushButton *>("statsRefresh");
    connect(statsRefresh, SIGNAL(released()), this, SLOT(editStatsText()));
}

void MainWindow::editHomeText() {
    changeHomeText(ui->homeText);
}

void MainWindow::editStatsText() {
    changeStatsText(ui->statsText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

