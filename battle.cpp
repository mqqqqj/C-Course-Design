#include "battle.h"

battle::battle(player*a,player*b){
    bool ahistory(false) ,bhistory(false);
    for(int i = 0;i < 10;i ++){
        if(i >= 1){
            a->act(ahistory);
            b->act(bhistory);
        }
        if(a->getname()=="detective"){
            if(b->getact()==false)
                a->evercheated = true;
        }
        if(b->getname()=="detective"){
            if(a->getact()==false)
                b->evercheated = true;
        }
        ahistory = b->getact();
        bhistory = a->getact();
        if(a->getact()){
            if(b->getact()){
                a->my_score+=2;
                b->my_score+=2;
                qDebug()<<"2/2";

            }else{
                a->my_score-=1;
                b->my_score+=3;
                qDebug()<<"-1/3";
            }
        }else{
            if(b->getact()){
                a->my_score+=3;
                b->my_score-=1;
                qDebug()<<"3/-1";
            }else{
                qDebug()<<"0/0";
            }
        }
    }
    qDebug()<<a->my_score<<"--"<<b->my_score;
}
