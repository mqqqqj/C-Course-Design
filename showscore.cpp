#include "showscore.h"
#include "ui_showscore.h"

showscore * p;

showscore::showscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showscore)
{
    ui->setupUi(this);
    p = this;
}

showscore::~showscore()
{
    delete ui;
}

void showscore::on_pushButton_clicked()
{
    trn->show();
    this->hide();
}
//尝试改成用鼠标点在某个区域内查看对应玩家的信息。
