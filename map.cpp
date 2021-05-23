#include "map.h"
#include "game.h"

extern Game * game;

Map::Map(int level, QGraphicsScene *sc)
{
    scene = sc;

    QString fileName = ":/maps/maps/" + QString::number(level) + ".txt";
    QFile file(fileName);
    if(!file.exists())
    {
        //finished the game
        QGraphicsSimpleTextItem *t = new QGraphicsSimpleTextItem("Congratulations, you have passed all the levels!");
        t->setPos(scene->width()/4, scene->height()/4);
        t->setBrush(QColor(64, 194, 252));
        QFont serifFont("Times", 14, QFont::Bold);
        t->setFont(serifFont);
        scene->addItem(t);
        return;
    }


    QTextStream in(&file);

    if (!file.open(QIODevice::ReadOnly))
    {
        //error
        QString temp = "Error while file reading: " + fileName;
        QGraphicsSimpleTextItem *t = new QGraphicsSimpleTextItem(temp);
        t->setPos(scene->width()/4, scene->height()/4);
        QFont serifFont("Times", 20, QFont::Bold);
        t->setFont(serifFont);
        scene->addItem(t);
        return;
    }

    char c;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            in >> c;
            while(c == '\n' || c == '\r') //skip endlines
                in >> c;

            int posy = i * 64;
            int posx = j * 64;
            switch(c)
            {
            case '+': //player standing on targer tile
                map[i][j] = new Cell(posx, posy, textures[MAP_TARGET], MAP_TARGET);
                game->player = new Player(posx, posy);
                scene->addItem(game->player);
                break;
            case 'p':
                map[i][j] = new Cell(posx, posy, textures[MAP_FLOOR], MAP_FLOOR);
                //create player            
                game->player = new Player(posx, posy);
                scene->addItem(game->player);
                break;

            case 'o':
                map[i][j] = new Cell(posx, posy, textures[MAP_FLOOR], MAP_FLOOR);
                candles.push_back(new Candle(posx, posy));
                scene->addItem(candles.last());
                //create stone
                break;
            case 'x':
                map[i][j] = new Cell(posx, posy, textures[MAP_TARGET], MAP_TARGET);
                //create target
                break;
            case '*':
                map[i][j] = new Cell(posx, posy, textures[MAP_WALL], MAP_WALL);
                //create wall
                break;
            case ' ':
                //create floor
                map[i][j] = new Cell(posx, posy, textures[MAP_FLOOR], MAP_FLOOR);
                break;
            }

            scene->addItem(map[i][j]);
        }
    }



    QString level_name = QString::number(level);
    QGraphicsSimpleTextItem *t = new QGraphicsSimpleTextItem("Level " + level_name);
    t->setBrush(QColor(64, 194, 252));
    QFont serifFont("Times", 12, QFont::Bold);
    t->setFont(serifFont);
    t->setPos(0, 0);
    scene->addItem(t);



    file.close();
}


Cell * Map::getCellByPos(int x, int y)
{
    return map[y/64][x/64];
}

Candle * Map::getCandleByPos(int x, int y)
{
   QVector<Candle *>::iterator iter = candles.begin();

   for(; iter != candles.end(); iter++)
   {
        if((*iter)->x() == x && (*iter)->y() == y)
            return *iter;
   }

   return nullptr;
}

bool Map::isCandleAtPos(int x, int y) const
{
    QVector<Candle *>::const_iterator iter = candles.begin();

    for(; iter != candles.end(); iter++)
    {
         if((*iter)->x() == x && (*iter)->y() == y)
             return true;
    }

    return false;
}

bool Map::isLevelFinished() const
{
    QVector<Candle *>::const_iterator iter = candles.begin();

    for(; iter != candles.end(); iter++)
    {
         if(!((*iter)->on_goal_))
             return false;
    }

    return true;
}

void Map::clear()
{
    candles.clear();
}

Map::~Map()
{

}
