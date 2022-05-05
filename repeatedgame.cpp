#include "repeatedgame.h"
#include "ui_repeatedgame.h"

repeatedgame::repeatedgame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::repeatedgame)
{
    ui->setupUi(this);
    ui->summary->hide();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    round = qrand()%5+3;//初始化和第一个对手的对战轮数
    //qDebug() << "total round !"<<round;
    optlist.append(&obj1);
    optlist.append(&obj2);
    optlist.append(&obj3);
    optlist.append(&obj4);
    optlist.append(&obj5);
    curropt = optlist.first();//当前的对手对象
    curropt->getname();
}

repeatedgame::~repeatedgame()
{
    delete ui;
}


void repeatedgame::paintEvent(QPaintEvent*event){
    QPixmap pixmap = QPixmap(":/image/background.png").scaled(this->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

QString repeatedgame::displayopt(int x){
    switch(x){
    case 1:
        return ":/image/cheater.png";
    case 2:
        return ":/image/pink.png";
    case 3:
        return ":/image/grudger.png";
    case 4:
        return ":/image/detective.png";
    }
}

void repeatedgame::getresult(player* opt){//计算得分结果
    opt->getname();
    bool optchoice = opt->getact();
    //qDebug()<<"cheater你到底投币了没:"<<optchoice;
    if(my_act){
        if(optchoice){
            mycurrscore+=2;
            mytotal+=2;
            opt->my_score+=2;
            qDebug()<<"双赢";
        }else{
            mycurrscore-=1;
            mytotal-=1;
            opt->my_score+=3;
            qDebug()<<"我输";
        }
    }else{
        if(optchoice){
            mycurrscore+=3;
            mytotal+=3;
            opt->my_score-=1;
            qDebug()<<"我赢";
        }else{
            qDebug()<<"无变化";
        }
    }
}


void repeatedgame::on_coop_clicked()//我选择合作
{
    QFont font;
    font.setPointSize(15);//字体大小
    ui->mycurr->setFont(font);
    ui->optcurr->setFont(font);
    //qDebug() << "curr round !"<<currround;
    my_act = 1;
    qDebug() << "我选择合作!";
    if(currround<round){//如果还没到最大轮数
        if(currround>=1){//如果不是第一轮
            curropt->act(my_last_act);//让对手根据我上一次行动来获取当前的选择，这里有问题,对象要写到头文件里
            //qDebug() << "opt get act finished!";
        }
        getresult(curropt);
        //qDebug() << "one fight has finished !";
        my_last_act = my_act;
        ui->optchoice->setText("对手是否选择合作："+QString::number(curropt->getact()));
    }
    currround++;
    ui->mycurr->setText(QString::number(mycurrscore));
    ui->optcurr->setText(QString::number(curropt->my_score));
    ui->mytotalscore->setText(QString::number(mytotal));
    if(currround==round){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        round = qrand()%5+3;
        //qDebug() << "change total round !"<<round;
        currround = 0;
        num_fighted++;
        optlist.removeAt(0);
        if(optlist.isEmpty()==false){
            //qDebug() << "change opt !";
            curropt = optlist.first();
            curropt->getname();
            ui->optid->setText("对手"+QString::number(num_fighted+1)+"/5");
            ui->mycurr->setText(QString::number(0));
            ui->optcurr->setText(QString::number(0));
            ui->optpicture->setPixmap(QPixmap(displayopt(num_fighted)));
            mycurrscore = 0;
        }
        else{
            //qDebug()<<"end";
            ui->cheat->hide();
            ui->coop->hide();
            ui->summary->show();
        }
    }
}



void repeatedgame::on_cheat_clicked()
{
    QFont font;
    font.setPointSize(15);//字体大小
    ui->mycurr->setFont(font);
    ui->optcurr->setFont(font);
    my_act = 0;
    qDebug() << "我选择欺骗!";

    //qDebug() << "curr round !"<<currround;
    if(currround<round){//如果还没到最大轮数
        if(currround>=1){//如果不是第一轮
            curropt->act(my_last_act);//让对手根据我上一次行动来获取当前的选择，这里有问题
        }
        getresult(curropt);
        curropt->evercheated = true;
        //qDebug() << "one fight has finished !";
        my_last_act = my_act;
        ui->optchoice->setText("对手是否选择合作："+QString::number(curropt->getact()));
    }
    currround++;
    ui->mycurr->setText(QString::number(mycurrscore));
    ui->optcurr->setText(QString::number(curropt->my_score));
    ui->mytotalscore->setText(QString::number(mytotal));
    if(currround==round){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        round = qrand()%5+3;
        //qDebug() << "change total round !"<<round;
        currround = 0;
        num_fighted++;
        optlist.removeAt(0);
        if(optlist.isEmpty()==false){
            //qDebug() << "change opt !";
            curropt = optlist.first();
            curropt->getname();
            ui->optid->setText("对手"+QString::number(num_fighted+1)+"/5");
            ui->mycurr->setText(QString::number(0));
            ui->optcurr->setText(QString::number(0));
            mycurrscore = 0;
            ui->optpicture->setPixmap(QPixmap(displayopt(num_fighted)));
        }
        else{
            //qDebug()<<"end";
            ui->cheat->hide();
            ui->coop->hide();
            ui->summary->show();
        }
    }
}

void repeatedgame::on_summary_clicked()
{
   QFont font;
   font.setPointSize(20);//字体大小
   p->ui->myscore->setFont(font);
   p->ui->myscore->setText("你最终的得分是："+QString::number(mytotal)+",理论的分数区间是[7,49]。");
   sc->show();
   this->hide();
}
