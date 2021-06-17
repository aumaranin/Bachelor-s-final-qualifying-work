#include "ch_alg.h"
#include "ui_ch_alg.h"
#include "widget.h"

ch_alg::ch_alg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ch_alg)
{
    ui->setupUi(this);
    ch_alg::setFixedSize(338,129);
    ui->radioButton_alg1->toggle();
}

ch_alg::~ch_alg()
{
    delete ui;
}

void ch_alg::on_pushButton_clicked()
{
    if (ui->radioButton_alg1->isChecked())
        alg = 1;
    if (ui->radioButton_alg2->isChecked())
        alg = 2;
    if (ui->radioButton_alg3->isChecked())
        alg = 3;
    ch_alg::reject();
}
