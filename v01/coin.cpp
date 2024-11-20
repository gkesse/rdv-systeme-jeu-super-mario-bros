#include "coin.h"

#include <QPainter>

Coin::Coin(QGraphicsItem *parent)
    : QGraphicsItem(parent),
      mCurrentFrame2()
{
    setFlag(ItemClipsToShape);
    mPixmap2 = QPixmap(":/images/coin.png");
}

Coin::~Coin()
{
}

QRectF Coin::boundingRect() const
{
    return QRectF(0, 0, 39, 41);
}

void Coin::nextFrame2()
{
    mCurrentFrame2 += 38;
    if (mCurrentFrame2 >= 300)
    {
        mCurrentFrame2 = 0;
    }
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, mPixmap2, mCurrentFrame2, 0, 39, 41);
    setTransformOriginPoint(boundingRect().center());
}