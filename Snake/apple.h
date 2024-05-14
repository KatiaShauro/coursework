#ifndef APPLE_H
#define APPLE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QRandomGenerator>
#include "snakeConsts.h"

class Apple : public QObject, public QGraphicsPixmapItem
{
public:
    Apple();
    void localeApple();
};

#endif // APPLE_H
