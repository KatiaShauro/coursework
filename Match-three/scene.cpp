#include "scene.h"

Scene::Scene(QObject* parent)
    : QGraphicsScene(parent),
      gameOn(false),
      score(0),
      bestScore(0),
      startPosition(QPointF(-643, -425)),
      m_selectedGem(nullptr) {}

void Scene::addGems() {
  for (int row = 0; row < ROW_COUNT; ++row) {
    for (int col = 0; col < COL_COUNT; ++col) {
      // Вычисление позиции текущего гема
      QPointF gemPosition = startPosition + QPointF(col * (GEM_SIZE + SPACING),
                                                    row * (GEM_SIZE + SPACING));

      GemsItem* gem = new GemsItem();
      gem->setPos(gemPosition);
      addItem(gem);
    }
  }
}

void Scene::setIsBackground(bool value)
{
    isBackground = value;
}

void Scene::swapGems(GemsItem* gem1, GemsItem* gem2) {
    if (!gem1 || !gem2) {
    return;
  }
  QPointF pos1 = gem1->scenePos();
  QPointF pos2 = gem2->scenePos();
  gem1->setPos(pos2);
  gem2->setPos(pos1);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {

  QPointF clickPos = event->scenePos();
  QGraphicsItem* item = itemAt(clickPos, QTransform());
  gem = qgraphicsitem_cast<GemsItem*>(item);
  if(gem->isBackground){
      return;
  }
  if (gem) {
    if (!m_selectedGem) {
      m_selectedGem =
          gem;  // Сохранение указателя на выбранный гем для последующего обмена
    } else {
      swapGems(m_selectedGem, gem);
      m_selectedGem = nullptr;
    }
    return;
  }

  m_selectedGem = nullptr;
}
