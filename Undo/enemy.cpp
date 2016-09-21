#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>   //rand() ->really large int
#include "game.h"

extern Game * game;

Enemy::Enemy(): QObject(),QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/bloque.png"));

}

