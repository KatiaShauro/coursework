#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsPixmapItem>
#include <QObject>


#include "snakeConsts.h"

class Snake : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  explicit Snake();
  ~Snake() override;
  QList<QGraphicsPixmapItem*> snakeBody;
  void move(Directions dir);
  void increaseSnake();

  Directions getDir() const;
  void setDir(const Directions &value);

private:
  int snakeLength;
  Directions direction;
};
#endif  // SNAKE_H
