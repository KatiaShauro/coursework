#include "fruits.h"

Fruits::Fruits() {
  if (fruitsTypes.isEmpty()) {
    fruitsTypes.append(QPixmap(":/apple.png"));
    fruitsTypes.append(QPixmap(":/banana.png"));
    fruitsTypes.append(QPixmap(":/coconut.png"));
    fruitsTypes.append(QPixmap(":/mango.png"));
    fruitsTypes.append(QPixmap(":/orange.png"));
    fruitsTypes.append(QPixmap(":/peach.png"));
    fruitsTypes.append(QPixmap(":/pear.png"));
    fruitsTypes.append(QPixmap(":/pineapple.png"));
    fruitsTypes.append(QPixmap(":/raspberry.png"));
    fruitsTypes.append(QPixmap(":/strawberry.png"));
    fruitsTypes.append(QPixmap(":/watermelon.png"));
  }

  int type = QRandomGenerator::global()->bounded(FRUITS_COUNT - 1);
  setPixmap(fruitsTypes[type].scaled(QSize(FRUITS_SIZE, FRUITS_SIZE),
                                     Qt::KeepAspectRatio));

   xPos = QRandomGenerator::global()->bounded(1000);
  yAnimation = new QPropertyAnimation(this, "y", this);
   yAnimation->setStartValue(0);  // Начальная позиция за кадром
   yAnimation->setEndValue(1000);      // Конечная позиция внизу экрана
   yAnimation->setEasingCurve(QEasingCurve::Linear);
   yAnimation->setDuration(3500);                 // Скорость падения в миллисекундах
   yAnimation->start();
}

void Fruits::setY(qreal y) {
  m_y = y;
  setPos(QPointF(0, 0) + QPointF(xPos, y));

}

Fruits::~Fruits() {
  delete yAnimation;
}

qreal Fruits::y() const {
  return m_y;
}
