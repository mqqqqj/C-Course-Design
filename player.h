#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QWidget>
#include <qdebug.h>
#include<QTime>
class player
{
public:
    player();
    bool myact ;
    bool evercheated = false;
    bool mylastchoie = 1;//一根筋需要记住上一次自己的选择
    int twocheat = 0;//复读鸭需要两次以上才反击
    int my_score = 0;
    int t_act = 0;

    bool getact() {return myact;};
    virtual QString getname() = 0;
    virtual QString getchinesename() = 0;
    virtual void act(bool opact) = 0;
};


class pink:public player{
public:
    pink(){myact  = 1;};
    QString getname(){
        //qDebug()<<"pink";
        return "pink";
    }
    QString getchinesename(){
        return "小粉红";
    }
    void act(bool opact){
        myact = 1;
        //qDebug()<<"opt act:"<<myact;
    }
};

class copycat:public player{
public:
    copycat(){
        myact  = 1;
    };
    QString getname(){
        //qDebug()<<"copycat";
        return "copycat";
    }
    QString getchinesename(){
        return "复读机";
    }
    void act(bool opact){
        if(opact)
            myact = 1;
        else
            myact = 0;
        //qDebug()<<"opt act:"<<myact;
    }
};

class grudger:public player{
public:
    grudger(){myact  = 1;evercheated = false;};
    QString getname(){
        //qDebug()<<"grudger";
        return "grudger";
    }
    QString getchinesename(){
        return "黑帮老铁";
    }
    void act(bool opact){
        //qDebug()<<"cheated？:"<<evercheated;
        if(opact==0)evercheated = true;
        if(evercheated){
            myact = 0;
            //qDebug()<<"opt act:"<<myact;
            return ;
        }
        myact = 1;
        //qDebug()<<"opt act:"<<myact;
    }
};

class cheater:public player{
public:
    cheater(){myact = 0;};
    QString getname(){
        //qDebug()<<"cheater";
        return "cheater";
    }
    QString getchinesename(){
        return "老油条";
    }
    void act(bool opact){
        myact = 0;
        //qDebug()<<"opt act:"<<myact;
    }
};

class detective:public player{
public:
    detective(){
        myact  = 1;
        evercheated = false;
        t_act = 0;
        mylogic = new bool[3]{0,1,1};
    };
    QString getname(){
        //qDebug()<<"detective";
        return "detective";
    }
    QString getchinesename(){
        return "福尔摩星";
    }
    bool *mylogic;
    void act(bool opact){
        if(t_act<3){
            myact = mylogic[t_act];
        }else{
            if(evercheated == true){
                if(opact == 1)
                    myact = 1;
                else
                    myact = 0;
            }else{
                myact = 0;
            }
        }
        t_act++;
        //qDebug()<<"opt act:"<<myact;
    }
};

class duck:public player{
public:
    duck(){
        myact = 1;
    }

    QString getname(){
        return "duck";
    }
    QString getchinesename(){
        return "复读鸭";
    }
    void act(bool opact){//计算这次是否选择合作
        if(opact){
            twocheat = 0;
            myact = 1;
        }else{
            twocheat++;
            if(twocheat>=2){
                myact = 0;
            }else{
                myact = 1;
            }
        }
        //qDebug()<<"opt act:"<<myact;
    }
};

class simple:public player{
public:
    simple(){myact  = 1;mylastchoie =1;};
    QString getname(){
        return "simple";
    }
    QString getchinesename(){
        return "一根筋";
    }
    void act(bool opact){
        if(opact){
            qDebug()<<"对手合作，我选择："<<myact;
            myact = mylastchoie;
        }
        else{
            if(mylastchoie){
                qDebug()<<"对手欺骗，我选择："<<myact;
                myact = 0;
            }
            else myact = 1;
        }
        mylastchoie = myact;
        //qDebug()<<"opt act:"<<myact;
    }
};


class rotten:public player{
public:
    rotten(){myact  = 1;};
    QString getname(){
        return "rotten";
    }
    QString getchinesename(){
        return "胡乱来";
    }
    void act(bool opact){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int x = qrand()%100;
        if(x%2==0){
            myact = 1;
        }else myact = 0;
        //qDebug()<<"opt act:"<<myact;
    }
};

#endif // PLAYER_H
