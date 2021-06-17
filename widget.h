#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QImage>
#include <QMessageBox>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QDateTime>
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video.hpp>

#include "settings.h"
#include "work_mode.h"
#include "ch_alg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

using namespace cv;

QPixmap MatToPixmap(cv::Mat src);


class FrameDifference
{
public:
    void process();
};

class MeanBGS
{
public:
    void process();
};

class Gaussian
{
public:
    void process();
};

class DetectSyst
{
public:
    int step;
    int thrh;
    int cam;
    bool mode;
    bool playing;
    QString video_path;
    DetectSyst();
    FrameDifference frame_difference;
    MeanBGS meanbgs;
    Gaussian gaussian;

    //void setVideoPath(QString n) {this->video_path = n;}
    //bool isPlaying()    {return playing;}
    //void setPlaying(bool pl)   {this->playing = pl;}
};

class Frame : public cv::Mat
{

};


extern int step;
extern int thrh;
extern int cam;
extern bool mode;    //false - видеозапись, true - камера
extern int alg;
extern QString video_path;



class Widget : public QWidget
{
    Q_OBJECT


public:
    DetectSyst detectsyst;
    Widget(QWidget *parent = nullptr);
    ~Widget();

    bool playing;




    void logging(double);
    void frame_difference();
    QImage frame_difference_mask(QImage, QImage);
    void meanbgs();
    void gaussian();
    void showResult(QImage, QImage);

private slots:

    void on_but_start_clicked();

    void on_but_stop_clicked();

    void on_but_exit_clicked();

    void on_but_set2_clicked();

    void on_but_set1_clicked();

    void on_but_set3_clicked();

private:
    Ui::Widget *ui;




};
#endif // WIDGET_H
