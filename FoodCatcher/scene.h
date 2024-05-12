#ifndef SCENE_H
#define SCENE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include "fruits.h"

#include "player.h"

class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  Scene();

 private:
  QTimer* fruitGeneratorTimer;

 private slots:
  void generateFruit();
  // Fruits* fruit;
};

#endif  // SCENE_H
