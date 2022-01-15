#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "home.h"
#include "stats.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

