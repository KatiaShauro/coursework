#include "snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget* parent) : QWidget(parent), ui(new Ui::Snake) {
  ui->setupUi(this);
  setFixedSize(DOT_LENGTH * QUANT_LENGTH, DOT_WIDTH * QUANT_WIDTH);
}

Snake::~Snake() {
  delete ui;
}

void Snake::localeApple() {
  apple.rx() = qrand() % DOT_LENGTH;
  apple.ry() = qrand() % DOT_WIDTH;

  qDebug() << "apple" << apple;
}

void Snake::move() {
  for (int i = coordinates.size() - 1; i > 0; --i) {
    coordinates[i] = coordinates[i - 1];
  }
  switch (dir) {
    case left:
      coordinates[0].rx() -= 1;
      break;
    case right:
      coordinates[0].rx() += 1;
      break;
    case up:
      coordinates[0].ry() -= 1;
      break;
    case down:
      coordinates[0].ry() += 1;
      break;
  }
}

void Snake::checkBorders() {
  QPoint head = coordinates[0];

  if (coordinates.size() > 4) {
    for (int i = 1; i < coordinates.size(); ++i) {
      if (head == coordinates[i]) {
        inGame = false;
      }
    }
  }

  if (coordinates[0].x() >= QUANT_LENGTH || coordinates[0].y() >= QUANT_WIDTH ||
      coordinates[0].x() < 0 || coordinates[0].x() < 0) {
    inGame = false;
  }

  if(!inGame){
      killTimer(timerId);
  };
}

void Snake::gameOver()
{
    QMessageBox messBox;
    messBox.setText("GAME OVER!");
    messBox.exec();

    initGame();
}

void Snake::checkAplle()
{
    if(apple == coordinates[0]){
        coordinates.push_back(QPoint(0, 0));
        localeApple();
    }
}

void Snake::initGame() {
  inGame = true;
  dir = right;

  coordinates.resize(3);

  for (int i = 0; i < coordinates.size(); ++i) {
    coordinates[i].rx() = coordinates.size() - i - 1;
    coordinates[i].ry() = 0;
  }

  localeApple();
  timerId = startTimer(TIME_INTERVAL);
}

void Snake::timerEvent(QTimerEvent* event) {
  if (inGame) {
    checkAplle();
    move();
    checkBorders();
  }
  this->repaint();
}

void Snake::keyPressEvent(QKeyEvent* event) {
  int key = event->key();
  if(key ==  Qt::Key_Left && dir!=Directions::right){
      dir = Directions::left;
  }
  if(key ==  Qt::Key_Right && dir!=Directions::left){
      dir = Directions::right;
  }
  if(key ==  Qt::Key_Up && dir!=Directions::down){
      dir = Directions::up;
  }
  if(key ==  Qt::Key_Down && dir!=Directions::up){
      dir = Directions::down;
  }
}

void Snake::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  if (inGame) {

    painter.setBrush(Qt::red);
    painter.drawEllipse(apple.x() * DOT_LENGTH, apple.y() * DOT_WIDTH,
                        DOT_LENGTH, DOT_WIDTH);

    for (const QPoint& point : coordinates) {

      painter.setBrush(Qt::green);

      if (point == coordinates[0]) {
        painter.setBrush(Qt::black);
      }
      painter.drawEllipse(point.x() * DOT_LENGTH, point.y() * DOT_WIDTH,
                          DOT_LENGTH, DOT_WIDTH);
    }
  } else {
      gameOver();
  }
}
