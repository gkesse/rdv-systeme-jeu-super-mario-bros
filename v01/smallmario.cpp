#include "smallmario.h"

#include <QPainter>

SmallMario::SmallMario(QGraphicsItem *parent)
    : QGraphicsItem(parent),
      mCurrentFrame(0),
      m_StandingDirection(0),
      m_direction(0),
      mState(Standing)
{
    setFlag(ItemClipsToShape);
    mWalkPixmap = QPixmap(":/images/shrink.png");
    mStandingPixmap = QPixmap(":/images/smallMarioStop.png");
    mPixmap = mWalkPixmap;
}

SmallMario::~SmallMario()
{
}

QRectF SmallMario::boundingRect() const
{
    return QRectF(0, 0, 45, 45);
}

void SmallMario::addDirection(int direction)
{
    if (m_direction == direction)
        return;

    m_direction += direction;

    if (m_direction != 0)
    {
        if (m_direction == -1)
            setTransform(QTransform(-1, 0, 0, 1, boundingRect().width(), 0));
        else
            setTransform(QTransform());
    }
}

void SmallMario::stand()
{
    if (mState == Standing)
        return;

    mPixmap = mStandingPixmap;
    mCurrentFrame = 0;
    mState = Standing;
}

void SmallMario::walk()
{
    if (mState == Walking)
        return;

    mPixmap = mWalkPixmap;
    mCurrentFrame = 0;
    mState = Walking;
}

void SmallMario::nextFrame()
{
    mCurrentFrame += 57;
    if (mCurrentFrame >= 1191)
    {
        mCurrentFrame = 0;
    }
}

bool SmallMario::isFalling()
{
    return mState == Falling;
}

void SmallMario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 45, 45);
    setTransformOriginPoint(boundingRect().center());
}
