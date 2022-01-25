#ifndef CATDIALOG_H
#define CATDIALOG_H

#include <QDialog>

namespace Ui {
class CatDialog;
}

/**
 * @brief The CatDialog class
 */
class CatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CatDialog(QWidget *parent = nullptr);
    ~CatDialog();

private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CatDialog *ui;
};

#endif // CATDIALOG_H
