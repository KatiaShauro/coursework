#include "scene.h"

Scene::Scene(QObject* parent) : QGraphicsScene(parent) {}

void Scene::addSnake() {
  snake = new Snake;
  //addItem(snake);
}

void Scene::startGame() {
    addSnake();
    snake->initGame();
}

