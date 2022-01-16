#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
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
    vector<Day*> daysHolder;
    int findDay(int year, int month, int day){
        for(int i = 0; i < daysHolder.size(); i++){
            Day d = *daysHolder.at(i);
            if(d.year == year && d.month == month && d.day == day){
                return i;
            }
        }
        return -1;
    }

private slots:
    void editHomeText();
    void editStatsText();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
