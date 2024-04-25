#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QTime>
#include <QKeyEvent>
#include "snakeConsts.h"

namespace Ui {
class Snake;
}

class Snake : public QWidget
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = nullptr);
    ~Snake() override;
    void initGame();

private:
    Ui::Snake *ui;
    
    bool inGame;
    int timerId;
    QPoint apple;

    enum Directions{
        left, right, up, down
    };

    Directions dir;
    QVector<QPoint> coordinates;
    
    void localeApple();
    void move();
    void checkBorders();
    void gameOver();
    void  checkAplle();

protected:
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // SNAKE_H
