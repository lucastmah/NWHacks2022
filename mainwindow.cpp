#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "day.h"
#include "catdialog.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect to SQLite DB
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    sqldb.setDatabaseName("/Users/jonathanYSA/Documents/GitHub/NWHacks2022/time_management.db");
=======
=======
>>>>>>> Stashed changes
    sqldb.setDatabaseName("C:\\Users\\josh_\\Documents\\GitHub\\NWHacks2022\\time_management.db");
    //qldb.setDatabaseName("time_management.db");
>>>>>>> Stashed changes
=======

    // Windows testing: Copy the absolute path to the database. Use double slashes ("\\"), remember to add the file name.
    //sqldb.setDatabaseName("../NWHacks2022\\time_management.db");
    sqldb.setDatabaseName("C:\\Users\\josh_\\Documents\\GitHub\\NWHacks2022\\time_management.db");

    // Mac testing: Copy the absolute path to the database.

   // sqldb.setDatabaseName("/Users/jonathanYSA/Documents/GitHub/NWHacks2022/time_management.db");
   // sqldb.setDatabaseName("/Users/ryan/Projects/NWHacks2022/time_management.db");

>>>>>>> Stashed changes
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
        string name = item.value(5).toString().toStdString();
        Category cat(item.value(6).toString().toStdString());
        if(findDay(year,month,day) == -1){
            daysHolder.push_back(new Day(year, month, day));
            daysHolder.at(findDay(year,month,day))->addEvent(new Event(cat,name,start,end));
        }else{
            daysHolder.at(findDay(year,month,day))->addEvent(new Event(cat,name,start,end));
        }
    }
<<<<<<< Updated upstream

<<<<<<< Updated upstream
    QVector<QColor> colors(5);
    QVector<double> values(5);
    colors[0] = Qt::red, colors[1] = Qt::blue, colors[2] = Qt::green, colors[3] = Qt::yellow, colors[4] = Qt::magenta;
    values[0] = 70, values[1] = 480, values[2] = 50, values[3] = 0, values[4] = 120;

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

<<<<<<< Updated upstream
    Day* temp(0);
    temp->weekday = 0;
    vector<Event> events(5);
=======
    Category::cats.push_back(Category("Sleeping"));
    Category::cats.push_back(Category("Work"));
    Category::cats.push_back(Category("Eating"));
    Category::cats.push_back(Category("School"));
    Category::cats.push_back(Category("Recreation"));
>>>>>>> Stashed changes

    // Grouped Implementation
    ui->piechartgrouped->setData(temp);
=======

=======
>>>>>>> Stashed changes
    ui->piechartgrouped->setData(daysHolder.at(0));
    ui->piechartseparated->setData(daysHolder.at(0));
    for(unsigned long long i = 0; i < daysHolder.at(0)->events.size(); i++){
        cout << daysHolder.at(0)->events.at(i)->toString() << endl << endl;
    }



>>>>>>> Stashed changes
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

