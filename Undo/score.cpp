#include "score.h"
#include <QFont>
#include "game.h"
#include <QGraphicsScene>
#include <QImage>
#include <QGraphicsView>

extern Game *game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    if(score==65){
        game->setForegroundBrush(QBrush(QImage(":/images/win.jpg")));
    }
    else{
        setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
    }
}

int Score::getScore(){
    return score;
}
