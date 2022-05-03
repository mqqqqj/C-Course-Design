#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QWidget>

class player
{
public:
    player();
    int my_score = 0;
    virtual void act(bool opact) = 0;
};

#endif // PLAYER_H
