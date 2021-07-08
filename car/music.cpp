#include "music.h"
#include "ui_music.h"
#include <QDebug>

music::music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,1);
    qDebug()<<"构造了music窗口"<<endl;
    this->show();
}

music::~music()
{
    delete ui;
}


void music::on_back_bt_clicked()
{
    emit sendsignal();
    this->close();
}

QSize music::sizeHint() const{
    return QSize(920,520);
}
