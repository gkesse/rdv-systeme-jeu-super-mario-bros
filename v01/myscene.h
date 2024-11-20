#pragma once

#include <QGraphicsScene>

class QScrollBar;

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyScene(QScrollBar *s, QObject *parent = 0);
    ~MyScene();

private:
    QScrollBar *scroll;
};
