#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "player.h"
//#include <QMediaPlayer>
#include <typeinfo>

extern Game *game;
int A=10;
int B=-10;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    //draw graphics
    setPixmap(QPixmap(":/images/bola.png"));




    //connect
    Initial();     // Para crear el caso aleatorio
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);           //Velocidad de la bola
}

void Bullet::Initial(){
    int caso = 1 + (qrand() %5);
    switch (caso) {
            case 1:
                A = 10;
                B = -2;
                break;
            case 2:
                A = 10;
                B = -5;
                break;
            case 3:
                A = 10;
                B = -10;
                break;
            case 4:
                A = 5;
                B = -10;
                break;
            case 5:
                A = 2;
                B = -10;
                break;
            }
}
void Bullet::move(){
    /*QMediaPlayer * musica=new QMediaPlayer();
    musica->setMedia(QUrl("qrc:/sounds/choquebloque.mp3"));
    QMediaPlayer * musicab=new QMediaPlayer();
    musicab->setMedia(QUrl("qrc:/sounds/choquebarra.wav"));*/
    QList<QGraphicsItem *> colliding_items=collidingItems();
    //if one of the colliding item is an Enemy, destroy Enemy
    for (int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==((typeid(Enemy)))){
            //rebote
            B=B*(-1);
            //aumento el puntaje
            game->score->increase();
            //musica->play();
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
            //musicab->play();
        }

    }


    if(pos().y() <0){
            B=B*(-1);
    }
    else if (pos().y()>600){
            game->health->decrease();
            delete this;
            return;
}
    else if ((pos().x()<0)||(pos().x()>780)){
            A=A*(-1);
}
    //else if (pos().x()>735){
 //           A=A*(-1);
//}
    else if (pos().x()==780 && pos().y() ==0){
        A=A*(-1);
        B=B*(-1);
}
    else if (pos().x()==0 && pos().y() ==0){
        A=A*(-1);
        B=B*(-1);
}


    //move bullet up
    setPos(x()+A,y()+B);
    return;
}
