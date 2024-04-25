#ifndef GEMSITEM_H
#define GEMSITEM_H

#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QWidget>
#include "const.h"

class GemsItem : public QWidget, public QGraphicsPixmapItem {
  Q_OBJECT
 public:
  explicit GemsItem();

  enum GemType {
    SquarePurple,
    Triangle,
    Virus,
    Star,
    SquareBlack,
    Circle,
    Rhombus,
    Count
  };
bool isBackground;

 private:
  GemType m_type;
};

#endif  // GEMSITEM_H
