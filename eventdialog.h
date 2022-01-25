#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QDialog>
#include "category.h"
#include "eventdialog.h"
#include "ui_eventdialog.h"
#include "event.h"
#include "mainwindow.h"
#include "piechartwidget.h"

namespace Ui {
class EventDialog;
}

/**
 * @brief The EventDialog class
 */
class EventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventDialog(QWidget *parent = nullptr);
    ~EventDialog();

private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void save_to_db(int year, int month, int day, int start_min, int end_min, Category cat, string event);

private:
    Ui::EventDialog *ui;
};

#endif // EVENTDIALOG_H
