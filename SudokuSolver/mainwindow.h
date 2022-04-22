#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
namespace Ui
{
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
    void alpha_matric();
    void alpha_matric2();
    void Alphabet();
    void Numbers();
    void matric2();
    bool solver();
    void nkar(QString&,int,int);
    bool check();
    bool empty();
    int count();
    bool is_full();
    int change[9][9];

public slots:
void Delete();
void solve();
void reset();
void New();
void setelement1();
void setelement2();
void setelement3();
void setelement4();
void setelement5();
void setelement6();
void setelement7();
void setelement8();
void setelement9();
private slots:
void ok_clicked()
{
    qDebug()<<"ok is clicked";// stugelu hamar
    ans=buttonBox->get_ans();
    help=buttonBox->get_help();
    col=buttonBox->get_col();
    col2=buttonBox->get_col2();
    update();
}
void cancel_clicked()
{
    qDebug()<<"cancel is clicked"; //stugelu hamar
}
void on_actionExit_triggered();

void on_actionRules_triggered();

void on_actionAbout_triggered();

void on_actionOptions_triggered();

private:
    Ui::MainWindow *ui;
    int x;
    int y;
     int w;
     int h;
     int matrix[9][9];
     int help;
     Dialog *buttonBox;
     QString col;
     QString col2;
     QString ans;
};

#endif // MAINWINDOW_H
