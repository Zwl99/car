#include "mapwindow.h"
#include "ui_mapwindow.h"

mapwindow::mapwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mapwindow)
{
    ui->setupUi(this);

   // this->ui->axWidget->setControl("D:/work/zrh/qtcore/car/map.html");

    qApp->setApplicationName("padcollectionclient");
    QString sFilePath = QCoreApplication::applicationDirPath();
    //qDebug()<<"path:"<<sFilePath<<endl;
    sFilePath += "/my.html";

    ui->lineEdit->setText(sFilePath);
    ui->axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));

    loadNavigate();
}

mapwindow::~mapwindow()
{
    delete ui;
}

void mapwindow::on_back_bt_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void mapwindow::loadNavigate()
{
    QString Utr = ui->lineEdit->text().trimmed();
    ui->axWidget->dynamicCall("Navigate(const QString&)",Utr);
}

