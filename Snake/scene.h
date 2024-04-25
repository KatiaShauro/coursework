#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "snake.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void addSnake();
    void startGame();

signals:

public slots:

private:
    Snake* snake ;
};

#endif // SCENE_H
