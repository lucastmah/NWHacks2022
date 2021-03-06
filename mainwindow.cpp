#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "day.h"
#include "catdialog.h"
#include "eventdialog.h"
#include "home.h"
#include "stats.h"

/*
 * Data types in the database
 * event_list(
    year INT,
    month INT,
    day INT,
    start_min INT,
    end_min INT,
    cat TEXT,
    event TEXT
    );
 */

vector<Day*> MainWindow::daysHolder;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  

    //Connect to SQLite DB
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");

    // Windows testing: Copy the absolute path to the database. Use double slashes ("\\"), remember to add the file name.
    //sqldb.setDatabaseName("../NWHacks2022\\time_management.db");
    sqldb.setDatabaseName("C:\\Users\\pm\\OneDrive\\Documents\\GitHub\\NWHacks2022\\time_management.db");

    // Mac testing: Copy the absolute path to the database.

//    sqldb.setDatabaseName("/Users/jonathanYSA/Documents/GitHub/NWHacks2022/time_management.db");
    sqldb.setDatabaseName("/Users/ryan/Projects/NWHacks2022/time_management.db");

    //TODO: Relative path should be used here

    //Display whether connected to the database
    if(!sqldb.open()){
        QMessageBox::information(this,"Not Connected", "Database not connected");
    }else{
        QMessageBox::information(this,"Connected", "Database connected");
    //TODO: should Exit here?
    }

    //Read data in the database, push into events of each Day
    QSqlQueryModel* readModel = new QSqlQueryModel;
    readModel->setQuery("SELECT * FROM event_list");
    for(int i = 0; i < readModel->rowCount();i++){
        QSqlRecord item = readModel->record(i);
        int year = item.value(0).toInt();
        int month = item.value(1).toInt();
        int day = item.value(2).toInt();
        int start = item.value(3).toInt();
        int end = item.value(4).toInt();
        string name = item.value(6).toString().toStdString();
        Category cat(item.value(5).toString().toStdString());
        if(findDay(year,month,day) == -1){
            daysHolder.push_back(new Day(year, month, day));
            daysHolder.at(findDay(year,month,day))->addEvent(new Event(cat,name,start,end));
        }else{
            daysHolder.at(findDay(year,month,day))->addEvent(new Event(cat,name,start,end));
        }
    }

    //fix piechart testing
    /*
    Day* temp(0);
    temp->weekday = 0;
    vector<Event> events(5);
    */

    // Grouped Implementation

    if(!daysHolder.empty()){
        updateGroupedPiechart();
        for(unsigned long long i = 0; i < daysHolder.at(0)->events.size(); i++) {
            std::cout << daysHolder.at(0)->events.at(i)->toString() << std::endl;
        }
    }else{
        std::cout << "DaysHolder is empty! QUIT." << std::endl;
        //exit(2); // If not testing with the database, comment out this line.
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_addCatButton_clicked
 */
void MainWindow::on_addCatButton_clicked()
{
    CatDialog catDialog;
    catDialog.setModal(true);
    catDialog.exec();
}

/**
 * @brief MainWindow::on_addEventButton_clicked
 */
void MainWindow::on_addEventButton_clicked()
{
    EventDialog eventDialog;
    eventDialog.setModal(true);
    eventDialog.exec();
}

/**
 * @brief MainWindow::updateGroupedPiechart set first day's data to the grouped piechart
 */
void MainWindow::updateGroupedPiechart(){
    ui->piechartgrouped->setData(daysHolder.at(0));
}

/**
 * @brief MainWindow::on_tabWidget_tabBarClicked
 * @param index
 */
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    QString avgText = "Average time spent: \n";
    QString perText = "Percent time spent: \n";


    int n = std::min(7, (int) daysHolder.size());
    if (n == 0) {
        ui->avgPanel->setText(avgText);
        ui->perPanel->setText(perText);
        return;
    }

    std::map<string, int> m;

    for (int i = 0; i < n; i++) {
        for (Event* e : daysHolder[i]->events) {
            m[e->category.name] += e->length; // total up minutes for each category
        }
    }

    for (auto const & c : m) {
        avgText += QString::fromStdString(c.first).toUpper();
        avgText += QString(": ");
        avgText += QString::number(c.second / n);
        avgText += QString("minutes\n");
    }

    for (auto const & c : m) {
        perText += QString::fromStdString(c.first).toUpper();
        perText += QString(": ");
        perText += QString::number((int) ((double) c.second / (n * 1440) * 100));
        perText += QString("%\n");
    }

    ui->avgPanel->setText(avgText);
    ui->perPanel->setText(perText);

}

