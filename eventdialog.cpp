#include "eventdialog.h"
#include "ui_eventdialog.h"
#include "event.h"

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

    Category cat = Category::findCat(ui->catBox->currentData().toString().toStdString());

    if (start.date() < end.date()) { // split event across two days

    } else {

    }

    done(0);
}


void EventDialog::on_cancelButton_clicked()
{
    done(0);
}

