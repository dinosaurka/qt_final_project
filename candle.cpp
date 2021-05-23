#include "candle.h"
#include <QTimer>
#include <QPropertyAnimation>
#include "game.h"


extern Game * game;


Candle::Candle(int x, int y):
    QObject(),
    QGraphicsPixmapItem()
{
        setPos(x, y);
        setPixmap(QPixmap(":/images/sokoban_pics/candle_fire.png"));
        setZValue(5);
        on_goal_ = false;
}

void Candle::setOnGoalAndCheckIsLevelFinished()
{
    this->setOnPlace();
    if(game->map->isLevelFinished())
    {
        QTimer::singleShot(800, game, &Game::nextLevel);
    }
}

void Candle::setOnPlace()
{
    on_goal_ = true;
    setPixmap(QPixmap(":/images/sokoban_pics/candle.png"));
}

void Candle::unSetOnGoal()
{
    if(!on_goal_) return;

    on_goal_ = false;
    setPixmap(QPixmap(":/images/sokoban_pics/goal_tile.png"));
}

QPoint Candle::getPosition() const
{
    return QPoint(x(), y());
}

void Candle::setPosition(QPoint p)
{
    setPos(p);
}

void Candle::animateCandle(int d_x, int d_y, int typeMap)
{
    QPoint startPosition(x(), y());
    QPoint endPosition((x()+d_x), (y()+d_y));

    QPropertyAnimation *s_a = new QPropertyAnimation(this, "getPosition");
    s_a->setStartValue(startPosition);
    s_a->setDuration(100);
    s_a->setEndValue(endPosition);
    s_a->start();

    if(typeMap == MAP_TARGET)
        connect(s_a, SIGNAL(finished()), this, SLOT(setOnGoalAndCheckIsLevelFinished()));
    else
        connect(s_a, SIGNAL(finished()), this, SLOT(unSetOnGoal()));
}
