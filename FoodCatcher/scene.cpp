#include "scene.h"

Scene::Scene() {
    // Создаем таймер для генерации фруктов
    fruitGeneratorTimer = new QTimer(this);
    connect(fruitGeneratorTimer, &QTimer::timeout, this, &Scene::generateFruit);
    fruitGeneratorTimer->start(1000); // Генерировать фрукты каждую секунду (1000 миллисекунд)
}

void Scene::generateFruit() {
    // Создаем новый объект Fruits и добавляем его на сцену
    Fruits* fruit = new Fruits();
    fruit->setPos(QRandomGenerator::global()->bounded(1000), 0);
    addItem(fruit);
}

