#ifndef SCENE_H
#define SCENE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QKeyEvent>
#include <QString>
#include <QString>
#include <QTimer>
#include "fruits.h"
#include "player.h"

class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  Scene();
  void addPlayerAndTextItems();
  void keyPressEvent(QKeyEvent* event) override;
  void startGame();

 private:
  QTimer* fruitGeneratorTimer;
  QTimer* checkCollisionsTimer;
  QGraphicsTextItem* scoreTextItem;
  QGraphicsTextItem* timerText;
  Player* cat;
  void setUpFruitTimer();
  void setUpCollisionsTimer();
  void checkCollisions();
  void gameOver();
  void updateTimerText();
  void updateScoreText();
  int score;
  int gameTime;
  int bestScore;

 private slots:
  void generateFruit();


};

#endif  // SCENE_H
