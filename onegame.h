#ifndef ONEGAME_H
#define ONEGAME_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include<QKeyEvent>
#include<vector>
#include<QString>
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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_retry_clicked();

    void on_notice_clicked();

private:
    Ui::onegame *ui;
};

#endif // ONEGAME_H
