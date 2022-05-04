#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QWidget>
#include <qdebug.h>
class player
{
protected:
    bool myact = 1;
public:
    player();
    int my_score = 0;
    bool getact() {return myact;};
    virtual QString getname() = 0;
    virtual void act(bool opact) = 0;
};


class pink:public player{
public:
    QString getname(){
        qDebug()<<"pink";
        return "pink";
    }
    void act(bool opact){
        myact = 1;
        qDebug()<<"opt act:"<<myact;
    }
};

class copycat:public player{
public:
    QString getname(){
        qDebug()<<"copycat";
        return "copycat";
    }
    void act(bool opact){
        if(opact)
            myact = 1;
        else
            myact = 0;
        qDebug()<<"opt act:"<<myact;
    }
};

class grudger:public player{
public:
    QString getname(){
        qDebug()<<"grudger";
        return "grudger";
    }
    bool evercheated = false;
    void act(bool opact){
        if(opact==0)evercheated = true;
        if(evercheated){
            myact = 0;
            qDebug()<<"opt act:"<<myact;
            return ;
        }
        myact = 1;
        qDebug()<<"opt act:"<<myact;
    }
};

class cheater:public player{
protected:
    bool myact = 0;
public:

    QString getname(){
        qDebug()<<"cheater";
        return "cheater";
    }
    void act(bool opact){
        myact = 0;
        qDebug()<<"opt act:"<<myact;
    }
};

class detective:public player{
public:
    QString getname(){
        qDebug()<<"detective";
        return "detective";
    }
    int t_act = 0;
    bool evercheated = false;
    bool mylogic[4] ={1,0,1,1};
    void act(bool opact){
        if(t_act<4){
            if(opact==0)evercheated = true;
            myact = mylogic[t_act];
        }else{
            if(evercheated == false){
                if(opact == 1)
                    myact = 1;
                else
                    myact = 0;
            }else{
                myact = 0;
            }
        }
        t_act++;
        qDebug()<<"opt act:"<<myact;
    }
};

#endif // PLAYER_H
