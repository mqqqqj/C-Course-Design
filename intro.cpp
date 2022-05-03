#include "intro.h"
#include "ui_intro.h"

intro::intro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::intro)
{
    ui->setupUi(this);
}

intro::~intro()
{
    delete ui;
}


void intro::on_pushButton_clicked()
{
    og->show();
    this->hide();
}
