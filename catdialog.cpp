#include "catdialog.h"
#include "ui_catdialog.h"
#include "category.h"

CatDialog::CatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CatDialog)
{
    ui->setupUi(this);
}

CatDialog::~CatDialog()
{
    delete ui;
}

/**
 * @brief CatDialog::on_addButton_clicked
 */
void CatDialog::on_addButton_clicked()
{
    string lineText = ui->catLine->text().toStdString();
    for (Category & c : Category::cats) {
        if (c.name == lineText)  { // check for dupe
            return; // optional: add an error message here
        }
    }

    Category::cats.push_back(Category(lineText));
    done(0);

// add a textEdit box to print categories for testing
//    QString test;
//    for (Category & c : Category::cats) {
//        QString catname = QString::fromStdString(c.name);
//        test.append(catname);
//    }
//    test.append(QString::number(Category::cats.size()));
//    ui->textEdit->setText(test);
}

/**
 * @brief CatDialog::on_cancelButton_clicked
 */
void CatDialog::on_cancelButton_clicked()
{
    done(0);
}

