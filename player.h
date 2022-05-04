#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QWidget>
#include <qdebug.h>
class player
{
public:
    player();
    bool myact ;
    bool evercheated = false;
    int my_score = 0;
    int t_act = 0;
    bool getact() {return myact;};
    virtual QString getname() = 0;
    virtual void act(bool opact) = 0;
};


class pink:public player{
public:
    pink(){myact  = 1;};
    QString getname(){
        //qDebug()<<"pink";
        return "pink";
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
    void act(bool opact){
        myact = 0;
        //qDebug()<<"opt act:"<<myact;
    }
};

class detective:public player{
public:
    detective(){myact  = 1;evercheated = false;t_act = 0;};
    QString getname(){
        //qDebug()<<"detective";
        return "detective";
    }
    bool mylogic[3] ={0,1,1};
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

#endif // PLAYER_H
