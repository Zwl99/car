#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <qdir.h>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QFileDialog>
#include <QDialog>

namespace Ui {
class musicwindow;
}

class musicwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit musicwindow(QWidget *parent = nullptr);
    ~musicwindow();

private:
    QString str_pathmusic; //音乐文件夹路径
    QListWidgetItem *p_item; //音乐列表
    bool b_play_music = false; //是否播放音乐
    QString str_music;
    QMediaPlayer *p_player;
    int n_music_number;
    bool m_checked = false;
    //QMediaPlaylist  *playlist;

private:
       // void paintEvent(QPaintEvent *event);
        //读取文件
        void readFile();
        //初始化界面
        void initUI();

private slots:
    void on_back_bt_clicked();
    void on_musicListRowNum(int);

    void on_playbtn_2_clicked();

   //void on_music_Lab_linkActivated(const QString &link);

    void on_upbtn_2_clicked();

    void on_down_btn_clicked();


    void on_volume_clicked();

    void on_vol_change_sliderMoved();

   // void on_toolButton_5_clicked();  //读取文件

private:
    Ui::musicwindow *ui;
};

#endif // MUSICWINDOW_H
