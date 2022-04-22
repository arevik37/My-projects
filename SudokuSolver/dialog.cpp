#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->radiobutton_none, SIGNAL(pressed()), this, SLOT(on_radioButton_none_clicked()));
    connect(ui->radioButton_blue, SIGNAL(pressed()), this, SLOT(on_radioButton_blue_clicked()));
    connect(ui->radioButton_green, SIGNAL(pressed()), this, SLOT(on_radioButton_green_clicked()));
    connect(ui->radioButton_multicolor, SIGNAL(pressed()), this, SLOT(on_radioButton_multicolor_clicked()));
    connect(ui->radioButton_numbers, SIGNAL(pressed()), this, SLOT(on_radioButton_numbers_clicked()));
    connect(ui->radioButton_alphabet, SIGNAL(pressed()), this, SLOT(on_radioButton_alphabet_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_radioButton_none_clicked()
{
     helpd=1;
     ansd="none";
}
void Dialog::on_radioButton_blue_clicked()
{
    helpd=1;
    ansd="blue";
}
void Dialog::on_radioButton_green_clicked()
{
    helpd=1;
    ansd="green";
}
void Dialog::on_radioButton_multicolor_clicked()
{
    helpd=1;
    ansd="color";
}
QString Dialog::get_ans()
{
    return ansd;
}
int Dialog::get_help()
{
    return helpd;
}
void Dialog::on_radioButton_numbers_clicked()
{
    cold="wg";
    col2d="num";
}

void Dialog::on_radioButton_alphabet_clicked()
{
    cold="wg";
    col2d="alpha";
}
QString Dialog::get_col()
{
    return cold;
}
QString Dialog::get_col2()
{
    return col2d;
}

void Dialog::on_radiobutton_white_green_clicked()
{
    cold="wg";
}

void Dialog::on_radioButton_yellow_blue_clicked()
{
    cold="yb";
}
