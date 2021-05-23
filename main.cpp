#include <QApplication>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game();

//    QFile styleF;

//    styleF.setFileName(":/style/style/style.css");
//    styleF.open(QFile::ReadOnly);
//    QString qssStr = styleF.readAll();
//    game->setStyleSheet(qssStr);

    game->show();

    return app.exec();
}
