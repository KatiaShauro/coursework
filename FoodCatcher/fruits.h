#ifndef FRUITS_H
#define FRUITS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QRandomGenerator>
#include <QPropertyAnimation>
#include "const.h"

class Fruits :  public  QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit Fruits();
    ~Fruits();
    QList<QPixmap> fruitsTypes;

    qreal y() const;

public slots:
    void setY(qreal y);

private:
    qreal m_y;
    QPropertyAnimation* yAnimation;
    int xPos;
};

#endif  // FRUITS_H
