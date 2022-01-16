#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "day.h"
#include "catdialog.h"
#include "eventdialog.h"
#include "home.h"
#include "stats.h"

/*
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
    //sqldb.setDatabaseName("C:\\Users\\pm\\OneDrive\\Documents\\GitHub\\NWHacks2022\\time_management.db");
    sqldb.setDatabaseName("../NWHacks2022\\time_management.db");
    //TODO: Relative path should be used here

    //Display whether connected to the database
    if(!sqldb.open()){
        QMessageBox::information(this,"Not Connected", "Database not connected");
    }else{
        QMessageBox::information(this,"Connected", "Database connected");
    //TODO: should Exit here
    }

    //Read data in the database and push into events
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
    ui->piechartgrouped->setData(daysHolder.at(0));
    for(unsigned long long i = 0; i < daysHolder.at(0)->events.size(); i++) {
        cout << daysHolder.at(0)->events.at(i)->toString() << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addCatButton_clicked()
{
    CatDialog catDialog;
    catDialog.setModal(true);
    catDialog.exec();
}


void MainWindow::on_addEventButton_clicked()
{
    EventDialog eventDialog;
    eventDialog.setModal(true);
    eventDialog.exec();
}

