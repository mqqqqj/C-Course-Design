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

void lastpage::paintEvent(QPaintEvent *event){
    QPixmap pixmap = QPixmap(":/image/love.png").scaled(this->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

void lastpage::closeEvent( QCloseEvent * event ){
switch( QMessageBox::information( this, tr("exit tip"), tr("Do you really want exit?"), tr("Yes"), tr("No"), 0, 1 ) )
   {
     case 0:
          event->accept();
          break;
     case 1:
     default:
         event->ignore();
         break;
   }
}

