#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QDir>

//窗口头文件
#include "musicwindow.h"
#include "videowindow.h"
#include "mapwindow.h"
#include "weatherwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_music_bt_clicked(); //音乐

    void on_video_bt_clicked(); //视频

    void on_map_bt_clicked();

    void on_weather_bt_clicked();

private:
    Ui::MainWindow *ui;

    //自定义窗口
    musicwindow *music;
    videowindow *video;
    mapwindow *map;
    weatherwindow *weather;

    void getTime();

};
#endif // MAINWINDOW_H
