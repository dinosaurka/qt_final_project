#ifndef MAP_H
#define MAP_H

#include <QGraphicsPixmapItem>
#include <QFile>
#include <QGraphicsScene>
#include <QVector>
#include <QTextStream>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QTimer>
#include <QTime>

#include "player.h"
#include "cell.h"
#include "candle.h"

enum mapConsts
{
    MAP_FLOOR = 0,
    MAP_WALL,
    MAP_TARGET
};

class Map
{
private:
    Cell *map[16][16];
    QGraphicsScene *scene;
    QString textures[3] =
    {
        ":/images/sokoban_pics/tile.png",
        ":/images/sokoban_pics/brick.png",
        ":/images/sokoban_pics/goal_tile.png"
    };
public:
    QVector<Candle *> candles;
    Map(int level, QGraphicsScene *sc);
    ~Map();
    Cell * getCellByPos(int x, int y);
    Candle * getCandleByPos(int x, int y);
    bool isCandleAtPos(int x, int y) const;
    bool isLevelFinished() const;
    void clear();
    //void updateTime(QTimer *tmr, QTime &time);

};



#endif // MAP_H
