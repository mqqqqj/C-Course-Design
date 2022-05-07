#ifndef LASTPAGE_H
#define LASTPAGE_H

#include <QMainWindow>

namespace Ui {
class lastpage;
}

class lastpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit lastpage(QWidget *parent = nullptr);
    ~lastpage();

private:
    Ui::lastpage *ui;
};

#endif // LASTPAGE_H
