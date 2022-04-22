#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <QMouseEvent>
#include <QString>
#include <QPaintEvent>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QtGui>
#include <QRandomGenerator>
#include <QTime>

#define elif else if

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,650);
    ui->setupUi(this);
    connect(ui->pushButton ,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(setelement()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(setelement()));
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
void MainWindow::paintEvent(QPaintEvent*)
{
    if(empty())
    {
        ui->solve->setEnabled(true);
    }
    else {
         ui->solve->setEnabled(false);
    }
    QPainter painter(this);
    QPen pen,pen1;
    pen.setWidth(4);
    pen.setColor("white");
    pen1.setWidth(1);
    pen1.setColor("white");
    QImage image(":/Icons/none.jpg"),blue(":/IconsBlue.png"),green(":/IconsGreen.jpg"),color(":/IconsMulticolor.jpg"),none(":/Iconsnone.jpg");

    painter.drawImage(0,0,image);
  // chart
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

    matric();

    painter.end();
    this->update();
}
void MainWindow::nkar(QString& a,int i,int j)
{
    QPainter painter(this);
    QImage image1;
    QString b=":/Icons/"+a+".png";
    image1.load(b);
    painter.drawImage((i+1)*50+4,(j+1)*50+4,image1);
    this->update();
}
void MainWindow::matric()
{
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
                if(matrix[i][j] && check() && change[i][j])
                   {
                        a=QString::number(matrix[i][j]);
                            nkar(a,i,j);
                   }
                elif (matrix[i][j] && check() && !change[i][j]) {
                        a="g"+QString::number(matrix[i][j]);
                        nkar(a,i,j);
                }
                    elif (matrix[i][j] && !check()) {
                            a="r"+QString::number(matrix[i][j]);
                            nkar(a,i,j);
                    }
        }
}
void MainWindow::Matrix()
{
    int k, i, j;

         k = QRandomGenerator::global()->bounded(1,9);
         i = QRandomGenerator::global()->bounded(0,8);
         j = QRandomGenerator::global()->bounded(0,8);
        matrix[i][j] = k;

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
                        ++c;
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

bool MainWindow::check()
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
void MainWindow::solve()
{
 Matrix();
 if(solver())
 {
     for (int i = 0; i < 94; ++i)
     {
         int n = QRandomGenerator::global()->bounded(0,9);
         int m = QRandomGenerator::global()->bounded(0,9);

         matrix[m][n] = 0;

     }

     update();
 }
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
            if(matrix[i][j] && change[i][j])
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
bool MainWindow::empty()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if(matrix[i][j])
                return false;
    return true;
}void MainWindow::mousePressEvent(QMouseEvent *me)
{
    QPointF point;
    point=me->localPos();
    x= int (point.x());
    y= int (point.y());
    w=x/50-1;
    h=y/50-1;
    this->update();
}
void MainWindow::setelement()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();
    int num=buttonText.toInt();
    if(!matrix[w][h] && x>50 && x<500 && y>50 && y<500)
    {
            matrix[w][h]=num;
            change[w][h]=1;
    }
    this->update();
}
MainWindow::~MainWindow()
{
    delete ui;
}
