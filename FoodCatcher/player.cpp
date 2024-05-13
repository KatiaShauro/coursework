#include "player.h"

Player::Player(QPixmap pixmap) {
  setPixmap(pixmap.scaled(QSize(CAT_SIZE, CAT_SIZE), Qt::KeepAspectRatio));
  setPos(SCENE_RECT / 2, 650);
}

void Player::moveLeft() {
  if (currentDirection != Direction::Left) {

    currentDirection = Direction::Left;

    setPixmap(QPixmap(":/Images/cat left.png")
                  .scaled(QSize(CAT_SIZE, CAT_SIZE), Qt::KeepAspectRatio));
  }
  if (x() > 0) {  // Проверяем, не достиг ли кот левой границы сцены
    setX(x() - value);  // Двигаем кота влево
  }
}

void Player::moveRight() {

  if (currentDirection != Direction::Right) {

    currentDirection = Direction::Right;

    setPixmap(QPixmap(":/Images/cat right.png")
                  .scaled(QSize(CAT_SIZE, CAT_SIZE), Qt::KeepAspectRatio));
  }
  if (x() + CAT_SIZE <
      SCENE_RECT) {  // Проверяем, не достиг ли кот правой границы сцены
    setX(x() + value);  // Двигаем кота вправо
  }
}

void Player::stand() {
  if (currentDirection != Direction::None) {

    currentDirection = Direction::None;

    setPixmap(QPixmap(":/Images/cat sitting.png")
                  .scaled(QSize(CAT_SIZE, CAT_SIZE), Qt::KeepAspectRatio));
  }
}
