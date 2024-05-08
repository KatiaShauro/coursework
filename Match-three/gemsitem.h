#ifndef GEMSITEM_H
#define GEMSITEM_H

#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
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

  int getpRow() const;
  void setpRow(int value);
  int getpCol() const;
  void setpCol(int value);
  int getType() const;
  void setType(int value);

private:
  int type;
  int pRow;
  int pCol;
  QPropertyAnimation* fstAnim;
  QPropertyAnimation* scndAnim;
};

#endif  // GEMSITEM_H
