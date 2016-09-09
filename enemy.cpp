#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>   //rand() ->really large int
#include "game.h"

extern Game * game;

Enemy::Enemy(): QObject(),QGraphicsRectItem()
{

    setRect(0,0,45,10);

}

