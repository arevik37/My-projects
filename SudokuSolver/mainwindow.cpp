#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "QPainter"
#include <QMouseEvent>
#include <QString>
#include <QPaintEvent>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QtGui>
#include <QDialogButtonBox>
#include <QDebug>
#define elif else if
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,650);
    w=0;
    h=0;
    ui->setupUi(this);
    buttonBox = new Dialog();
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(ok_clicked()));

    connect(ui->pushButton ,SIGNAL(clicked()),this,SLOT(setelement1()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(setelement2()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(setelement3()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(setelement4()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(setelement5()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(setelement6()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(setelement7()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(setelement8()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(setelement9()));
    connect(ui->Delete,SIGNAL(clicked()),this,SLOT(Delete()));
    connect(ui->New,SIGNAL(clicked()),this,SLOT(New()));
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(reset()));
    connect(ui->solve,SIGNAL(clicked()),this,SLOT(solve()));
    for (int i=0;i<9;++i)
        for(int j=0;j<9;++j)
        {
            matrix[i][j]=0;
            change[i][j]=0;
        }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen,pen1;
    pen.setWidth(4);
    pen.setColor("white");
    pen1.setWidth(1);
    pen1.setColor("white");
    QImage image(":/Icons/Background/none.jpg"),blue(":/Icons/Background/Blue.png"),green(":/Icons/Background/Green.jpg"),color(":/Icons/Background/Multicolor.jpg"),none(":/Icons/Background/none.jpg");
    painter.drawImage(0,0,image);
    if(help)
    {
    if(ans=="blue"){
       painter.drawImage(0,0,blue);
      }
        elif (ans=="green") {
           painter.drawImage(0,0,green);
        }
            elif (ans=="color") {
             painter.drawImage(0,0,color);
            }
                elif (ans=="none")
                {
                    painter.drawImage(0,0,none);
                   }
     } ////// chart
    painter.setPen(pen);
    painter.drawRect(50,50,450,450);
    painter.setPen(pen1);
    for(int i=2;i<=9;++i)
        {
            if(i==4 || i==7)
                painter.setPen(pen);
            else
                painter.setPen(pen1);
            painter.drawLine(i*50,50,i*50,500);
            painter.drawLine(50,i*50,500,i*50);
        }
    if(col2=="alpha" && col=="wg") {
        Alphabet();
        alpha_matric();
    }
    elif(col2=="alpha" && col=="yb") {
        Alphabet();
        alpha_matric2();
    }
    elif(col=="yb")
    {
        Numbers();
        matric2();
    }
    else {
        Numbers();
        matric();
    }
    painter.end();
 //   this->update();
}
void MainWindow::nkar(QString& a,int i,int j)
{
    QPainter painter(this);
    QImage image1;
    QString b=":/Icons"+a+".png";
    image1.load(b);
    painter.drawImage((i+1)*50+4,(j+1)*50+4,image1);
    this->update();
}
void MainWindow::matric()
{
    /*if(count()>=4)
        ui->solve->setEnabled(true);
    else
        ui->solve->setEnabled(false);*/
    QString a;
    if(!matrix[w][h] && x>50 && x<500 && y>50 && y<500)
    {
        a="/green";
        nkar(a,w,h);
    }
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            for (int k = j + 1; k <=9; ++k)
        {
                if(matrix[i][j] && check() && change[i][j]) {
                        a="/Numbers/"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                   }
                elif (matrix[i][j] && check() && !change[i][j]) {
                        a="/Numbers/g"+QString::number(matrix[i][j]);
                        nkar(a,i,j);
                }
                    elif (matrix[i][j] && !check()) {
                            ui->solve->setEnabled(false);
                            a="/Numbers/r"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                    }
        }
}
void MainWindow::matric2()
{
   /* if(count()>=4)
    ui->solve->setEnabled(true);
    else
        ui->solve->setEnabled(false);*/
    QString a;
    if(!matrix[w][h] && x>50 && x<500 && y>50 && y<500)
    {
        a="green";
        nkar(a,w,h);
    }
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            for (int k = j + 1; k <=9; ++k)
        {
                if(matrix[i][j] && check() && change[i][j]) {
                        a="/Numbers/y"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                   }
                elif (matrix[i][j] && check() && !change[i][j]) {
                        a="/Numbers/b"+QString::number(matrix[i][j]);
                        nkar(a,i,j);
                }
                    elif (matrix[i][j] && !check())  {
                            ui->solve->setEnabled(false);
                            a="/Numbers/r"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                    }
        }
}
void MainWindow::alpha_matric()
{
   /* if(count()>=4)
    ui->solve->setEnabled(true);
    else
        ui->solve->setEnabled(false);*/
    QString a;
    if(!matrix[w][h] && x>50 && x<500 && y>50 && y<500)
    {
        a="green";
        nkar(a,w,h);
    }
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            for (int k = j + 1; k <=9; ++k)
        {
                if(matrix[i][j] && check() && change[i][j]) {
                        a="/Alphabet/a"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                   }
                elif (matrix[i][j] && check() && !change[i][j]) {
                        a="/Alphabet/ag"+QString::number(matrix[i][j]);
                        nkar(a,i,j);
                }
                    elif (matrix[i][j] && !check())  {
                            ui->solve->setEnabled(false);
                            a="/Alphabet/ar"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                    }
        }
}
void MainWindow::alpha_matric2()
{
   /* if(count()>=4)
    ui->solve->setEnabled(true);
    else
        ui->solve->setEnabled(false);*/
    QString a;
    if(!matrix[w][h] && x>50 && x<500 && y>50 && y<500)
    {
        a="green";
        nkar(a,w,h);
    }
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            for (int k = j + 1; k <=9; ++k)
        {
                if(matrix[i][j] && check() && change[i][j]) {
                        a="/Alphabet/ay"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                   }
                elif (matrix[i][j] && check() && !change[i][j]) {
                        a="/Alphabet/ab"+QString::number(matrix[i][j]);
                        nkar(a,i,j);
                }
                    elif (matrix[i][j] && !check())  {
                            ui->solve->setEnabled(false);
                            a="/Alphabet/ar"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                    }
        }
}
int MainWindow::count() //for solve button activation
{
    int count=0;
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
        {
            if(matrix[i][j] && change[i][j])
            {
                ++count;
            }
        }
    return count;
}
void MainWindow::Delete()
{
    if(!empty() &&  x>50 && x<500 && y>50 && y<500)
    {
        matrix[w][h]=0;
        change[w][h]=0;
        update();
    }
    else
        update();
}
void MainWindow::reset()
{
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
        {
            if(matrix[i][j] && !change[i][j])
                matrix[i][j]=0;
        }
    update();
}
void MainWindow::New()
{
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
        {
                matrix[i][j]=0;
                change[i][j]=0;
        }
    update();
}
bool MainWindow::solver()
{
    int a = -1;
    int b = -1;
    int min = 10;
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
        {
            if(matrix[i][j]==0)
            {
                int c=0;
                for(int k=1;k<=9;++k)
                {
                    matrix[i][j]=k;
                    if(check())
                    {
                        ++c;
                    }
                    matrix[i][j]=0;
                }
                if (min > c)
                        {
                          min = c;
                          a = i;
                          b = j;
                        }
            }
        }
    if (a == -1)
      return true;
    for (int k = 1; k <= 9; ++k)
    {
      matrix[a][b] = k;
      if (check())
        if (solver())
            return true;
    }
    matrix[a][b] = 0;
    return false;
}
void MainWindow::solve()
{
    if(solver())
        update();
    else {
        QMessageBox msg;
        msg.setText("<H1>No solution exists<H1>");
        msg.exec();
    }
}
bool MainWindow::check() //for function solver
{
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
      for (int k = j + 1; k < 9; ++k)
      {
       if (matrix[i][j] != 0 && matrix[i][j] == matrix[i][k])
            return false;
       if (matrix[j][i] != 0 && matrix[j][i] == matrix[k][i])
            return false;
       if (matrix[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] != 0 && matrix[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] ==
              matrix[k % 3 + (i % 3) * 3][k / 3 + (i / 3) * 3])
            return false;
        }
    return true;
}
bool MainWindow::empty() //for delete
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if(matrix[i][j])
                return false;
    return true;
}
/*bool MainWindow::is_full()
 * {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if(!matrix[i][j])
                return false;
    return true;
}*/
void MainWindow::mousePressEvent(QMouseEvent *me)
{
    QPointF point;
    point=me->localPos();
    x= int (point.x());
    y= int (point.y());
    w=x/50-1;
    h=y/50-1;
    this->update();
}
void MainWindow::setelement1()
{
    matrix[w][h]=1;
    change[w][h]=1;
}
void MainWindow::setelement2()
{
    matrix[w][h]=2;
    change[w][h]=1;
}
void MainWindow::setelement3()
{
    matrix[w][h]=3;
    change[w][h]=1;
}
void MainWindow::setelement4()
{
    matrix[w][h]=4;
    change[w][h]=1;
}
void MainWindow::setelement5()
{
    matrix[w][h]=5;
    change[w][h]=1;
}
void MainWindow::setelement6()
{
    matrix[w][h]=6;
    change[w][h]=1;
}
void MainWindow::setelement7()
{
    matrix[w][h]=7;
    change[w][h]=1;
}
void MainWindow::setelement8()
{
    matrix[w][h]=8;
    change[w][h]=1;
}
void MainWindow::setelement9()
{
    matrix[w][h]=9;
    change[w][h]=1;
}
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
void MainWindow::on_actionRules_triggered()
{
    QMessageBox msg;
    msg.setText("<h2><font color=white>Rules<h3><br><br>Fill the neseccary cells:<br>You can delete any cell by checking "
                "that cell and pressing ''Delete'' button.<br>After filling necessary cells press ''Solve'' button."
                "<br>ENJOY IT!");
    msg.setStyleSheet("background-color: black");
    msg.exec();
}
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.setWindowTitle("About");
    msg.setText("<h1><font color=white>About Sudoku Solver<h3><br><br>Version 1.0.0<br><br>''Sudoku Solver'' "
                "was developed by Arevik Hakobyan.<br><br>"
                "This program comes with ABSOLUTELY NO WARRANTY.<br><br>Email:<font color=blue>arushhakobyan8@gmail.com"
                "<br><font color=white>COPYRIGHT ©2019, Arevik Hakobyan."
                "<br>All rights reserved.<h3>");
    msg.setStyleSheet("background-color: black");
    msg.exec();
}
void MainWindow::Alphabet()
{
    ui->pushButton  ->setText("A");
    ui->pushButton_2->setText("B");
    ui->pushButton_3->setText("C");
    ui->pushButton_4->setText("D");
    ui->pushButton_5->setText("E");
    ui->pushButton_6->setText("F");
    ui->pushButton_7->setText("G");
    ui->pushButton_8->setText("H");
    ui->pushButton_9->setText("I");
}
void MainWindow::Numbers()
{
    ui->pushButton  ->setText("1");
    ui->pushButton_2->setText("2");
    ui->pushButton_3->setText("3");
    ui->pushButton_4->setText("4");
    ui->pushButton_5->setText("5");
    ui->pushButton_6->setText("6");
    ui->pushButton_7->setText("7");
    ui->pushButton_8->setText("8");
    ui->pushButton_9->setText("9");
}

void MainWindow::on_actionOptions_triggered()
{
    buttonBox->show();
}
