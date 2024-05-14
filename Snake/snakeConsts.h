#ifndef SNAKECONSTS_H
#define SNAKECONSTS_H
#include <QPointF>

static const int FRUIT_SIZE = 50;
static const int SNAKE_SKIN_SIZE = 70;
static const int SNAKE_HEAD_SIZE = 140;
static const int SIZE = 1000;
static const int START_POS = 100;
static const int STEP = 70;
static const int SCENE_RECT = 950;
static const int WINDOW_LENGTH = SCENE_RECT + 20;
static const int WINDOW_WIDTH = SCENE_RECT + 150;
static const int TIME_INTERVAL = 200;
static const int FONT_SIZE = 30;
static const int GAME_OVER_SIZE = SIZE / 2;
static const QPointF TEXT_POINT = QPointF(0, 50);

enum Directions { left, right, up, down, none };

#endif  // SNAKECONSTS_H
