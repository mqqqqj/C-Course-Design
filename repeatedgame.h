#ifndef REPEATEDGAME_H
#define REPEATEDGAME_H

#include <QMainWindow>
#include <player.h>
#include <QTimer>
#include <QTime>
#include <QList>
#include<qdebug.h>
#include<showscore.h>
#include "ui_showscore.h"
#include<QPainter>
extern showscore *p;

namespace Ui {
class repeatedgame;
}

class repeatedgame : public QMainWindow
{
    Q_OBJECT

public:
    explicit repeatedgame(QWidget *parent = nullptr);
    ~repeatedgame();
    void paintEvent(QPaintEvent*event);
    void startgame(player*opt);
    void getresult(player* opt);
    QString displayopt(int x);
    bool my_act = 1;
    bool my_last_act = my_act;
    int mytotal = 0;
    int mycurrscore = 0;
    int currround = 0;
    int round = 0;
    int num_fighted = 0;
    copycat obj1;//创建五个对手对象
    cheater obj2;
    pink obj3;
    grudger obj4;
    detective obj5;
    QList<player*> optlist;
    player* curropt = nullptr;

private slots:
    void on_coop_clicked();

    void on_cheat_clicked();

    void on_summary_clicked();

private:
    Ui::repeatedgame *ui;
    showscore* sc = new showscore;
};

#endif // REPEATEDGAME_H
