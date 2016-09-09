#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFont>
#include <QWidget>
#include "enemy.h"
#include "player.h"
#include "bullet.h"

Game::Game (QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setRect(0,0,100,1); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    score->setPos(score->x()+550,score->y()+560);
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x()+700,health->y()+560);
    scene->addItem(health);


    //Creacion de los bloques

    for(int j=40;j<100;j=j+20){
        for(int i=10;i<790;i=i+60){
            Enemy * enemy = new Enemy();
            enemy->setPos(i,j);
            scene->addItem(enemy);
        }
    }
    show();
}
