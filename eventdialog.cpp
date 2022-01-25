#include "eventdialog.h"
#include "ui_eventdialog.h"
#include "event.h"
#include "mainwindow.h"

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
    if (ui->catBox->currentIndex() == -1) return; // no category selected yet

    string lineText = ui->nameLine->text().toStdString(); // initialize current input

    // date formats
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

    Category cat = Category::findCat(ui->catBox->currentData().toString().toStdString());
    
    if (startDate.day() == endDate.day()) {
        Event* e  = new Event(cat, lineText, startMin, endMin);
        int i = MainWindow::findDay(startDate.year(), startDate.month(), startDate.day());
        MainWindow::daysHolder[i]->addEvent(e);

    } else { // split event across two days

        Event* e1 = new Event(cat, lineText, startMin, 1440);
        Event* e2 = new Event(cat, lineText, 0, endMin);

        int i1 = MainWindow::findDay(startDate.year(), startDate.month(), startDate.day());
        int i2 = MainWindow::findDay(endDate.year(), endDate.month(), endDate.day());

        MainWindow::daysHolder[i1]->addEvent(e1);
        MainWindow::daysHolder[i2]->addEvent(e2);

    }
    done(0);
}

/**
 * @brief EventDialog::on_cancelButton_clicked closes the dialog window
 */
void EventDialog::on_cancelButton_clicked()
{
    done(0);
}

