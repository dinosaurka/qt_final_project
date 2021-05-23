#include "game.h"

extern Game * game;

Game::~Game()
{
    scene->clear();
    delete map;
    delete player;
}



Game::Game()
{

//    QPushButton *first_level_button = new QPushButton("first level", this);

//    first_level_button->setFixedSize(160, 40);
//    first_level_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    game = this;

    level = 1;

    scene = new QGraphicsScene();
    setScene(scene);

    const int d = 16*64;
    scene->setSceneRect(0, 0, d, d);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(d, d);


    map = new Map(level, scene);

//    QTime time(0, 0);

//    QTimer *timer = new QTimer(this);
//    //connect(timer, SIGNAL(process()), this, SLOT(updateTime(timer, time)));
//    //timer->start(1000);
//    updateTime(timer, time);
//    //timer->stop();

}

void Game::restartLevel()
{
    scene->clear();
    scene->update();

    map->clear();
    map = new Map(level, scene);
}

void Game::nextLevel()
{
    scene->clear();
    scene->update();

    level++;
    map->clear();
    map = new Map(level, scene);
}
