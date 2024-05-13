#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include "const.h"

enum Direction { None, Left, Right };

class Player : public QObject, public QGraphicsPixmapItem {
 public:
  Player(QPixmap pixmap);
  void moveLeft();
  void moveRight();
  void stand();

  Direction currentDirection;

 private:
  int value = 20;

  //
};

#endif  // PLAYER_H
