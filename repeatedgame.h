#ifndef REPEATEDGAME_H
#define REPEATEDGAME_H

#include <QMainWindow>

namespace Ui {
class repeatedgame;
}

class repeatedgame : public QMainWindow
{
    Q_OBJECT

public:
    explicit repeatedgame(QWidget *parent = nullptr);
    ~repeatedgame();

private:
    Ui::repeatedgame *ui;
};

#endif // REPEATEDGAME_H
