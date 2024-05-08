#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QString>
#include <QTransform>
#include <QDebug>
#include <QtMath>
#include <QGraphicsTextItem>
#include "const.h"
#include "gemsitem.h"

class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Scene(QObject* parent = nullptr);
  void addGems();
  void setIsBackground(bool value);
  void addScore();

private:
  int score;
  bool isBackground;

  GemsItem* m_selectedGem;
  GemsItem* gem;

  QPointF startPosition;
  GemsItem*** arrOfGems;
  QGraphicsTextItem *scoreText;

  void deleteMatches(GemsItem* gem);
  void swapGems(GemsItem* gem1, GemsItem* gem2);
  void checkHorMatches();
  void checkVertMatches();
  void dropGems();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // SCENE_H
