#pragma once

#include <QGraphicsItem>
#include <QPixmap>

class Coin : public QGraphicsItem
{
public:
    Coin(QGraphicsItem *parent = 0);
    ~Coin();
    QRectF boundingRect() const;
    void nextFrame2();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame2;
    QPixmap mPixmap2;
};
