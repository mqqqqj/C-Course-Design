#ifndef RPTTOURNAMENT_H
#define RPTTOURNAMENT_H

#include <QMainWindow>
#include <QPainter>
#include"player.h"
#include<QList>
#include <QWidget>
#include <QStackedWidget>
#include<QMessageBox>
#include<QDebug>
#include<QTime>
#include<QHash>
#include<QMap>
namespace Ui {
class rpttournament;
}

class rpttournament : public QMainWindow
{
    Q_OBJECT

public:
    explicit rpttournament(QWidget *parent = nullptr);
    ~rpttournament();
    void paintEvent(QPaintEvent*event);
    void game();
    void eliminate();
    void reproduce();
    void refresh(player*a);
    void showresult();
    QList<player*>list;
    static bool comp( player* a, player*b);
    //设置玩家数量
    int n_copycat = 3;
    int n_cheat = 3;
    int n_pink = 6;
    int n_grugder = 3;
    //int n_detective = 0;
    int n_duck =3;
    int n_simple = 3;
    int n_rotten = 4;

    //初始化参数
    float mis_rate = 0.05;
    int doublewin_reward = 2;
    int doublelose_reward = 0;
    int win_reward = 3;
    int lose_reward = -1;
    int n_eliminate = 5;
    int round = 10;
private slots:
    void on_pushButton_clicked();

    void on_showrole_clicked();

    void on_nextpage_clicked();

    void on_pushButton_2_clicked();

    void on_rewarddone_clicked();

    void on_done3_clicked();

    void on_startgame_clicked();

    void on_end_clicked();

    void on_game_clicked();

    void on_elim_clicked();

    void on_repro_clicked();

private:
    Ui::rpttournament *ui;
    QStackedWidget *stackedWidget;
};

#endif // RPTTOURNAMENT_H
