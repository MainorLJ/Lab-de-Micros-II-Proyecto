#include "health.h"
#include "game.h"
#include <QFont>
#include <QGraphicsScene>
#include <QImage>
#include <QGraphicsView>

extern Game *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    if(health==0){
        game->setForegroundBrush(QBrush(QImage(":/images/gameover.jpg")));
    }
    else{
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}}

int Health::getHealth(){
    return health;
}
