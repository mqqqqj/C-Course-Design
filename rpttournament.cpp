#include "rpttournament.h"
#include "ui_rpttournament.h"

rpttournament::rpttournament(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rpttournament)
{
    ui->setupUi(this);
    ui->startgame->hide();
    ui->role->hide();
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

}

rpttournament::~rpttournament()
{
    delete ui;
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

void rpttournament::on_pushButton_2_clicked()
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

void rpttournament::on_rewarddone_clicked()
{
    doublewin_reward = ui->doublewin->value();
    doublelose_reward =ui->doublelose->value();
    lose_reward = ui->lose->value();
    win_reward = ui->win->value();
    QMessageBox::information(NULL,"Congratulations!","设置成功。");
    qDebug()<<doublewin_reward<<","<<doublelose_reward<<","<<lose_reward<<","<<win_reward;

}


void rpttournament::on_done3_clicked()
{
    mis_rate = ui->setmistake->value()*1.0/100.0;
    n_eliminate = ui->setelim->value();
    round = ui->setround->value();
    qDebug()<<round<<","<<n_eliminate<<","<<mis_rate;
    ui->showset->setText(QString::number(round)+","+QString::number(n_eliminate)+","+QString::number(mis_rate));
    ui->showset->repaint();
    QMessageBox::information(NULL,"Congratulations!","设置成功。");
}

void rpttournament::on_startgame_clicked()
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
    for(auto a:list){
        qDebug()<<a->getname();
    }
}
