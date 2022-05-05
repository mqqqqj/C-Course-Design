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

void intro::paintEvent(QPaintEvent *event){
    QPixmap pixmap = QPixmap(":/image/background.png").scaled(this->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

void intro::on_pushButton_clicked()
{
    og->show();
    this->hide();
}
