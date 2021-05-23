#ifndef CANDLE_H
#define CANDLE_H


#include <QGraphicsPixmapItem>
#include <QObject>


class Candle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPoint getPosition READ getPosition WRITE setPosition)

public slots:
    void unSetOnGoal();
    void setOnGoalAndCheckIsLevelFinished();
public:
    QPoint getPosition() const;
    void setPosition(QPoint p);
    Candle(int x, int y);
    void setOnPlace();
    void animateCandle(int x, int y, int type);

    bool on_goal_;
};

#endif // CANDLE_H
