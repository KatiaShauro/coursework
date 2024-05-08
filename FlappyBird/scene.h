#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include "pillaritem.h"
#include "birditem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void addBird();
    void startGame();

    bool getGameOn() const;
    void setGameOn(bool value);
    void incrementScore();

signals:

public slots:

private:
    void showGameOver();
    void hideGameOver();
    void cleanPillars();
    void setUpPillarTimer();
    void freeze();

    QTimer *pillarTimer;
    BirdItem * bird;
    bool gameOn;
    int score;
    int bestScore;

    QGraphicsPixmapItem* gameOverPix;
    QGraphicsTextItem * scoreTextItem;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
