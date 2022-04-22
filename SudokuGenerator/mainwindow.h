#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent * me);
    void matric();
    bool solver();
    void nkar(QString&,int,int);
    bool check();
    void Matrix();
    bool empty();
    int change[9][9];

public slots:
    void Delete();
    void reset();
    void New();
    void solve();
    void setelement();

private:
    Ui::MainWindow *ui;
    int x;
    int y;
     int w;
     int h;
     int matrix[9][9];
     int help;
};

#endif // MAINWINDOW_H
