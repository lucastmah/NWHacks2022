#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <chrono>
#include <ctime>
#include "day.h"
#include "category.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static vector<Day*> daysHolder;

    static int findDay(int year, int month, int day){
        for(unsigned long long i = 0; i < daysHolder.size(); i++){
            if(daysHolder.at(i)->year == year && daysHolder.at(i)->month == month && daysHolder.at(i)->day == day) return i;
        }
        return -1;
    }

private slots:
    void on_addCatButton_clicked();
    void on_addEventButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
