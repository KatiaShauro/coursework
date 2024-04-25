#include "gemsitem.h"

GemsItem::GemsItem() : isBackground(false) {
  QPixmap pixmap(":/images/gems.png");
  int gemWidth = pixmap.width() / Count;
  int gemHeight = pixmap.height();

  // Обрезка изображения для выбранного типа гема
  int type = QRandomGenerator::global()->bounded(7);
  QPixmap gemPixmap = pixmap.copy(gemWidth * type, 0, gemWidth, gemHeight);
  setPixmap(gemPixmap.scaled(QSize(75, 75), Qt::KeepAspectRatio));
}
