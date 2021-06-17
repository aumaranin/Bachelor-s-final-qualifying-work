#ifndef WORK_MODE_H
#define WORK_MODE_H

#include <QDialog>

namespace Ui {
class work_mode;
}

class work_mode : public QDialog
{
    Q_OBJECT

public:
    explicit work_mode(QWidget *parent = 0);
    ~work_mode();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::work_mode *ui;
    QString f_name;
};

#endif // WORK_MODE_H
