#include "showscore.h"
#include "ui_showscore.h"

showscore * p;

showscore::showscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showscore)
{
    ui->setupUi(this);
    p = this;
    QStandardItemModel*model = new QStandardItemModel;   //创建一个标准的条目模型
    ui->tableView->setModel(model);   //将tableview设置成model这个标准条目模型的模板, model设置的内容都将显示在tableview上
    model->setRowCount(2);
    model->setHorizontalHeaderItem(0, new QStandardItem("玩家昵称"));
    model->setHorizontalHeaderItem(1, new QStandardItem("玩家策略"));
    model->setItem(0, 0, new QStandardItem("复读机(蓝帽子)"));
    model->setItem(0, 1, new QStandardItem("他会选择和玩家之前一模一样的选择。也就是说假如我一直合作，他也会一直合作，假如我一直欺骗，他也会一直欺骗。"));
    model->setItem(1, 0, new QStandardItem("老油条(紫灰帽子)"));
    model->setItem(1, 1, new QStandardItem("永远欺骗你，在只有两个人的世界里，他是无论怎么样都不可能输的。"));
    model->setItem(2, 0, new QStandardItem("小粉红(粉帽子)"));
    model->setItem(2, 1, new QStandardItem("永远相信别人的家伙。永远相信别人，即使你一直欺骗还是会相信你。"));
    model->setItem(3, 0, new QStandardItem("黑帮老铁(黄帽子)"));
    model->setItem(3, 1, new QStandardItem("一开始选择合作，试探对方态度。假如欺骗了他一次，他就会和你彻底翻脸，永不合作。"));
    model->setItem(4, 0, new QStandardItem("福尔摩星(侦探帽)"));
    model->setItem(4, 1, new QStandardItem("先会试探4局，分别为合作、欺骗、合作、合作，他会欺骗你一轮，假如你欺骗回去，他会像复读机一样以牙还牙，而假如你没有反过来欺骗回去，他会像千年老油条榨干你。"));
    this->ui->tableView->setColumnWidth(1, 300);
    ui->tableView->resizeRowsToContents();
}

showscore::~showscore()
{
    delete ui;
}

void showscore::paintEvent(QPaintEvent*event){
    QPixmap pixmap = QPixmap(":/image/background.png").scaled(this->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

void showscore::on_pushButton_clicked()
{
    trn->show();
    this->hide();
}
