#include "widget.h"
#include "ui_widget.h"

int step = 10;
int thrh = 10;
int cam = 0;
int alg = 1;
bool mode = true;

QString video_path = "C:\\projects2\\images\\test_video_640-480.mp4";

DetectSyst::DetectSyst()
{
    this->playing = false;
    this->video_path = video_path;
    this->cam = cam;
    this->mode = mode;
    this ->step = step;

}



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Widget::setFixedSize(1438, 544);                    //фиксация размера окна приложения
    cv::namedWindow("test",0);                      //создание необходимого окна для работы таймера
    cv::moveWindow("test", 10000, 10000);
}

Widget::~Widget()
{
    cv::destroyWindow("test");
    delete ui;
}


void Widget::on_but_start_clicked()
{
    playing = true;
    if (alg == 1)
        Widget::frame_difference();
    if (alg == 2)
        Widget::meanbgs();
    if (alg ==3 )
        Widget::gaussian();
}


void Widget::on_but_stop_clicked()
{
    playing = false;
}



void Widget::logging(double size)
{
    QString time_format = "yyyy-MM-dd HH:mm:ss";
    QDateTime DateTime = QDateTime::currentDateTime();
    QString DateTimeRes = DateTime.toString(time_format);
    std::string str;
    str += DateTimeRes.toStdString();
    str += " ";
    if (mode)
        str += "Camera";
    else
        str += video_path.toStdString();
    str += " ";
    str += std::to_string(size * 100);
    str += "\n";

    std::fstream log_file;
    log_file.open("log.txt", std::ios::app);
    log_file << str;
    log_file.close();
}


QPixmap MatToPixmap(cv::Mat src)
{
    QImage::Format format=QImage::Format_Grayscale8;
    int bpp=src.channels();
    if(bpp==3)format=QImage::Format_RGB888;
    QImage img(src.cols,src.rows,format);
    uchar *sptr,*dptr;
    int linesize=src.cols*bpp;
    for(int y=0;y<src.rows;y++){
        sptr=src.ptr(y);
        dptr=img.scanLine(y);
        memcpy(dptr,sptr,linesize);
    }
    if(bpp==3)return QPixmap::fromImage(img.rgbSwapped());
    return QPixmap::fromImage(img);
}

void Widget::on_but_exit_clicked()
{
    Widget::close();
}

void Widget::on_but_set2_clicked()
{
    settings win_settings;
    win_settings.setModal(true);
    win_settings.exec();
}

void Widget::on_but_set1_clicked()
{
    work_mode win_mode;
    win_mode.setModal(true);
    win_mode.exec();
}

void Widget::on_but_set3_clicked()
{
    ch_alg win_alg;
    win_alg.setModal(true);
    win_alg.exec();
}

/*
void Widget::frame_difference()
{
    cv::VideoCapture *cap;
    if (mode == true)
        cap = new cv::VideoCapture(cam);
    else
        cap = new cv::VideoCapture(video_path.toStdString());
    Frame frame1;
    QImage pic1, pic2, pic_ed;

    while (playing)
    {
        for (int i = 0; i < 2; i++)
        {
            cap->read(frame1);
            if (frame1.empty())
            {
                playing = false;
                break;
                QMessageBox::about(this,"Видеозапись повреждена","Ошибка");
            }
            if (i == 0)
            {
               pic1 = MatToPixmap(frame1).toImage();
            }
            if (i == 1)
            {
                pic2 = MatToPixmap(frame1).toImage();
                pic_ed = frame_difference_mask(pic1, pic2);
            }
            Widget::showResult(pic1, pic_ed);
            cv::waitKey(5);
        }
    }
    delete cap;
}

QImage Widget::frame_difference_mask(QImage picture1, QImage picture2)
{
    QImage picture1_gr = picture1.convertToFormat(QImage::Format_Grayscale8);
    QImage picture2_gr = picture2.convertToFormat(QImage::Format_Grayscale8);
    int col = (640 / step);
    int row = (480 / step);
    QColor pix1, pix2;


    //Обнуление матриц изображений
    int frag1[row][col];
    int frag2[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            frag1[i][j] = 0;
            frag2[i][j] = 0;
        }

    //Вычисление матриц яркости
    for (int nrow = 0, buf1 = 0, buf2 = 0;nrow < row; nrow++)
    {
        for (int ncol = 0;ncol < col;ncol++)
        {
            for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                for (int j = 0 + ncol*step; j < step + ncol*step; j++)
                {
                    pix1 = picture1_gr.pixelColor(j,i);
                    buf1 += pix1.lightness();
                    pix2 = picture2_gr.pixelColor(j,i);
                    buf2 += pix2.lightness();
                }
            frag1[nrow][ncol] = buf1;
            buf1 = 0;
            frag2[nrow][ncol] = buf2;
            buf2 = 0;
        }
    }

    int a_c = col * row;    // общее количество сегментов
    int r_c = 0;            // количество красных сегментов

    //окно с конечными изменениями
    QImage pic_res = picture1;
    for (int nrow = 0;nrow < row; nrow++)
    {
        for (int ncol = 0;ncol < col;ncol++)
        {
            int dism = (frag1[nrow][ncol] * (100 - thrh)/100);
            int disp = (frag1[nrow][ncol] * (100 + thrh)/100);
            if ((frag2[nrow][ncol] < dism) or (frag2[nrow][ncol] > disp))
            {
                //увеличить красный цвет в секторе
                for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                    for (int j = 0+ ncol*step; j < step + ncol*step; j++)
                    {
                        QColor pic_col = picture1.pixelColor(j,i);
                        pic_col.setRed(255);
                        pic_res.setPixelColor(j, i, pic_col);

                    }
                r_c++;  //считаем количество красных сегментов
            }
        }
    }

    double size = (double(r_c) / double(a_c));
    if (size > double(0.05))
        Widget::logging(size);
    return pic_res;
}*/

void Widget::showResult(QImage pic1, QImage pic2)
{
    ui->lab_or->setPixmap(QPixmap::fromImage(pic1));
    ui->lab_ed->setPixmap(QPixmap::fromImage(pic2));
}

void Widget::meanbgs()
{
    cv::VideoCapture *cap;
    if (mode == true)
        cap = new cv::VideoCapture(cam);
    else
        cap = new cv::VideoCapture(video_path.toStdString());
    Frame frame1;
    QImage picBG, pic1, pic2, pic_ed;

    cap->read(frame1);
    if (frame1.empty())
    {
        playing = false;
        QMessageBox::about(this,"Видеозапись повреждена","Ошибка");
        return;
    }
    picBG = MatToPixmap(frame1).toImage();

    while (playing)
    {
        cap->read(frame1);
        pic1 = MatToPixmap(frame1).toImage();

        QImage picture1_gr = pic1.convertToFormat(QImage::Format_Grayscale8);
        QImage picture2_gr = picBG.convertToFormat(QImage::Format_Grayscale8);
        int col = (640 / step);
        int row = (480 / step);
        QColor pix1, pix2;

        //Обнуление матриц изображений
        int frag1[row][col];
        int fragBG[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                frag1[i][j] = 0;
                fragBG[i][j] = 0;
            }

        //Вычисление матриц яркости
        for (int nrow = 0, buf1 = 0, buf2 = 0;nrow < row; nrow++)
        {
            for (int ncol = 0;ncol < col;ncol++)
            {
                for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                    for (int j = 0 + ncol*step; j < step + ncol*step; j++)
                    {
                        pix1 = picture1_gr.pixelColor(j,i);
                        buf1 += pix1.lightness();
                        pix2 = picture2_gr.pixelColor(j,i);
                        buf2 += pix2.lightness();
                    }
                frag1[nrow][ncol] = buf1;
                buf1 = 0;
                fragBG[nrow][ncol] = buf2;
                buf2 = 0;
            }
        }

        int a_c = col * row;    // общее количество сегментов
        int r_c = 0;            // количество красных сегментов

        //окно с конечными изменениями
        QImage pic_res = pic1;
        for (int nrow = 0;nrow < row; nrow++)
        {
            for (int ncol = 0;ncol < col;ncol++)
            {
                int dism = (frag1[nrow][ncol] * (100 - thrh)/100);
                int disp = (frag1[nrow][ncol] * (100 + thrh)/100);
                if ((fragBG[nrow][ncol] < dism) or (fragBG[nrow][ncol] > disp))
                {
                    //увеличить красный цвет в секторе
                    for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                        for (int j = 0+ ncol*step; j < step + ncol*step; j++)
                        {
                            QColor pic_col = pic1.pixelColor(j,i);
                            pic_col.setRed(255);
                            pic_res.setPixelColor(j, i, pic_col);

                        }
                    r_c++;  //считаем количество красных сегментов
                }
            }
        }

        pic_ed = pic_res;

        double size = (double(r_c) / double(a_c));
        if (size > double(0.05))
            Widget::logging(size);

        Widget::showResult(pic1, pic_ed);
        cv::waitKey(5);

    }
    delete cap;
}


/*
QImage Gaussian_dif(QImage picture0, QImage picture1, QImage picture2, QImage picture3, int *mas)
    {
        QImage picture0_gr = picture1.convertToFormat(QImage::Format_Grayscale8);
        QImage picture1_gr = picture1.convertToFormat(QImage::Format_Grayscale8);
        QImage picture2_gr = picture2.convertToFormat(QImage::Format_Grayscale8);
        QImage picture3_gr = picture1.convertToFormat(QImage::Format_Grayscale8);
        int col = (640 / step);
        int row = (480 / step);
        QColor pix0, pix1, pix2, pix4;


        //Обнуление матриц изображений
        int frag0[row][col];
        int frag1[row][col];
        int frag2[row][col];
        int frag3[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                frag0[i][j] = 0;
                frag1[i][j] = 0;
                frag2[i][j] = 0;
                frag3[i][j] = 0;
            }

        //Вычисление матриц яркости
        for (int nrow = 0, buf0 = 0, buf1 = 0, buf2=0, buf3 = 0;nrow < row; nrow++)
        {
            for (int ncol = 0;ncol < col;ncol++)
            {
                for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                    for (int j = 0 + ncol*step; j < step + ncol*step; j++)
                    {
                        pix0 = picture0_gr.pixelColor(j,i);
                        buf0 += pix0.lightness();
                        pix1 = picture1_gr.pixelColor(j,i);
                        buf1 += pix1.lightness();
                        pix1 = picture1_gr.pixelColor(j,i);
                        buf1 += pix1.lightness();
                        pix2 = picture2_gr.pixelColor(j,i);
                        buf2 += pix2.lightness();
                        pix3 = picture3_gr.pixelColor(j,i);
                        buf3 += pix3.lightness();
                    }
                frag0[nrow][ncol] = buf0;
                buf0 = 0;
                frag1[nrow][ncol] = buf1;
                buf1 = 0;
                frag2[nrow][ncol] = buf2;
                buf2 = 0;
                frag3[nrow][ncol] = buf3;
                buf3 = 0;
            }
        }

        int a_c = col * row;    // общее количество сегментов
        int r_c = 0;            // количество красных сегментов

        //окно с конечными изменениями
        QImage pic_res = picture1;
        for (int nrow = 0;nrow < row; nrow++)
        {
            for (int ncol = 0;ncol < col;ncol++)
            {
                int dism = (frag0[nrow][ncol] * (100 - thrh)/100);
                int disp = (frag0[nrow][ncol] * (100 + thrh)/100);
                if ((frag1[nrow][ncol] < dism) or (frag1[nrow][ncol] > disp))
                {
                //заполнить матрицу по секторам
                    *(mas + nrow*col + ncol) ++;

                }
            }

        }
}
*/

void Gaussian_mask(QImage picture1,QImage picture2, int* mas)
{
    QImage picture1_gr = picture1.convertToFormat(QImage::Format_Grayscale8);
    QImage picture2_gr = picture2.convertToFormat(QImage::Format_Grayscale8);
    int col = (640 / step);
    int row = (480 / step);
    QColor pix1, pix2;


    //Обнуление матриц изображений
    int frag1[row][col];
    int frag2[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            frag1[i][j] = 0;
            frag2[i][j] = 0;
        }

    //Вычисление матриц яркости
    for (int nrow = 0, buf1 = 0, buf2 = 0;nrow < row; nrow++)
    {
        for (int ncol = 0;ncol < col;ncol++)
        {
            for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                for (int j = 0 + ncol*step; j < step + ncol*step; j++)
                {
                    pix1 = picture1_gr.pixelColor(j,i);
                    buf1 += pix1.lightness();
                    pix2 = picture2_gr.pixelColor(j,i);
                    buf2 += pix2.lightness();
                }
            frag1[nrow][ncol] = buf1;
            buf1 = 0;
            frag2[nrow][ncol] = buf2;
            buf2 = 0;
        }
    }



    //окно с конечными изменениями
    for (int nrow = 0;nrow < row; nrow++)
    {
        for (int ncol = 0;ncol < col;ncol++)
        {
            int dism = (frag1[nrow][ncol] * (100 - thrh)/100);
            int disp = (frag1[nrow][ncol] * (100 + thrh)/100);
            if ((frag2[nrow][ncol] < dism) or (frag2[nrow][ncol] > disp))
            {
                //увеличить сектор в маске на единицу
                *(mas + nrow*col + ncol)+=1;
            }
        }
    }


}

void Widget::gaussian()
{
    cv::VideoCapture *cap;
    if (mode == true)
        cap = new cv::VideoCapture(cam);
    else
        cap = new cv::VideoCapture(video_path.toStdString());
    Frame frame1;
    QImage pic0, pic1, pic2, pic3, pic4, pic_ed;

    cap->read(frame1);
    if (frame1.empty())
    {
        playing = false;
        QMessageBox::about(this,"Видеозапись повреждена","Ошибка");
        return;
    }

    int row = (480 / step);
    int col = (640 / step);
    int mask[row*col];
    for (int i = 0; i < row*col; i++)
        mask[i] = 0;

    while (playing)
    {
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                cap->read(frame1);
                pic0 = MatToPixmap(frame1).toImage();
                break;
            case 1:
                cap->read(frame1);
                pic1 = MatToPixmap(frame1).toImage();
                break;
            case 2:
                cap->read(frame1);
                pic2 = MatToPixmap(frame1).toImage();
                break;
            case 3:
                cap->read(frame1);
                pic3 = MatToPixmap(frame1).toImage();
                break;
            }
        }

        Gaussian_mask(pic0,pic1,mask);
        Gaussian_mask(pic1,pic2,mask);
        Gaussian_mask(pic2,pic3,mask);

        //выделение крассным

        int a_c = col * row;    // общее количество сегментов
        int r_c = 0;            // количество красных сегментов

        //окно с конечными изменениями
        QImage pic_res = pic3;
        for (int nrow = 0;nrow < row; nrow++)
        {
            for (int ncol = 0;ncol < col;ncol++)
            {

                if (*(mask + nrow*col + ncol) > 2)
                {
                    //увеличить красный цвет в секторе
                    for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                        for (int j = 0+ ncol*step; j < step + ncol*step; j++)
                        {
                            QColor pic_col = pic3.pixelColor(j,i);
                            pic_col.setRed(255);
                            pic_res.setPixelColor(j, i, pic_col);

                        }
                    r_c++;  //считаем количество красных сегментов
                }
            }
        }

        pic_ed = pic_res;
        for (int i = 0; i < row*col; i++)
            mask[i] = 0;

        double size = (double(r_c) / double(a_c));
        if (size > double(0.05))
            Widget::logging(size);

        Widget::showResult(pic3, pic_ed);
        cv::waitKey(5);
    }

    delete cap;
}










void Widget::frame_difference()
{
    cv::VideoCapture *cap;
    if (mode == true)
        cap = new cv::VideoCapture(cam);
    else
        cap = new cv::VideoCapture(video_path.toStdString());
    Frame frame1;
    QImage pic1, pic2, pic_ed;

    while (playing)
    {
        for (int i = 0; i < 2; i++)
        {
            cap->read(frame1);
            if (frame1.empty())
            {
                playing = false;
                break;
                QMessageBox::about(this,"Видеозапись повреждена","Ошибка");
            }
            if (i == 0)
            {
               pic1 = MatToPixmap(frame1).toImage();
            }
            if (i == 1)
            {
                pic2 = MatToPixmap(frame1).toImage();

                QImage picture1_gr = pic1.convertToFormat(QImage::Format_Grayscale8);
                QImage picture2_gr = pic2.convertToFormat(QImage::Format_Grayscale8);
                int col = (640 / step);
                int row = (480 / step);
                QColor pix1, pix2;


                //Обнуление матриц изображений
                int frag1[row][col];
                int frag2[row][col];
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < col; j++)
                    {
                        frag1[i][j] = 0;
                        frag2[i][j] = 0;
                    }

                //Вычисление матриц яркости
                for (int nrow = 0, buf1 = 0, buf2 = 0;nrow < row; nrow++)
                {
                    for (int ncol = 0;ncol < col;ncol++)
                    {
                        for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                            for (int j = 0 + ncol*step; j < step + ncol*step; j++)
                            {
                                pix1 = picture1_gr.pixelColor(j,i);
                                buf1 += pix1.lightness();
                                pix2 = picture2_gr.pixelColor(j,i);
                                buf2 += pix2.lightness();
                            }
                        frag1[nrow][ncol] = buf1;
                        buf1 = 0;
                        frag2[nrow][ncol] = buf2;
                        buf2 = 0;
                    }
                }

                int a_c = col * row;    // общее количество сегментов
                int r_c = 0;            // количество красных сегментов

                //окно с конечными изменениями
                QImage pic_res = pic1;
                for (int nrow = 0;nrow < row; nrow++)
                {
                    for (int ncol = 0;ncol < col;ncol++)
                    {
                        int dism = (frag1[nrow][ncol] * (100 - thrh)/100);
                        int disp = (frag1[nrow][ncol] * (100 + thrh)/100);
                        if ((frag2[nrow][ncol] < dism) or (frag2[nrow][ncol] > disp))
                        {
                            //увеличить красный цвет в секторе
                            for (int i = 0 + nrow*step; i < step + nrow*step; i++)
                                for (int j = 0+ ncol*step; j < step + ncol*step; j++)
                                {
                                    QColor pic_col = pic1.pixelColor(j,i);
                                    pic_col.setRed(255);
                                    pic_res.setPixelColor(j, i, pic_col);

                                }
                            r_c++;  //считаем количество красных сегментов
                        }
                    }
                }

                pic_ed = pic_res;

                double size = (double(r_c) / double(a_c));
                if (size > double(0.05))
                    Widget::logging(size);

            }
            Widget::showResult(pic1, pic_ed);
            cv::waitKey(5);
        }
    }
    delete cap;
}
