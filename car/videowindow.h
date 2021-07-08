#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMainWindow>
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <qdir.h>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class videowindow;
}

class videowindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit videowindow(QWidget *parent = nullptr);
    ~videowindow();

private slots:
    void on_back_bt_clicked();

private:
    Ui::videowindow *ui;
    QMediaPlayer *mediaplayer;
    QMediaPlaylist  *playlist;
    QString path_video;
    bool m_checked = false;

    //void  readFile();

private slots:
    void durationChanged(qint64 duration);
    void play();
    //列表
    void onPlaylistChanged(int position);
    void mediaStateChange(QMediaPlayer::State state);
////改变播放位置
    void positionChanged(qint64 position);
////获取播放位置
    void setPosition(int postion);
    void on_toolButton_clicked(); //play

    void on_horizontalSlider_sliderMoved(int position); //视频进度

    //void on_verticalSlider_valueChanged(int value);  //声音调节

    void on_toolButton_3_clicked();  //stop

    void on_toolButton_4_clicked();  //静音

    void on_toolButton_5_clicked();  //打开文件

    //void on_toolButton_6_clicked(); //清空列表

    void on_listWidget_doubleClicked(const QModelIndex &index);

    //void on_toolButton_7_clicked();  获取时间

    void on_toolButton_8_clicked();  //up

    void on_toolButton_9_clicked();  //down

    void on_toolButton_10_clicked();  //快进

    void on_toolButton_11_clicked();  //快退

   // void on_toolButton_2_clicked();
    void on_volume_clicked();  //声音按钮

    void on_vol_change_sliderMoved();  // 调节音量
};

#endif // VIDEOWINDOW_H
