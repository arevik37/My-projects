#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Sudoku solver ");
    w.setWindowIcon(QIcon(":/Icons/icon.png"));
    w.show();
    return a.exec();
}
