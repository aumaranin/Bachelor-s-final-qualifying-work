#ifndef CH_ALG_H
#define CH_ALG_H

#include <QDialog>

namespace Ui {
class ch_alg;
}

class ch_alg : public QDialog
{
    Q_OBJECT

public:
    explicit ch_alg(QWidget *parent = 0);
    ~ch_alg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ch_alg *ui;
};

#endif // CH_ALG_H
