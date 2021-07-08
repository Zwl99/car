#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //窗口分配空间
    music = new musicwindow(this);
    video = new videowindow(this);
    map = new mapwindow(this);
    weather = new weatherwindow(this);

    //显示时间
    getTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//显示窗口
void MainWindow::on_music_bt_clicked()   //音乐
{
    music->show();
    this->hide();
}

void MainWindow::on_video_bt_clicked()
{
    video->show();
    this->hide();
}

void MainWindow::on_map_bt_clicked()
{
    map->show();
    this->hide();
}

void MainWindow::on_weather_bt_clicked()
{
    weather->show();
    this->hide();
}

void MainWindow::getTime()
{
    QDateTime time =QDateTime::currentDateTime();
    QString str= time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->time->setText(str);
}
