#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "player.h"

extern Game *game;
int A=10;
int B=-10;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(50,0,2,5);

    //connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);           //Velocidad de la bola
}

void Bullet::move(){
    QList<QGraphicsItem *> colliding_items=collidingItems();
    //if one of the colliding item is an Enemy, destroy Enemy
    for (int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==((typeid(Enemy)))){
            //rebote
            B=B*(-1);
            //aumento el puntaje
            game->score->increase();
            //remove then both
            scene()->removeItem(colliding_items[i]);
            //-scene()->removeItem(this);
            //-delete the both
            delete colliding_items[i];
            //-delete this;
            return;
        }
        else if (typeid(*(colliding_items[i]))==((typeid(Player)))){
            //rebote
            B=B*(-1);
        }
    }


    if(pos().y()+rect().height() <0){
            B=B*(-1);
    }
    else if (pos().y()-rect().height()>580){
            //B=B*(-1)
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
}
    else if ((pos().x()<-50)||(pos().x()>735)){
            A=A*(-1);
}
    //else if (pos().x()>735){
 //           A=A*(-1);
//}
    else if (pos().x()==735 && pos().y()+rect().height() ==0){
        A=A*(-1);
        B=B*(-1);
}
    else if (pos().x()==-50 && pos().y()+rect().height() ==0){
        A=A*(-1);
        B=B*(-1);
}
    else if (pos().x()==735 && pos().y()+rect().height() ==580){
        A=A*(-1);
        B=B*(-1);
}
    else if (pos().x()==-50 && pos().y()+rect().height() ==580){
        A=A*(-1);
        B=B*(-1);
}

    //move bullet up
    setPos(x()+A,y()+B);
    return;
}
