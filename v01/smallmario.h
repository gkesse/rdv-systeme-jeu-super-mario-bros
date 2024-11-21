#pragma once

#include <QGraphicsItem>
#include <QPixmap>

class SmallMario : public QGraphicsItem
{
private:
    enum State
    {
        Standing = 0,
        StandShoot,
        Walking,
        Jumping,
        Falling
    };

public:
    SmallMario(QGraphicsItem *parent = 0);
    ~SmallMario();
    QRectF boundingRect() const;
    void addDirection(int direction);
    void nextFrame();
    void stand();
    void walk();
    bool isFalling();

    void addStandingDirection(int standingDirection) { m_StandingDirection = standingDirection; }
    int standingDirection() const { return m_StandingDirection; }
    int direction() const { return m_direction; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame;
    int m_StandingDirection;
    int m_direction;
    State mState;

    QPixmap mPixmap;
    QPixmap mWalkPixmap;
    QPixmap mStandingPixmap;
};
