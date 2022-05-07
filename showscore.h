#ifndef SHOWSCORE_H
#define SHOWSCORE_H

#include <QMainWindow>
#include<tournament.h>
#include<QPainter>
#include <QStandardItemModel>
namespace Ui {
class showscore;
}

class showscore : public QMainWindow
{
    Q_OBJECT

public:
    explicit showscore(QWidget *parent = nullptr);
    ~showscore();
    void paintEvent(QPaintEvent*event);
    int score = 0;
    Ui::showscore *ui;
private slots:
    void on_pushButton_clicked();

private:
    tournament* trn  = new tournament;
};

#endif // SHOWSCORE_H
