#include "player.h"
#include "game.h"
#include "map.h"
#include "cell.h"

#include <QPropertyAnimation>

extern Game * game;
//static QTime time_now(0, 0);
//static QTimer *timer = new QTimer(game);
//static QGraphicsSimpleTextItem *t;


Statistics game_stat;

void Player::keyPressEvent(QKeyEvent *event)
{


//        connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
//        timer->start(1000);
//        updateTime();

    if(game->map->isLevelFinished())
        return;

    int d_x = 0;
    int d_y = 0;
    int oldx = x();
    int oldy = y();
    bool need = false;

    switch(event->key())
    {
    case Qt::Key_E:
        game->nextLevel();
        return;
    case Qt::Key_R:
    case Qt::Key_Space:
        game->restartLevel();
        return;

    case Qt::Key_Left:
    case Qt::Key_A:
        d_x = -64;
        break;

    case Qt::Key_Right:
    case Qt::Key_D:
         d_x = 64;
        break;

    case Qt::Key_Up:
    case Qt::Key_W:
         d_y = -64;
        break;

    case Qt::Key_Down:
    case Qt::Key_S:
         d_y = 64;
        break;

    case Qt::Key_Z:{
        std::pair<int,int> pre_step = game_stat.reverseMovement();
        d_x = pre_step.first;
        d_y = pre_step.second;
        need = true;
        break;
    }
    default:
        break;
    }

//    if (need) {
//        Candle *st = game->map->getCandleByPos(oldx+d_x, oldy+d_y);
//        int typeMap = game->map->getCellByPos(oldx+(2*d_x), oldy+(2*d_y))->getType();
//        st->animateCandle(-d_x, -d_y, typeMap);

//    } else {
    if(!canMove) return;

    if(game->map->getCellByPos(oldx+d_x, oldy+d_y)->getType() == MAP_WALL)
        return;

    Candle *st = game->map->getCandleByPos(oldx+d_x, oldy+d_y);


    if(st != nullptr)
    {

        if(game->map->isCandleAtPos(oldx+(2*d_x), oldy+(2*d_y))) return;


        int typeMap = game->map->getCellByPos(oldx+(2*d_x), oldy+(2*d_y))->getType();


        switch(typeMap)
        {
            case MAP_WALL:
                return;
            case MAP_TARGET:
            case MAP_FLOOR:
            st->animateCandle(d_x, d_y, typeMap);
            break;
        }

    }

    canMove = false;
    //}

    game_stat.saveMovement(d_x, d_y);
    this->animate(d_x, d_y);

}

void Player::animate(int d_x, int d_y)
{
    QPoint startPosition(x(), y());
    QPoint endPosition((x()+d_x), (y()+d_y));

    QPropertyAnimation *a = new QPropertyAnimation(this, "getPosition");
    a->setStartValue(startPosition);
    a->setDuration(100);
    a->setEndValue(endPosition);
    a->start();

    connect(a, SIGNAL(finished()), this, SLOT(allowMove()));
}

void Player::allowMove()
{
    canMove = true;
}

QPoint Player::getPosition() const
{
    return QPoint(x(), y());
}

void Player::setPosition(QPoint p)
{
    setPos(p);
}

Player::Player(int x, int y) :
    QObject(),
    QGraphicsPixmapItem()
{
    canMove = true;
    setPos(x, y);
    setPixmap(QPixmap(":/images/sokoban_pics/hero.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setZValue(10);//display over other items
}

//void Player::focusOutEvent(QFocusEvent* e)
//{
//    setFocus();
//}

Statistics Player::getStatistics() {
    return game_stat;
}


//void Player::updateTime()

//{
//        //timer->start(0);
//        game->scene->removeItem(t);
//        time_now = time_now.addSecs(-1);
//        t = new QGraphicsSimpleTextItem(time_now.toString("mm:ss"));
//        t->setBrush(Qt::black);
//        t->setPos(0, 0);
//        game->scene->addItem(t);

//}

