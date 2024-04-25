#ifndef PILLARITEM_H
#define PILLARITEM_H

#include <QGraphicsItemGroup>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QRandomGenerator>
#include "birditem.h"
#include "scene.h"

class PillarItem :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit PillarItem();
    ~PillarItem();

    qreal x() const;
    void freezeInPlace();

signals:
    void collideFail();

public slots:

    void setX(qreal x);

private:
    QGraphicsPixmapItem *topPillar;
    QGraphicsPixmapItem *bottomPillar;
    QPropertyAnimation *xAnimation;
    int yPos;
    bool collidesWithBird();
    qreal m_x;
    bool pastBird;
};

#endif // PILLARITEM_H
