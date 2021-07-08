#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMainWindow>
#include <QAxObject>
#include <QDebug>
//CONFIG   += qaxcontainer

namespace Ui {
class mapwindow;
}

class mapwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mapwindow(QWidget *parent = nullptr);
    ~mapwindow();

private slots:
    void on_back_bt_clicked();
    void loadNavigate();

private:
    Ui::mapwindow *ui;
};

#endif // MAPWINDOW_H
