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

void CatDialog::on_addButton_clicked()
{
    string lineText = ui->catLine->text().toStdString();
    for (Category c : Category::cats) {
        if (c.name == lineText)  {
            return; // optional: add an error message here
        }
    }
    Category::cats.push_back(Category(lineText));
    // close window
}


void CatDialog::on_cancelButton_clicked()
{
    // close window
}

