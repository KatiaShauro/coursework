#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  setFixedSize(1500, 1000);

  scene = new Scene;
  scene->setIsBackground(true);
  scene->setSceneRect(-250, -300, 500, 600);

  QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(
      QPixmap(":/images/background.png")
          .scaled(QSize(1500, 1000), Qt::KeepAspectRatio));
  scene->addItem(pixItem);
  pixItem->setPos(QPointF(0, 0) -
                  QPointF(pixItem->boundingRect().width() / 2,
                          pixItem->boundingRect().height() / 2));

  ui->graphicsView->setScene(scene);
  scene->addGems();

}

Widget::~Widget() {
  delete ui;
}

//      QPixmap cursorPixmap(":/images/cursor.png");
//              QCursor cursor(cursorPixmap);
//             setCursor(cursor);
