#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QPushButton>


namespace Ui {
class music;
}

class music : public QWidget
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();


private slots:
    void on_back_bt_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息
private:
    QSize sizeHint() const;
private:
    Ui::music *ui;
};

#endif // MUSIC_H
