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
 * @brief CatDialog::on_addButton_clicked creates and adds a category to the vector of categories if new
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
}

/**
 * @brief CatDialog::on_cancelButton_clicked closes the dialog
 */
void CatDialog::on_cancelButton_clicked()
{
    done(0);
}

