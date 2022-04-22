#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString get_ans();
    int get_help();
    QString get_col();
    QString get_col2();

private slots:
    void on_radioButton_none_clicked();

    void on_radioButton_blue_clicked();

    void on_radioButton_green_clicked();

    void on_radioButton_multicolor_clicked();

    void on_radioButton_numbers_clicked();

    void on_radioButton_alphabet_clicked();

    void on_radiobutton_white_green_clicked();

    void on_radioButton_yellow_blue_clicked();

private:
    Ui::Dialog *ui;
    QString ansd;
    int helpd;
    QString cold,col2d;
};

#endif // DIALOG_H
