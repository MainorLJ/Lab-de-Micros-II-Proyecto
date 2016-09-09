#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Enemy();

};

#endif // ENEMY_H
