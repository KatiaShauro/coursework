#include "scene.h"

Scene::Scene(QObject* parent)
    : QGraphicsScene(parent), gameOn(false), score(0), bestScore(0) {
  setUpPillarTimer();
}

void Scene::addBird() {
  bird = new BirdItem(QPixmap(":/Images/bird1.png")
                          .scaled(QSize(100, 100), Qt::KeepAspectRatio));
  addItem(bird);
}

void Scene::startGame() {
  //Bird
  bird->startFlying();
  //Pillars
  if (!pillarTimer->isActive()) {
    cleanPillars();
    setGameOn(true);
    hideGameOver();
    pillarTimer->start(1000);
  }
}

void Scene::setUpPillarTimer() {
  pillarTimer = new QTimer(this);
  connect(pillarTimer, &QTimer::timeout, [=]() {
    PillarItem* pillarItem = new PillarItem();
    connect(pillarItem, &PillarItem::collideFail, [=]() {
      pillarTimer->stop();
      freeze();
      setGameOn(false);
      showGameOver();
    });
    addItem(pillarItem);
  });
  //pillarTimer->start(1000);
}

void Scene::freeze() {
  bird->freezeInPlaace();
  QList<QGraphicsItem*> sceneItems = items();

  foreach (QGraphicsItem* item, sceneItems) {
    PillarItem* pillar = dynamic_cast<PillarItem*>(item);
    if (pillar) {
      pillar->freezeInPlace();
    }
  }
}

void Scene::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Space) {
    if (gameOn)
      bird->shootUp();
  }
  QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    if (gameOn)
      bird->shootUp();
  }
  QGraphicsScene::mousePressEvent(event);
}

bool Scene::getGameOn() const {
  return gameOn;
}

void Scene::setGameOn(bool value) {
  gameOn = value;
}

void Scene::incrementScore() {
  score++;
  if (score > bestScore)
    bestScore = score;
}

void Scene::showGameOver() {
  gameOverPix = new QGraphicsPixmapItem(QPixmap(
      ":/Images/—Pngtree—orange pixel wind gameover broken_5525880.png").scaled(QSize(500, 500), Qt::KeepAspectRatio));
  addItem(gameOverPix);
  gameOverPix->setPos(QPointF(0, 0) -
                      QPointF(gameOverPix->boundingRect().width() / 2,
                              gameOverPix->boundingRect().height() / 2));

  scoreTextItem = new QGraphicsTextItem();
  QString htmlString = "<p> Score: " + QString::number(score) + "</p>" +
                       "<p> Best score: " + QString::number(bestScore) + "</p>";

  QFont mFont("Consolas", 30, QFont::Bold);
  scoreTextItem->setHtml(htmlString);
  scoreTextItem->setFont(mFont);
  scoreTextItem->setDefaultTextColor(Qt::yellow);
  addItem(scoreTextItem);

  scoreTextItem->setPos(QPointF(0, 0) -
                        QPointF(scoreTextItem->boundingRect().width() / 2,
                                -gameOverPix->boundingRect().height() / 2));
}

void Scene::hideGameOver() {
  if (gameOverPix) {
    removeItem(gameOverPix);
    delete gameOverPix;
    gameOverPix = nullptr;
  }
 if (scoreTextItem) {
    removeItem(scoreTextItem);
    delete scoreTextItem;
    scoreTextItem = nullptr;
  }
}

void Scene::cleanPillars() {
  QList<QGraphicsItem*> sceneItems = items();
  foreach (QGraphicsItem* item, sceneItems) {
    PillarItem* pillar = dynamic_cast<PillarItem*>(item);
    if (pillar) {
      removeItem(pillar);
      delete pillar;
    }
  }
}
