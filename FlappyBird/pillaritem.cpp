#include "pillaritem.h"

PillarItem::PillarItem()
    : topPillar(new QGraphicsPixmapItem(QPixmap(":/Images/topPillar.png"))),
      bottomPillar(
          new QGraphicsPixmapItem(QPixmap(":/Images/bottomPillar.png"))),
      pastBird(false) {

  topPillar->setPos(QPointF(0, 0) -
                    QPointF(topPillar->boundingRect().width() / 2,
                            topPillar->boundingRect().height() + 200));
  bottomPillar->setPos(QPointF(0, 0) +
                       QPointF(-bottomPillar->boundingRect().width() / 2, 0));

  addToGroup(topPillar);
  addToGroup(bottomPillar);

  yPos = QRandomGenerator::global()->bounded(450);
  int xRandomizer = QRandomGenerator::global()->bounded(200);
  //setPos(QPoint(0, 0) + QPoint(260 + xRandomizer, yPos));

  xAnimation = new QPropertyAnimation(this, "x", this);
  xAnimation->setStartValue(750);
  xAnimation->setEndValue(-1500);  // то, насколько колонны зайдут за кадр
  xAnimation->setEasingCurve(QEasingCurve::Linear);
  xAnimation->setDuration(3500);  // скорость в мск
  xAnimation->start();

  connect(xAnimation, &QPropertyAnimation::finished, [=]() {
    scene()->removeItem(this);
    delete this;
  });
}

PillarItem::~PillarItem() {
  delete topPillar;
  delete bottomPillar;
}

qreal PillarItem::x() const {
  return m_x;
}

void PillarItem::freezeInPlace() {
  xAnimation->stop();
}

void PillarItem::setX(qreal x) {
  m_x = x;

  if (x < 0 && !pastBird) {
    pastBird = true;
    QGraphicsScene* mScene = scene();
    Scene* myScene = dynamic_cast<Scene*>(mScene);
    if (myScene) {
      myScene->incrementScore();
    }
  }
  if (collidesWithBird()) {
    emit collideFail();
  }
  setPos(QPointF(0, 0) + QPointF(x, yPos));
}

bool PillarItem::collidesWithBird() {
  QList<QGraphicsItem*> collidingItems = topPillar->collidingItems();
  collidingItems.append(bottomPillar->collidingItems());

  foreach (QGraphicsItem* item, collidingItems) {
    BirdItem* birdItem = dynamic_cast<BirdItem*>(item);
    if (birdItem)
      return true;
  }
  return false;
}
