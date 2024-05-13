#include "fruits.h"

static QList<QPixmap> fruitsTypes;

Fruits::Fruits() {

  initializeFruitsTypes();
  int type = QRandomGenerator::global()->bounded(FRUITS_COUNT - 1);
  setPixmap(fruitsTypes[type].scaled(QSize(FRUITS_SIZE, FRUITS_SIZE),
                                     Qt::KeepAspectRatio));

  xPos = QRandomGenerator::global()->bounded(50, 750);
  qDebug() << xPos;
  yAnimation = new QPropertyAnimation(this, "y", this);
  yAnimation->setStartValue(0);  // Начальная позиция за кадром
  yAnimation->setEndValue(1000);  // Конечная позиция внизу экрана
  yAnimation->setEasingCurve(QEasingCurve::Linear);
  yAnimation->setDuration(3500);  // Скорость падения в миллисекундах
  yAnimation->start();

  connect(yAnimation, &QPropertyAnimation::finished, [=]() {
    scene()->removeItem(this);
    delete this;
  });
}

void Fruits::setY(qreal y) {
  m_y = y;
  setPos(QPointF(0, 0) + QPointF(xPos, y));
}

void Fruits::freezeFruits()
{
    yAnimation->stop();
}

void Fruits::initializeFruitsTypes() {
  if (fruitsTypes.isEmpty()) {
    fruitsTypes.append(QPixmap(":/Images/apple.png"));
    fruitsTypes.append(QPixmap(":/Images/banana.png"));
    fruitsTypes.append(QPixmap(":/Images/coconut.png"));
    fruitsTypes.append(QPixmap(":/Images/mango.png"));
    fruitsTypes.append(QPixmap(":/Images/orange.png"));
    fruitsTypes.append(QPixmap(":/Images/peach.png"));
    fruitsTypes.append(QPixmap(":/Images/pear.png"));
    fruitsTypes.append(QPixmap(":/Images/pineapple.png"));
    fruitsTypes.append(QPixmap(":/Images/raspberry.png"));
    fruitsTypes.append(QPixmap(":/Images/strawberry.png"));
    fruitsTypes.append(QPixmap(":/Images/watermelon.png"));
    fruitsTypes.append(QPixmap(":/Images/grape.png"));
  }
}

Fruits::~Fruits() {
  delete yAnimation;
}

qreal Fruits::y() const {
  return m_y;
}

