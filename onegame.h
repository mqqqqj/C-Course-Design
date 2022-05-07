#ifndef ONEGAME_H
#define ONEGAME_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include<QString>
#include <repeatedgame.h>
namespace Ui {
class onegame;
}

class onegame : public QMainWindow
{
    Q_OBJECT

public:
    explicit onegame(QWidget *parent = nullptr);
    ~onegame();
    bool isopcheat = true;
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_retry_clicked();

    void on_notice_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::onegame *ui;
    repeatedgame* repg = new repeatedgame;

};

#endif // ONEGAME_H
