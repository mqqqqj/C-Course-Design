#include "rpttournament.h"
#include "ui_rpttournament.h"

rpttournament::rpttournament(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rpttournament)
{
    ui->setupUi(this);
    ui->startgame->hide();
    ui->elim->hide();
    ui->repro->hide();
    ui->role->hide();
    ui->groupBox->hide();
    ui->stackedWidget->hide();
    ui->nextpage->hide();
    ui->showrole->hide();
    ui->setround->setMinimum(1);      // 设置滑动条的最小值
    ui->setround->setMaximum(50);   // 设置滑动条的最大值
    ui->setround->setValue(10); // 设置滑动条初始值
    ui->setelim->setMinimum(1);
    ui->setelim->setMaximum(10);
    ui->setelim->setValue(5);
    ui->setmistake->setMinimum(0);
    ui->setmistake->setMaximum(50);
    ui->setmistake->setValue(5);
    ui->setround->setPageStep(1);
    ui->setelim->setPageStep(1);
    ui->setmistake->setPageStep(1);
    ui->doublewin->setRange(-10,10);
    ui->doublewin->setValue(0);
    ui->doublewin->stepBy(1);
    ui->doublewin->setWrapping(true);

    ui->doublelose->setRange(-10,10);
    ui->doublelose->setValue(0);
    ui->doublelose->stepBy(1);
    ui->doublelose->setWrapping(true);

    ui->win->setRange(-10,10);
    ui->win->setValue(0);
    ui->win->stepBy(1);
    ui->win->setWrapping(true);

    ui->lose->setRange(-10,10);
    ui->lose->setValue(0);
    ui->lose->stepBy(1);
    ui->lose->setWrapping(true);

}

rpttournament::~rpttournament()
{
    delete ui;
}

bool rpttournament::comp( player* a, player*b){
    return a->my_score<b->my_score;
}

void rpttournament::refresh(player*a){
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
    else if(a->getname()=="simple"){
        a->mylastchoie = 1;
        a->myact = 1;
    }
    else if(a->getname()=="duck"){
        a->myact = 1;
        a->twocheat = 0;
    }
}

void rpttournament::paintEvent(QPaintEvent*event){
    QPixmap pixmap = QPixmap(":/image/white.png").scaled(this->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

void rpttournament::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->textBrowser->hide();
    ui->stackedWidget->show();
    ui->nextpage->show();
    ui->showrole->show();
    ui->startgame->show();
}

void rpttournament::on_showrole_clicked()
{
    ui->role->show();
}

void rpttournament::on_nextpage_clicked()
{
    int nIndex = ui->stackedWidget->currentIndex();
    nIndex++;
    nIndex=nIndex%3;
    ui->stackedWidget->setCurrentIndex(nIndex);
}

void rpttournament::on_pushButton_2_clicked()//设置玩家组成
{
    int a = ui->cat->text().toInt();
    int b = ui->cheater->text().toInt();
    int c = ui->pink->text().toInt();
    int d = ui->duck->text().toInt();
    int e = ui->detect->text().toInt();
    int f = ui->grudger->text().toInt();
    int g = ui->simple->text().toInt();
    int h = ui->rotten->text().toInt();
    int sum = a+b+c+d+e+f+g+h;
    if(sum!=25){
        QMessageBox::information(NULL,"Wrong input!","玩家组成总数错误，请更正输入。");
    }else{
        n_copycat = a;
        n_cheat = b;
        n_pink = c;
        n_duck = d;
        n_detective = e;
        n_grugder = f;
        n_simple = g;
        n_rotten = h;
        QMessageBox::information(NULL,"Congratulations!","设置成功。");
    }
    qDebug()<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<","<<g<<","<<h;
}

void rpttournament::on_rewarddone_clicked()//设置奖励值
{
    doublewin_reward = ui->doublewin->value();
    doublelose_reward =ui->doublelose->value();
    lose_reward = ui->lose->value();
    win_reward = ui->win->value();
    QMessageBox::information(NULL,"Congratulations!","设置成功。");
    qDebug()<<doublewin_reward<<","<<doublelose_reward<<","<<lose_reward<<","<<win_reward;

}


void rpttournament::on_done3_clicked()//设置犯错率，消减人数，对战轮数
{
    mis_rate = ui->setmistake->value()*1.0/100.0;
    n_eliminate = ui->setelim->value();
    round = ui->setround->value();
    qDebug()<<round<<","<<n_eliminate<<","<<mis_rate;
    ui->showset->setText(QString::number(round)+","+QString::number(n_eliminate)+","+QString::number(mis_rate));
    ui->showset->repaint();
    QMessageBox::information(NULL,"Congratulations!","设置成功。");
}

void rpttournament::on_startgame_clicked()//按下开始游戏按钮，groupbox显示，
{
    pink *pk = new pink[n_pink];
    cheater *cht = new cheater[n_cheat];
    detective *det = new detective[n_detective];
    copycat *cat = new copycat[n_copycat];
    grudger *grd = new grudger[n_grugder];
    duck *dk = new duck[n_duck];
    simple *sp = new simple[n_simple];
    rotten *rt = new rotten[n_rotten];
    player*pl[]={pk,cht,det,cat,grd,dk,sp,rt};
    int num[]={n_pink,n_cheat,n_detective,n_copycat,n_grugder,n_duck,n_simple,n_rotten};
    for(int i = 0;i < 8;i ++){
        for(int j = 0;j < num[i];j ++){
            list.append(&pl[i][j]);
            //qDebug()<<pl[i][j].getname();
        }
    }
    ui->groupBox->show();
    ui->startgame->hide();
    ui->nextpage->hide();
    ui->stackedWidget->hide();
    showresult();
}

void rpttournament::game(){//一局比赛，所有人两两对决round轮
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int k ,j;
    qDebug()<<"开始对局，列表长度："<<list.length();
    for(k = 0;k < 24;k ++){//前24个（0~23）玩家都可能是玩家a
        qDebug()<<"当前a玩家编号："<<k;
        for(j = k + 1;j < 25;j ++){//玩家b
            qDebug()<<"当前b玩家编号："<<j;
            player *a = list[k];
            player *b = list[j];
            qDebug()<<"获取双方姓名："<<a->getname()<<" vs "<<b->getname();
            bool ahistory(false) ,bhistory(false);
            for(int i = 0;i < round;i ++){//两名玩家进行round轮对决
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

                int x = qrand()%100;
                bool a_real_act,b_real_act;
                if(x<=mis_rate*100){//犯错
                    a_real_act = !a->getact();
                    b_real_act = !b->getact();

                }else{//正常决策
                    a_real_act = a->getact();
                    b_real_act = b->getact();
                }
                ahistory = b_real_act;
                bhistory = a_real_act;
                if(a_real_act){
                    if(b_real_act){
                        a->my_score+=doublewin_reward;
                        b->my_score+=doublewin_reward;
                        qDebug()<<"win/win";
                    }else{
                        a->my_score+=lose_reward;
                        b->my_score+=win_reward;
                        qDebug()<<"lose/win";
                    }
                }else{
                    if(b_real_act){
                        a->my_score+=win_reward;
                        b->my_score+=lose_reward;
                        qDebug()<<"win/lose";
                    }else{
                        a->my_score+=doublelose_reward;
                        b->my_score+=doublelose_reward;
                        qDebug()<<"lose/lose";
                    }
                }
            }
            //两名玩家进行round轮对决后，要将其进行参数复原。
            qDebug()<<"refresh "<<k<<","<<j;
            refresh(a);
            refresh(b);
        }
    }
    qSort(list.begin(), list.end(), comp);
    //所有玩家对局完后，显示结果
    qDebug()<<"进行显示";
    showresult();
    qDebug()<<"显示完成";
}

void rpttournament::showresult(){
    ui->showall->clear();
    ui->showall->repaint();
    ui->showscore->clear();
    ui->showscore->repaint();
    for(int i = 0;i < list.length();i ++){
        ui->showall->insertPlainText(list[i]->getchinesename()+",");
        ui->showscore->insertPlainText(QString::number(list[i]->my_score)+",");
    }
    ui->showall->repaint();
    ui->showscore->repaint();
    qDebug()<<"显示完成，列表长度："<<list.length();
}

void rpttournament::eliminate(){

    for(int i = 0;i < n_eliminate;i ++){
        list.removeAt(0);
    }
    for(int i = 0;i < list.length();i ++){
        list[i]->my_score = 0;
    }
    showresult();
}

void rpttournament::reproduce(){
    QString winners[n_eliminate];
    QHash<QString,int> hashtable;
    for(int i =0;i < n_eliminate;i ++){
        winners[i] = list[25-2*n_eliminate+i]->getname();
        if(hashtable.find(winners[i])==hashtable.end()){
            hashtable.insert(winners[i],1);
        }else hashtable.find(winners[i]).value()++;
    }
    QHash<QString, int>::const_iterator it;
    for(it=hashtable.constBegin();it!=hashtable.constEnd(); ++it){
        if(it.key()=="copycat"){
            copycat *obj=new copycat[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="pink"){
            pink *obj=new pink[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="duck"){
            duck *obj=new duck[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="detective"){
            detective *obj=new detective[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="grudger"){
            grudger *obj=new grudger[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="cheater"){
            cheater *obj=new cheater[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="simple"){
            simple *obj=new simple[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
        else if(it.key()=="rotten"){
            rotten *obj=new rotten[it.value()];
            for(int i = 0;i < it.value();i ++){
                list.append(&obj[i]);
            }
        }
    }
    showresult();

    /*
    QString winnername = list[24-n_eliminate]->getname();
    if(winnername=="copycat"){
        copycat *obj=new copycat[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="pink"){
        pink *obj=new pink[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="duck"){
        duck *obj=new duck[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="detective"){
        detective *obj=new detective[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="grudger"){
        grudger *obj=new grudger[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="cheater"){
        cheater *obj=new cheater[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="simple"){
        simple *obj=new simple[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    else if(winnername=="rotten"){
        rotten *obj=new rotten[n_eliminate];
        for(int i = 0;i < n_eliminate;i ++){
            list.append(&obj[i]);
        }
    }
    showresult();
    */
}

void rpttournament::on_end_clicked()
{
    list.clear();
    ui->groupBox->hide();
    ui->startgame->show();
    ui->nextpage->show();
    ui->stackedWidget->show();
}

void rpttournament::on_game_clicked()
{
    game();
    ui->game->hide();
    ui->elim->show();
}

void rpttournament::on_elim_clicked()
{
    eliminate();
    ui->elim->hide();
    ui->repro->show();
}

void rpttournament::on_repro_clicked()
{
    reproduce();
    ui->repro->hide();
    ui->game->show();
}
