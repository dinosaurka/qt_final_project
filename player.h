#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QVector>

#include "statistics.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPoint getPosition READ getPosition WRITE setPosition)

public slots:
    void allowMove();
    //void updateTime();

public:
    bool canMove;

    Player(int x, int y);
    QPoint getPosition() const;
    void setPosition(QPoint p);
    void animate(int d_x, int d_y);
    void keyPressEvent(QKeyEvent *e);
    //void focusOutEvent(QFocusEvent* e);
    Statistics getStatistics();
//signals:
//    void unfinished(QTimer *tmr, QTime &time);
};

#endif // PLAYER_H
