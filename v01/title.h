#pragma once

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class QScrollBar;
class QPropertyAnimation;

class View;
class AnimatedGraphicsItem;

class Title : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Title(View *view, QWidget *parent = 0);
    ~Title();

private:
    const int width = 1280;

    View *viewer;

    AnimatedGraphicsItem *background;
    QPropertyAnimation *animation;

    QScrollBar *scroll;
};

class AnimatedGraphicsItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
};
