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

/**
 * @brief The Only Window in the program.
 * @variable daysHolder. A internal vector including <Day*> information
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static vector<Day*> daysHolder;

    /**
     * @brief findDay look into the daysHolder and retrieve the location of the day by given (year, month, day)
     * @param year
     * @param month
     * @param day
     * @return -1 if not found, else: found.
     */
    static int findDay(int year, int month, int day){
        for(unsigned long long i = 0; i < daysHolder.size(); i++){
            if(daysHolder.at(i)->year == year && daysHolder.at(i)->month == month && daysHolder.at(i)->day == day) return i;
        }
        return -1;
    }

private slots:
    void on_addCatButton_clicked();
    void on_addEventButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
