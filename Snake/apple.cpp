#include "apple.h"

Apple::Apple() {
  setPixmap(QPixmap(":/Images/apple.png")
                .scaled(QSize(FRUIT_SIZE, FRUIT_SIZE), Qt::KeepAspectRatio));
  localeApple();
}

void Apple::localeApple() {
  int x = QRandomGenerator::global()->bounded(50, SCENE_RECT - 50);
  int y = QRandomGenerator::global()->bounded(50, SCENE_RECT - 50);

  setPos(QPointF(x, y));
}
