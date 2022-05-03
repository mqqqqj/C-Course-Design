#include "repeatedgame.h"
#include "ui_repeatedgame.h"

repeatedgame::repeatedgame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::repeatedgame)
{
    ui->setupUi(this);
}

repeatedgame::~repeatedgame()
{
    delete ui;
}
