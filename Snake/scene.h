#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QTimer>
#include "apple.h"
#include "snake.h"


class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Scene();
  void startGame();
  bool getInGame() const;
  void setInGame(bool value);

private:
  Apple* apple;
  Snake* snake;
  QTimer* timer;
  QGraphicsTextItem* scoreTextItem;
  QGraphicsPixmapItem* gameOverPicture;
  int score;
  int bestScore;
  bool inGame;
  void moveSnake();
  void addSnake();
  void addApple();
  void checkCollisisons();
  void gameOver();
  void updateScoreText();

protected:
  void keyPressEvent(QKeyEvent *event) override;
};

#endif  // SCENE_H
