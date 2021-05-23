#ifndef STATISTICS_H
#define STATISTICS_H

#include <QFile>
#include <QTextStream>
#include <QVector>

//-64, 64..
enum stepConsts
{
    STEP_LEFT = 0,
    STEP_RIGHT,
    STEP_UP,
    STEP_DOWN
};

class Statistics
{

    QVector <stepConsts> game_movements_;
    int number_of_movements_ = 0;
public:
    Statistics();
    void saveMovement(int d_x, int d_y);
    std::pair<int, int> reverseMovement();
    stepConsts lastMovement();
};

#endif // STATISTICS_H
