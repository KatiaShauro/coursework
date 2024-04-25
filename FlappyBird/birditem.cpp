#include "birditem.h"

BirdItem::BirdItem(QPixmap pixmap)
    : wingPosition(WingPosition::Up), wingDirection(0) {
  setPixmap(pixmap);
  QTimer* birdWingsTimer = new QTimer(this);

  connect(birdWingsTimer, &QTimer::timeout, [=]() { updatePixmap(); });
  birdWingsTimer->start(80);

  groundPosition = scenePos().y() + 290;

  yAnimation = new QPropertyAnimation(this, "y", this);
  yAnimation->setStartValue(scenePos().y());
  yAnimation->setEndValue(groundPosition);
  yAnimation->setEasingCurve(QEasingCurve::InQuad);
  yAnimation->setDuration(1000);

  //yAnimation->start();

  rotationAnimation = new QPropertyAnimation(this, "rotation", this);
 // rotateTo(90, 1200, QEasingCurve::InQuad);
}

qreal BirdItem::rotation() const {
  return m_rotation;
}

qreal BirdItem::y() const {
  return m_y;
}

void BirdItem::shootUp() {

  freezeInPlaace();
  qreal curPosY = y();
  yAnimation->setStartValue(curPosY);
  yAnimation->setEndValue(curPosY - scene()->sceneRect().height() / 8);
  yAnimation->setEasingCurve(QEasingCurve::OutQuad);
  yAnimation->setDuration(285);

  connect(yAnimation, &QPropertyAnimation::finished,
          [=]() { fallToTheGround(); });
  yAnimation->start();
  rotateTo(-20, 200, QEasingCurve::OutCubic);
}

void BirdItem::startFlying()
{
    yAnimation->start();
    rotateTo(90, 1200, QEasingCurve::InQuad);
}

void BirdItem::freezeInPlaace()
{
     yAnimation->stop();
     rotationAnimation->stop();
}

void BirdItem::setY(qreal y) {
  moveBy(0, y - m_y);
  m_y = y;
}

void BirdItem::setRotation(qreal rotation) {
  m_rotation = rotation;
  QPointF center = boundingRect().center();
  QTransform t;
  t.translate(center.x(), center.y());
  t.rotate(rotation);
  t.translate(-center.x(), center.y());
  setTransform(t);
}

void BirdItem::rotateTo(const qreal& end, const int& duration,
                        const QEasingCurve& curve) {
  rotationAnimation->setStartValue((rotation()));
  rotationAnimation->setEndValue(end);
  rotationAnimation->setEasingCurve(curve);
  rotationAnimation->setDuration(duration);
  rotationAnimation->start();
}

void BirdItem::fallToTheGround() {
  if (y() < groundPosition) {
    rotationAnimation->stop();
    yAnimation->setStartValue(y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1200);
    yAnimation->start();
    rotateTo(90, 1100, QEasingCurve::InCubic);
  }
}

void BirdItem::updatePixmap() {
  if (wingPosition == WingPosition::Middle) {
    if (wingDirection) {  // летит вверх
      setPixmap(QPixmap(":/Images/bird0.png")
                    .scaled(QSize(100, 100), Qt::KeepAspectRatio));
      wingPosition = WingPosition::Up;
      wingDirection = 0;
    } else {
      setPixmap(QPixmap(":/Images/bird2.png")
                    .scaled(QSize(100, 100), Qt::KeepAspectRatio));
      wingPosition = WingPosition::Down;
      wingDirection = 1;
    }
  } else {
    setPixmap(QPixmap(":/Images/bird1.png")
                  .scaled(QSize(100, 100), Qt::KeepAspectRatio));
    wingPosition = WingPosition::Middle;
  }
}
