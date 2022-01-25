/**
 * Descriptions:
 * @authors Lucas Mah, Josh Castillo, Ryan Tan, Shenao "Jonathan" Yang
 * @date Jan. 15, 2022.
 * nwHacks 2022
 */


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
