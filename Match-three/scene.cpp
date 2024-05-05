#include "scene.h"

Scene::Scene(QObject* parent)
    : QGraphicsScene(parent),
      gameOn(false),
      score(0),
      bestScore(0),
      startPosition(QPointF(START_POS_X, START_POS_Y)),
      m_selectedGem(nullptr) {}

void Scene::addGems() {

  arrOfGems = new GemsItem**[ROW_COUNT];
  for (int i = 0; i < ROW_COUNT; ++i) {
    arrOfGems[i] = new GemsItem*[COL_COUNT];
  }

  for (int row = 0; row < ROW_COUNT; ++row) {
    for (int col = 0; col < COL_COUNT; ++col) {
      // Вычисление позиции текущего гема
      QPointF gemPosition = startPosition + QPointF(col * (GEM_SIZE + SPACING),
                                                    row * (GEM_SIZE + SPACING));
      GemsItem* gem = new GemsItem();
      gem->setPos(gemPosition);
      addItem(gem);
      arrOfGems[row][col] = gem;
      gem->setpRow(row);
      gem->setpCol(col);
    }
  }
  checkHorMatches();
  checkVertMatches();
}

void Scene::setIsBackground(bool value) {
  isBackground = value;
}

void Scene::dropGems() {
  for (int col = 0; col < COL_COUNT; ++col) {
    for (int row = 0; row < 1; ++row) {

      GemsItem* gem = arrOfGems[row][col];
      QPointF pos = gem->scenePos();

      if (gem->getType() == -1) {
        if (row == 0) {

          gem = new GemsItem();
          gem->setPos(pos);
          addItem(gem);
          arrOfGems[row][col] = gem;
          continue;
        }
      }
    }
  }
}

void Scene::deleteMatches(GemsItem* gem) {
  if (items().contains(gem)) {
    int row = gem->getpRow();
    int col = gem->getpCol();

    // Удаляем гем из сцены
    gem->setType(-1);
    removeItem(gem);
    arrOfGems[row][col]->setType(-1);

  } else {
    return;
  }
}

void Scene::swapGems(GemsItem* gem1, GemsItem* gem2) {
    if (!gem1 || !gem2) {
        return;
    }

    QPointF pos1 = gem1->scenePos();
    QPointF pos2 = gem2->scenePos();

    bool areAdjacent = (((qAbs(pos1.x() - pos2.x()) < GEM_SIZE * 2 + SPACING) &&
                         (qAbs(pos1.y() - pos2.y()) < GEM_SIZE * 2 + SPACING)) ||

                        ((qAbs(pos1.y() - pos2.y()) < GEM_SIZE + SPACING) &&
                         (qAbs(pos1.x() - pos2.x()) < GEM_SIZE + SPACING)));

    if (!areAdjacent) {
        return;
    } else {
        // Поменять местами гемы на сцене
        gem1->setPos(pos2);
        gem2->setPos(pos1);

        qDebug() << "!!!!!types before: 1)" << gem1->getType() << "2)"
                 << gem2->getType();
        // Обновить содержимое массива arrOfGems
        qDebug() << "types before: 1)"
                 << arrOfGems[gem1->getpRow()][gem1->getpCol()]->getType() << "2)"
                 << arrOfGems[gem2->getpRow()][gem2->getpCol()]->getType();

        // Проверяем, чтобы индексы не выходили за границы массива
        int row1 = gem1->getpRow();
        int col1 = gem1->getpCol();
        int row2 = gem2->getpRow();
        int col2 = gem2->getpCol();

        if (row1 >= 0 && row1 < ROW_COUNT && col1 >= 0 && col1 < COL_COUNT &&
            row2 >= 0 && row2 < ROW_COUNT && col2 >= 0 && col2 < COL_COUNT) {

            std::swap(arrOfGems[row1][col1], arrOfGems[row2][col2]);

            qDebug() << "types after: 1)"
                     << arrOfGems[gem1->getpRow()][gem1->getpCol()]->getType() << "2)"
                     << arrOfGems[gem2->getpRow()][gem2->getpCol()]->getType();
        } else {
            qDebug() << "Index out of bounds!";
        }

        // Обновить указатели pRow и pCol у гемов
        int tempRow = gem1->getpRow();
        int tempCol = gem1->getpCol();
        gem1->setpRow(gem2->getpRow());
        gem1->setpCol(gem2->getpCol());
        gem2->setpRow(tempRow);
        gem2->setpCol(tempCol);

        checkHorMatches();
        checkVertMatches();
    }
}


void Scene::checkHorMatches() {

  int count = 1;

  for (int row = 0; row < ROW_COUNT; ++row) {
    for (int col = 0; col < COL_COUNT - 1; ++col) {
      GemsItem* currentGem = arrOfGems[row][col];
      GemsItem* nextGem = arrOfGems[row][col + 1];
      qDebug() << "row " << row << "col " << col << "count" << count
               << "gemtype" << arrOfGems[row][col]->getType();
      if (count == 3) {
        for (int i = 0; i < 3 ; ++i) {
          qDebug() << "H:delete at row " << row << "col " << col - i;
          deleteMatches(arrOfGems[row][col - i]);
        }
       dropGems();
        count = 1;
      }
      if (!nextGem || nextGem->getType() != currentGem->getType() ||
          currentGem->getType() == -1 || nextGem->getType() == -1) {
        count = 1;
        continue;
      } else {
        ++count;
      }
    }
    if (count == 3) {
      for (int i = 0; i < 3; ++i) {
        qDebug() << "H:delete at row " << row << "col " << LAST_COL - i;
        deleteMatches(arrOfGems[row][LAST_COL - i]);
      }
    dropGems();
    }
    count = 1;
    qDebug() << "\n";
  }
}

void Scene::checkVertMatches() {

  int count = 1;

  for (int col = 0; col < COL_COUNT; ++col) {
    for (int row = 0; row < ROW_COUNT - 1; ++row) {
      GemsItem* currentGem = arrOfGems[row][col];
      GemsItem* nextGem = arrOfGems[row + 1][col];

      if (count == 3) {
        for (int i = 0; i < 3; ++i) {
          qDebug() << "V:delete at row " << row - i << "col " << col;
          deleteMatches(arrOfGems[row - i][col]);
        }
       dropGems();
        count = 1;
      }
      if (!nextGem || nextGem->getType() != currentGem->getType() ||
          currentGem->getType() == -1 || nextGem->getType() == -1) {
        count = 1;
        continue;
      } else {
        ++count;
      }
    }
    if (count == 3) {
      for (int i = 0; i < 3; ++i) {
        qDebug() << "V:delete at row " << LAST_ROW - i << "col " << col;
        deleteMatches(arrOfGems[LAST_ROW - i][col]);
      }
       dropGems();
      count = 1;
    }
  }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  gem = nullptr;
  QPointF clickPos = event->scenePos();
  QGraphicsItem* item = itemAt(clickPos, QTransform());
  gem = qgraphicsitem_cast<GemsItem*>(item);

  if (gem && !gem->isBackground) {
    if (!m_selectedGem) {
      m_selectedGem = gem;
    } else {
      swapGems(m_selectedGem, gem);
      m_selectedGem = nullptr;
    }
  }
}
