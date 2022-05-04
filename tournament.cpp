#include "tournament.h"
#include "ui_tournament.h"


void tournament::refresh(player *a){
    if(a->getname()=="copycat"){
        a->myact = 1;
    }
    else if(a->getname()=="grudger"){
        a->evercheated = false;
        a->myact = 1;
    }
    else if(a->getname()=="detective"){
        a->myact  = 1;
        a->evercheated = false;
        a->t_act = 0;
    }
}

tournament::tournament(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tournament)
{
    ui->setupUi(this);
    list.append(&cat);
    list.append(&cht);
    list.append(&pk);
    list.append(&grd);
    list.append(&det);
}

void tournament::paintEvent(QPaintEvent *event){//直接用qtimer全部执行完
    QPainter painter(this);
        painter.setPen(QPen(Qt::yellow,4));//设置画笔形式
        QFont font2("楷体",10);
        painter.drawText(390,100,"复读机,得分："+QString::number(cat.my_score));
        //painter.drawText(390,100,"复读机");
        //painter.drawText(220,300,QString::number(cat.my_score));
        painter.drawLine(400,100,200,230);//画直线

        painter.drawLine(200,230,270,450);
        painter.drawLine(270,450,530,450);
        painter.drawLine(530,450,600,230);
        painter.drawLine(600,230,400,100);

        //painter.drawEllipse(20,20,200,200);//画圆
        //painter.drawRect(20,20,200,200);//画矩形
}

tournament::~tournament()
{
    delete ui;
}


void tournament::on_pushButton_clicked()
{
    while(list.length()>1){
        player* player_a =list.first();
        list.removeAt(0);
        for(auto curropt:list){
            battle(player_a,curropt);
            refresh(player_a);
            refresh(curropt);
        }
    }
    ui->spk->setText(QString::number(pk.my_score));
    ui->scht->setText(QString::number(cht.my_score));
    ui->sdet->setText(QString::number(det.my_score));
    ui->sgrd->setText(QString::number(grd.my_score));
    ui->scat->setText(QString::number(cat.my_score));
}
