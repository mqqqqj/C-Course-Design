#ifndef LASTPAGE_H
#define LASTPAGE_H

#include <QMainWindow>
#include<QPainter>
#include <QCloseEvent>
#include<QMessageBox>
namespace Ui {
class lastpage;
}

class lastpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit lastpage(QWidget *parent = nullptr);
    ~lastpage();
    void paintEvent(QPaintEvent *event);
    void closeEvent( QCloseEvent * event);

private:
    Ui::lastpage *ui;
};

#endif // LASTPAGE_H
