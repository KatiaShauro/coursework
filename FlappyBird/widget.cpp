#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  setFixedSize(1500, 1000);

  scene = new Scene;
  scene->setSceneRect(-250, -300, 500, 600);

  QGraphicsPixmapItem* pixItem =
      new QGraphicsPixmapItem(QPixmap(":/Images/background.png"));
  scene->addItem(pixItem);
  pixItem->setPos(QPointF(0, 0) -
                  QPointF(pixItem->boundingRect().width() / 2,
                          pixItem->boundingRect().height() / 2));

  ui->graphicsView->setScene(scene);
  scene->addBird();
}

Widget::~Widget() {
  delete ui;
}

void Widget::on_startButton_clicked()
{scene->startGame();
}
