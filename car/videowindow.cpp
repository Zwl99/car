#include "videowindow.h"
#include "ui_videowindow.h"
#include<QMediaPlayer>
#include<QUrl>
#include<QFileDialog>
#include <QDialog>
#include<QDateTime>
#include<QPixmap>
#include<QPalette>
#include<QBrush>
#include<QWidget>
#include<QListWidgetItem>

videowindow::videowindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videowindow)
{
    ui->setupUi(this);
    on_volume_clicked();
    //readFile();


    mediaplayer = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    mediaplayer->setVideoOutput(ui->widget);
    mediaplayer->setPlaylist(playlist);
    //设置播放属性
    //监听
    connect(mediaplayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(mediaStateChange(QMediaPlayer::State)));
      //播放进度函数
    connect(mediaplayer,SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    connect(mediaplayer,SIGNAL(durationChanged(qint64)),this,SLOT(durationChanged(qint64)));
    connect(mediaplayer,SIGNAL(positionChanged1(qint64)),this,SLOT(positionChanged1(qint64)));
    //connect(mediaplayer,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(handleError()));
    connect(playlist,SIGNAL(currentIndexChanged(int)), this, SLOT(onPlaylistChanged(int)));

}

videowindow::~videowindow()
{
    delete ui;
}

void videowindow::on_back_bt_clicked()   // 返回主界面
{
    this->parentWidget()->show();
    this->hide();
}


void videowindow::play(){             //获取播放状态

    switch (mediaplayer->state()) {
    case QMediaPlayer::PlayingState:
        mediaplayer->pause();
        break;
    default:
         mediaplayer->play();
    break;
}
}
void videowindow::onPlaylistChanged(int position) //
{
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem  *item=ui->listWidget->currentItem();
    if (item)
        this->setWindowTitle(item->text());
}


void videowindow::setPosition(int position)     //获取进度条位置
{

    mediaplayer->setPosition(position);

}
void videowindow::durationChanged(qint64 duration)
{

    ui->horizontalSlider->setRange(0,duration);
}
 void videowindow::positionChanged(qint64 position)    //改变播放位置
 {

     ui->horizontalSlider->setValue(position);
 }



void videowindow::on_horizontalSlider_sliderMoved(int position)
{
    setPosition(position);
}

void videowindow::on_toolButton_clicked()    //播放
{
   play();
}


void videowindow::mediaStateChange(QMediaPlayer::State state)    //播放过程中调整动态函数
{

    switch (state) {
    case QMediaPlayer::PlayingState:
      ui->toolButton->setToolTip("暂停");
     // ui->toolButton->setIcon(QPixmap(":/new/prefix1/2.png"));
        break;
    default:
        ui->toolButton->setToolTip("播放");
       // ui->toolButton->setIcon(QPixmap(":/new/prefix1/1.png"));
        break;
    }
}

void videowindow::on_toolButton_5_clicked()   //打开文件
{
       QStringList fileList=QFileDialog::getOpenFileNames(this,QString::fromLocal8Bit("打开文件"),"D:/work/zrh/qtcore/car/video",tr("*.wmv *.mp3 *.avi"));

       if (fileList.count()<1)
            return;

       for (int i = 0; i<fileList.count();i++)
        {
           QString aFile=fileList.at(i);
           playlist->addMedia(QUrl::fromLocalFile(aFile));  //添加文件
           QFileInfo fileInfo(aFile);
           ui->listWidget->addItem(fileInfo.fileName()); //添加到界面文件列表
        }

       if (mediaplayer->state() != QMediaPlayer::PlayingState)
          playlist->setCurrentIndex(0);

       mediaplayer->play();

}


void videowindow::on_listWidget_doubleClicked(const QModelIndex &index)   // 双击文件名播放
{
        int rowNo=index.row();
        playlist->setCurrentIndex(rowNo);
        mediaplayer->play();

}


void videowindow::on_toolButton_8_clicked()  //上一个
{
    playlist->previous();

}

void videowindow::on_toolButton_9_clicked()  // down
{
    playlist->next();

}




void videowindow::on_toolButton_10_clicked()   //快进
{
   qint64 t;
   t = mediaplayer->position();
   t += 2000;
   mediaplayer->setPosition(t);
}





void videowindow::on_toolButton_11_clicked()  //快退
{
    qint64 t;
    t = mediaplayer->position();
    t -= 2000;
    mediaplayer->setPosition(t);
}




void videowindow::on_toolButton_4_clicked()   //静音
{
    bool mute=mediaplayer->isMuted();
    mediaplayer->setMuted(!mute);

   /* if (mute)
        ui->toolButton_4->setText("开启静音");
    else
        ui->toolButton_4->setText("关闭静音");*/
}


void videowindow::on_toolButton_3_clicked()
{
   mediaplayer->stop();
}


//void videowindow::readFile()
//{
//    path_video = "D:/work/zrh/qtcore/car/video";
//    QDir dir(path_video);

//    QStringList nameFileters;
//    nameFileters << "*.avi";
//    QStringList files = dir.entryList(nameFileters,QDir::Files|QDir::Readable,QDir::Name);

//    ui->listWidget->addItems(files);

//    ui->listWidget->sortItems();
//    qDebug()<<"我进来啦"<<endl;

//   // playlist = ui->listWidget->item(0);
//    //playlist->setCurrentIndex(0);
//}



void videowindow::on_volume_clicked() //声音按钮显示
{
    if(m_checked)
    {
        ui->vol_change->show();
        m_checked = false;//点击显示
        //qDebug()<<"check :"<<m_checked<<endl;
    }
    else
    {
        ui->vol_change->hide();
        m_checked = true;
       // qDebug()<<"check :"<<m_checked<<endl;
    }
}




void videowindow::on_vol_change_sliderMoved()
{
    mediaplayer->setVolume(ui->vol_change->value());
}
