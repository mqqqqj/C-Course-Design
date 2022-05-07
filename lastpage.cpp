#include "lastpage.h"
#include "ui_lastpage.h"

lastpage::lastpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lastpage)
{
    ui->setupUi(this);
}

lastpage::~lastpage()
{
    delete ui;
}
