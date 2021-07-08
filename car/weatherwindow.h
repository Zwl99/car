#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVariantMap>
#include <QVariantList>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include <QNetworkReply>
#include <QPixmap>


namespace Ui {
class weatherwindow;
}

class weatherwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit weatherwindow(QWidget *parent = nullptr);
    ~weatherwindow();

private slots:
    void on_back_bt_clicked();
    void replyFinished(QNetworkReply *);

private:
    Ui::weatherwindow *ui;

    QNetworkAccessManager *manager;         //请求
    QLabel *dw[6];                          //日期
    QLabel *tpe1[6];                        //天气类型
    QLabel *hg[6];                          //最高温
    QLabel *lw[6];                          //最低温
};

#endif // WEATHERWINDOW_H
