#include "musicwindow.h"
#include "ui_musicwindow.h"
#include <QDebug>

musicwindow::musicwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicwindow)
{
    ui->setupUi(this);
    //读取文件
    readFile();
  //  on_playbtn_2_clicked();
    on_musicListRowNum(0);
    //初始化界面
    initUI();
    on_volume_clicked();
}

musicwindow::~musicwindow()
{
    delete ui;
}

void musicwindow::readFile()
{
    //设置遍历的目录
    str_pathmusic = "D:/work/zrh/qtcore/car/music";
    QDir dir(str_pathmusic);


    //设置文件过滤器
    QStringList nameFileters;
    //设置文件过滤器的格式
    nameFileters << "*.mp3";
    //将过滤后的文件名存入到list 中
    QStringList files = dir.entryList(nameFileters,QDir::Files|QDir::Readable,QDir::Name);
    //添加到listwidget中item中
    ui->list_music_2->addItems(files);
    //把item加入到listwidget中
    ui->list_music_2->sortItems();
    /*QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("D:\\work\\zrh\\qtcore\\car\\music\\4円 (ヨエン) - アイロニ (反语).mp3"));
    player->setVolume(100);
    player->play();*/

    p_item = ui->list_music_2->item(0);
    //qDebug()<<"music name:"<<p_item->text();
    p_item->setSelected(true);
    // p_player = new QMediaPlayer(this);
    connect(ui->list_music_2,SIGNAL(currentRowChanged(int)),this,SLOT(on_musicListRowNum(int)));
}
void musicwindow::on_musicListRowNum(int n_number)
{
   // qDebug()<<n_number;
   // qDebug()<<ui->list_music_2->item(n_number)->text()<<endl;
    str_music = ui->list_music_2->item(n_number)->text();
    p_player = new QMediaPlayer(this);
    p_player->setMedia(QUrl::fromLocalFile(str_pathmusic +'/'+str_music));
    //qDebug()<<str_music<<" "<<str_pathmusic<<endl;
    p_player->setVolume(100);
    //p_player->stop();
    n_music_number = n_number;
   // qDebug()<<"b:"<<b_play_music<<endl;
}



void musicwindow::on_back_bt_clicked()
{
    this->parentWidget()->show();
    this->hide();
}
void musicwindow::initUI()
{

}


void musicwindow::on_playbtn_2_clicked()
{
        //qDebug()<<"b_play          _music = " << b_play_music <<endl;
        if(b_play_music)
        {

            ui->playbtn_2->setStyleSheet(QString("QPushButton#playbtn_2{border-image: url(:/new/prefix1/images/play2.png); background-color: transparent;}"));
    //      ui->playbtn->setStyleSheet(QString("border-image: url(:/new/prefix1/pause2.png);"));
            b_play_music = false;
            p_player->pause();

        }
        else
        {
            ui->playbtn_2->setStyleSheet(QString("QPushButton#playbtn_2{border-image: url(:/new/prefix1/images/pause2.png); background-color: transparent;}"));
    //      ui->playbtn->setStyleSheet(QString("border-image: url(:/new/prefix1/play2.png);"));
            b_play_music = true;
            p_player->play();
           // qDebug()<<"b_play          _music = " << b_play_music <<endl;

        }
}

void musicwindow::on_upbtn_2_clicked()
{
    // p_player->stop();
     if(n_music_number == 0)
     {
         int nMax = ui->list_music_2->count();
         //qDebug()<<nMax;
         str_music = ui->list_music_2->item(nMax - 1)->text();
         p_item = ui->list_music_2->item(nMax - 1);
         p_item->setSelected(true);

         QString str = str_pathmusic + '/' +str_music;
         p_player->setMedia(QUrl::fromLocalFile(str));
         p_player->setVolume(100);
         p_player->stop();
         n_music_number = nMax - 1;

     }
     else
     {

         str_music = ui->list_music_2->item(n_music_number - 1)->text();
         p_item = ui->list_music_2->item(n_music_number - 1);
         p_item->setSelected(true);

         QString str = str_pathmusic + '/' +str_music;
         p_player->setMedia(QUrl::fromLocalFile(str));
         p_player->setVolume(100);
         p_player->stop();
         n_music_number -= 1;

     }


}

void musicwindow::on_down_btn_clicked()
{
    int nMax = ui->list_music_2->count();
    if(n_music_number == (nMax - 1))
    {
        str_music = ui->list_music_2->item(0)->text();
        p_item = ui->list_music_2->item(0);
        p_item->setSelected(true);

        QString str = str_pathmusic + '/' +str_music;
        p_player->setMedia(QUrl::fromLocalFile(str));
        p_player->setVolume(100);
        p_player->stop();
        n_music_number = 0;
    }
    else
    {
        str_music = ui->list_music_2->item(n_music_number + 1)->text();
        p_item = ui->list_music_2->item(n_music_number + 1);
        p_item->setSelected(true);

        QString str = str_pathmusic + '/' +str_music;
        p_player->setMedia(QUrl::fromLocalFile(str));
        p_player->setVolume(100);
        p_player->stop();
        n_music_number += 1;
    }

}


void musicwindow::on_volume_clicked()
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

void musicwindow::on_vol_change_sliderMoved()
{
    p_player->setVolume(ui->vol_change->value());
}

/*void musicwindow::on_toolButton_5_clicked()
{
    QStringList fileList=QFileDialog::getOpenFileNames(this,QString::fromLocal8Bit("打开文件"),"D:/",tr("*.mp3"));

   if (fileList.count()<1)
        return;

    for (int i=0; i<fileList.count();i++)
    {
       QString aFile=fileList.at(i);
       playlist->addMedia(QUrl::fromLocalFile(aFile));  //添加文件
       QFileInfo fileInfo(aFile);
       ui->list_music_2->addItem(fileInfo.fileName()); //添加到界面文件列表
    }
   if(p_player->state() != QMediaPlayer::PlayingState)
        playlist->setCurrentIndex(0);
    p_player->play();
}*/
