#include "gemsitem.h"

GemsItem::GemsItem() : isBackground(false) {
  QPixmap pixmap(":/images/gems.png");
  int gemWidth = pixmap.width() / Count;
  int gemHeight = pixmap.height();

  // Обрезка изображения для выбранного типа гема
  type = QRandomGenerator::global()->bounded(7);
  QPixmap gemPixmap = pixmap.copy(gemWidth * type, 0, gemWidth, gemHeight);
  setPixmap(gemPixmap.scaled(QSize(75, 75), Qt::KeepAspectRatio));
}

int GemsItem::getColor() {
  return type;
}

int GemsItem::getpRow() const
{
    return pRow;
}

void GemsItem::setpRow(int value)
{
    pRow = value;
}

int GemsItem::getpCol() const
{
    return pCol;
}

void GemsItem::setpCol(int value)
{
    pCol = value;
}

int GemsItem::getType() const
{
    return type;
}

void GemsItem::setType(int value)
{
    type = value;
}

