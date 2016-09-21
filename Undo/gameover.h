#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Gameover:public QGraphicsView{
public:
    Gameover (QWidget* parent=0);
    QGraphicsScene * scene;

}

#endif // GAMEOVER_H
