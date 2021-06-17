#include "settings.h"
#include "ui_settings.h"
#include "widget.h"


settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    settings::setFixedSize(329,101);
    ui->spinBox->setValue(step);
    ui->spinBox_2->setValue(thrh);
    ui->horizontalSlider->setValue(step);
    ui->horizontalSlider_2->setValue(thrh);
    connect(ui->spinBox, SIGNAL(valueChanged(int)),ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->spinBox, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),ui->horizontalSlider_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),ui->spinBox_2, SLOT(setValue(int)));
}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    step = ui->spinBox->value();
    thrh = ui->spinBox_2->value();
    settings::reject();
}
