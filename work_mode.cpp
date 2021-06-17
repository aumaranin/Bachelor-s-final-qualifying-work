#include "work_mode.h"
#include "ui_work_mode.h"
#include "widget.h"

work_mode::work_mode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::work_mode)
{
    ui->setupUi(this);
    ui->rad_cam->toggle();
}

work_mode::~work_mode()
{
    delete ui;
}

void work_mode::on_pushButton_2_clicked()
{
    if (ui->rad_cam->isChecked())
        mode = true;
    if (ui->rad_vid->isChecked())
    {
        mode = false;
        video_path = f_name;
    }
    work_mode::reject();
}

void work_mode::on_pushButton_clicked()
{
    f_name = QFileDialog::getOpenFileName(this, "Выберите видеозапись", "C:\\projects2\\test_video\\");
    ui->lineEdit->setText(f_name);
}
