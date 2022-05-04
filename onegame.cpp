#include "onegame.h"
#include "ui_onegame.h"

onegame::onegame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::onegame)
{
    ui->setupUi(this);
    ui->noticetext->hide();
}

onegame::~onegame()
{
    delete ui;
}

void onegame::on_pushButton_2_clicked(){
    QFont font;
    font.setPointSize(12);//字体大小
    ui->myscore->setFont(font);
    ui->opscore->setFont(font);
    if(isopcheat){
        ui->myscore->setText("-1");
        ui->opscore->setText("+3");
    }
    else{
        ui->myscore->setText("+2");
        ui->opscore->setText("+2");
    }
}

void onegame::on_pushButton_clicked()
{
    QFont font;
    font.setPointSize(12);//字体大小
    ui->myscore->setFont(font);
    ui->opscore->setFont(font);
    if(isopcheat){
        ui->myscore->setText("0");
        ui->opscore->setText("0");
    }
    else{
        ui->myscore->setText("+3");
        ui->opscore->setText("-1");
    }
}

void onegame::on_retry_clicked()
{
    QFont font;
    font.setPointSize(18);//字体大小
    ui->label_2->setFont(font);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->label_2->setPalette(pe);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int x=qrand()%100;
    if(x%2==0){
        isopcheat = false;
        ui->label_2->setText("合作（投币）");
    }else{
        isopcheat = true;
        ui->label_2->setText("欺骗（不投币）");
    }
}

void onegame::on_notice_clicked()
{
    ui->noticetext->show();
}

void onegame::on_pushButton_3_clicked()
{
    repg->show();
    this->hide();
}
