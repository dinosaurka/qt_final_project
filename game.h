#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QEvent>
#include <QObject>
#include <QTime>
#include <QPushButton>

#include "map.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public slots:
     void nextLevel();
     //void updateTime(QTimer *tmr, QTime &time);
//signals:
//     void process();
public:
    Game();
    ~Game();
    void restartLevel();

    Player *player;
    QGraphicsScene *scene;
    Map *map;
    int level;
};

#endif // GAME_H
