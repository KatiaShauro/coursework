#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QTransform>
#include <QDebug>
#include "const.h"
#include "gemsitem.h"

class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Scene(QObject* parent = nullptr);
  void addGems();
  bool isBackground;

  void setIsBackground(bool value);

private:
  bool gameOn;
  int score;
  int bestScore;

  GemsItem* m_selectedGem;
  GemsItem* gem;

  QPointF startPosition;


  void swapGems(GemsItem* gem1, GemsItem* gem2);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // SCENE_H
