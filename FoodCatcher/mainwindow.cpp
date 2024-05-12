#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setFixedSize(SIDE, SIDE);

  // Создаем сцену и устанавливаем ее размеры
  scene = new Scene;
  scene->setSceneRect(0, 0, SCENE_RECT, SCENE_RECT);

  // Добавляем фоновое изображение
  QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(
      QPixmap(":/background.png")
          .scaled(QSize(SIDE, SIDE), Qt::KeepAspectRatio));
  scene->addItem(pixItem);

  // Устанавливаем сцену для QGraphicsView
  ui->graphicsView->setScene(scene);


  // Убираем полосы прокрутки
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // Устанавливаем выравнивание для фонового изображения
  ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}


MainWindow::~MainWindow() {
  delete ui;
}
