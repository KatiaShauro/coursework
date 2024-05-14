#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(WINDOW_LENGTH, WINDOW_WIDTH);

  scene = new Scene;
  scene->setSceneRect(0, 0, SCENE_RECT, SCENE_RECT);

  // Добавляем фоновое изображение
  QGraphicsPixmapItem* pixItem =
      new QGraphicsPixmapItem(QPixmap(":/Images/background.jpeg")
                                  .scaled(QSize(SCENE_RECT, SCENE_RECT)));
  scene->addItem(pixItem);
  pixItem->setPos(QPointF(0, 0));

  // Устанавливаем сцену в виджет
  ui->graphicsView->setFixedSize(SCENE_RECT, SCENE_RECT);
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_snakeButton_clicked() {

  if (scene->getInGame()) {

    QMessageBox messageBox(QMessageBox::Warning, "WARNING",
                           "The game was already started!", QMessageBox::Ok);

    messageBox.exec();

  } else {
    scene->startGame();
  }
}
