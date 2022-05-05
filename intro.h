#ifndef INTRO_H
#define INTRO_H

#include <QMainWindow>
#include "onegame.h"
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class intro; }
QT_END_NAMESPACE

class intro : public QMainWindow
{
    Q_OBJECT

public:
    intro(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~intro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::intro *ui;
    onegame *og = new onegame;
};
#endif // INTRO_H
