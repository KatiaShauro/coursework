#include "scene.h"

Scene::Scene()
    : bestScore(0),
      scoreTextItem(nullptr),
      inGame(false),
      gameOverPicture(nullptr) {
  scoreTextItem = new QGraphicsTextItem();
  gameOverPicture = new QGraphicsPixmapItem();
}

void Scene::addSnake() {
  snake = new Snake;
  for (auto i : snake->snakeBody) {
    addItem(i);
  }
}

void Scene::startGame() {
  addSnake();
  addApple();
  inGame = true;
  score = 0;
  timer = new QTimer();
  connect(timer, &QTimer::timeout, [=]() {
    moveSnake();
    checkCollisisons();
    updateScoreText();
    if (snake->getDir() == none) {
      gameOver();
      inGame = false;
    }
  });

  timer->start(TIME_INTERVAL);

  scoreTextItem->show();
  QFont mFont("Consolas", FONT_SIZE, QFont::Bold);
  scoreTextItem->setFont(mFont);
  scoreTextItem->setDefaultTextColor(Qt::red);
  scoreTextItem->setPos(TEXT_POINT);
  addItem(scoreTextItem);

  if(gameOverPicture){
      removeItem(gameOverPicture);
  }
}

bool Scene::getInGame() const {
  return inGame;
}

void Scene::setInGame(bool value) {
  inGame = value;
}

void Scene::addApple() {
  apple = new Apple;
  addItem(apple);
}

void Scene::checkCollisisons() {
  QList<QGraphicsItem*> itemsList = items();
  for (QGraphicsItem* item : itemsList) {
    if (dynamic_cast<Apple*>(item) &&
        item->collidesWithItem(snake->snakeBody[0])) {
      removeItem(item);
      ++score;
      addApple();
      snake->increaseSnake();
      addItem(snake->snakeBody.last());
      delete item;
    }
  }
}

void Scene::gameOver() {
  gameOverPicture->setPixmap(
      QPixmap(":/Images/gameover.png").scaled(QSize(GAME_OVER_SIZE, GAME_OVER_SIZE)));
  gameOverPicture->setPos(int(SCENE_RECT / 4), int(SCENE_RECT) / 4);
  addItem(gameOverPicture);

  timer->stop();
  for (int i = 0; i < snake->snakeBody.size(); ++i) {
    removeItem(snake->snakeBody[i]);
  }
  delete snake;
  snake = nullptr;
  removeItem(apple);
  delete apple;
  apple = nullptr;
  delete timer;
  timer = nullptr;
  scoreTextItem->hide();
}

void Scene::updateScoreText() {
  // Отображаем счет
  bestScore = score > bestScore ? score : bestScore;
  QString htmlString = "<p> Score: " + QString::number(score) + "</p>" +
                       "<p> Best score: " + QString::number(bestScore) + "</p>";
  scoreTextItem->setHtml(htmlString);
}

void Scene::moveSnake() {
  // Получаем текущее направление змеи
  Directions currentDirection = snake->getDir();

  // Двигаем змею в текущем направлении
  snake->move(currentDirection);
}

void Scene::keyPressEvent(QKeyEvent* event) {
  int key = event->key();
  if (key == Qt::Key_Left && snake->getDir() != right) {
    snake->setDir(left);
  } else if (key == Qt::Key_Right && snake->getDir() != left) {
    snake->setDir(right);
  } else if (key == Qt::Key_Up && snake->getDir() != down) {
    snake->setDir(up);
  } else if (key == Qt::Key_Down && snake->getDir() != up) {
    snake->setDir(down);
  }
}
