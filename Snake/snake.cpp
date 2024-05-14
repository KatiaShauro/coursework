#include "snake.h"

Snake::Snake() : snakeLength(4), direction(Directions::right) {
  for (int i = 0; i < snakeLength; ++i) {
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem;
    QPixmap pixmap;
    int size;
    if (i == 0) {
      pixmap = QPixmap(":/Images/skin.png");
      size = SNAKE_SKIN_SIZE;
    }

    else {
      pixmap = QPixmap(":/Images/skin.png");
      size = SNAKE_SKIN_SIZE;
    }

    item->setPixmap((pixmap).scaled(QSize(size, size), Qt::KeepAspectRatio));
    item->setPos((snakeLength - i - 1) * STEP, 0);
    snakeBody.append(item);
  }
}

void Snake::move(Directions dir) {
  // Получаем границы сцены
  QRectF sceneRect = QRectF(0, 0, SCENE_RECT, SCENE_RECT);

  for (int i = snakeBody.size() - 1; i > 0; --i) {
    // Проверяем, не выходит ли элемент за границы сцены
    if (!sceneRect.contains(snakeBody[i - 1]->pos())) {
      return;
    }
    snakeBody[i]->setPos(snakeBody[i - 1]->pos());
  }

  // Проверяем, не выходит ли голова за границы сцены
  switch (dir) {
    case left:
      if (snakeBody[0]->x() - STEP >= sceneRect.left()) {
        snakeBody[0]->setPos(snakeBody[0]->x() - STEP, snakeBody[0]->y());
        direction = left;
      } else {
        direction = none;
      }
      break;
    case right:
      if (snakeBody[0]->x() + STEP <= sceneRect.right()) {
        snakeBody[0]->setPos(snakeBody[0]->x() + STEP, snakeBody[0]->y());
        direction = right;
      } else {
        direction = none;
      }
      break;
    case up:
      if (snakeBody[0]->y() - STEP >= sceneRect.top()) {
        snakeBody[0]->setPos(snakeBody[0]->x(), snakeBody[0]->y() - STEP);
        direction = up;
      } else {
        direction = none;
      }
      break;
    case down:
      if (snakeBody[0]->y() + STEP <= sceneRect.bottom()) {
        snakeBody[0]->setPos(snakeBody[0]->x(), snakeBody[0]->y() + STEP);
        direction = down;
      } else {
        direction = none;
      }
      break;
  }

  // Проверяем, не столкнулась ли голова с самим собой
  for (int i = 1; i < snakeLength; ++i) {
    if (snakeBody[0]->collidesWithItem(snakeBody[i])) {
      direction = none;
      return;
    }
  }
}

void Snake::increaseSnake() {
  QGraphicsPixmapItem* item = new QGraphicsPixmapItem(
      QPixmap(":/Images/skin.png")
          .scaled(QSize(SNAKE_SKIN_SIZE, SNAKE_SKIN_SIZE),
                  Qt::KeepAspectRatio));
  item->setPos(snakeBody.last()->pos());
  snakeBody.append(item);
  ++snakeLength;
}

Directions Snake::getDir() const {
  return direction;
}

void Snake::setDir(const Directions& value) {
  direction = value;
}

Snake::~Snake() = default;
