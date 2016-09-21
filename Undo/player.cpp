#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QImage>
#include "bullet.h"
#include "enemy.h"
#include "game.h"


extern Game *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 780)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+50,y()-15);
        scene()->addItem(bullet);
    }
}


