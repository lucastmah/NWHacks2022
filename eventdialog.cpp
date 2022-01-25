#include "eventdialog.h"

EventDialog::EventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventDialog)
{
    ui->setupUi(this);

    for (Category c : Category::cats) {
        ui->catBox->addItem(QString::fromStdString(c.name));
    }
}

EventDialog::~EventDialog()
{
    delete ui;
}

/**
 * @brief EventDialog::on_addButton_clicked
 */
void EventDialog::on_addButton_clicked()
{
    if (ui->catBox->currentIndex() == -1) return;

    string lineText = ui->nameLine->text().toStdString();

    QDateTime start = ui->start->dateTime();
    QDateTime end = ui->end->dateTime();

    QDate startDate = start.date();
    QDate endDate = end.date();

    // start is same/later than end or exceeds 24 hours
    if (start >= end || endDate.day() - startDate.day() > 1) return;

    QTime startTime = start.time();
    QTime endTime = end.time();

    int startMin = startTime.hour() * 60 + startTime.minute();
    int endMin = endTime.hour() * 60 + endTime.minute();
    cout << "CAT : " << ui->catBox->currentData().toString().toStdString() << endl; // This is not getting the text
    Category cat = Category::findCat(ui->catBox->currentData().toString().toStdString());
    
    if (startDate.day() == endDate.day()) {
        Event* e  = new Event(cat, lineText, startMin, endMin);
        int i = MainWindow::findDay(startDate.year(), startDate.month(), startDate.day());
        if(i == -1){
            MainWindow::daysHolder.push_back(new Day(startDate.year(), startDate.month(), startDate.day()));
            i = MainWindow::daysHolder.size() - 1; // Newly added day
        }
        cout << e->toString();
        MainWindow::daysHolder[i]->addEvent(e);
        save_to_db(startDate.year(), startDate.month(), startDate.day(), startMin, endMin, cat, lineText);

    } else { // split event across two days

        Event* e1 = new Event(cat, lineText, startMin, 1440);
        Event* e2 = new Event(cat, lineText, 0, endMin);

        int i1 = MainWindow::findDay(startDate.year(), startDate.month(), startDate.day());
        if(i1 == -1){
            MainWindow::daysHolder.push_back(new Day(startDate.year(), startDate.month(), startDate.day()));
            i1 = MainWindow::daysHolder.size() - 1; // Newly added day
        }
        int i2 = MainWindow::findDay(endDate.year(), endDate.month(), endDate.day());
        if(i2 == -1){
            MainWindow::daysHolder.push_back(new Day(endDate.year(), endDate.month(), endDate.day()));
            i2 = MainWindow::daysHolder.size() - 1; // Newly added day
        }

        MainWindow::daysHolder[i1]->addEvent(e1);
        cout << e1->toString();
        save_to_db(startDate.year(), startDate.month(), startDate.day(), startMin, 1440, cat, lineText);
        MainWindow::daysHolder[i2]->addEvent(e2);
        cout << e2->toString();
        save_to_db(endDate.year(), endDate.month(), endDate.day(), 0, endMin, cat, lineText);

    }

    done(0);
}

/**
 * @brief EventDialog::on_cancelButton_clicked
 */
void EventDialog::on_cancelButton_clicked()
{
    done(0);
}

void EventDialog::save_to_db(int year, int month, int day, int start_min, int end_min, Category cat, string event){
    QSqlQuery qry;
    qry.prepare("INSERT INTO event_list VALUES(?,?,?,?,?,?,?)");
    qry.addBindValue(year);
    qry.addBindValue(month);
    qry.addBindValue(day);
    qry.addBindValue(start_min);
    qry.addBindValue(end_min);
    qry.addBindValue(QString::fromStdString(cat.name));
    qry.addBindValue(QString::fromStdString(event));

    if(qry.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
    }else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

    // Update the PieChart

    // Only printing one day's piechart

}
