#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(DOT_LENGTH * QUANT_LENGTH, DOT_WIDTH * QUANT_WIDTH);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_snakeButton_clicked()
{
    snake.setWindowTitle("Snake!!!");
    snake.initGame();
    snake.show();

}
