#include "myscene.h"

#include <QScrollBar>

MyScene::MyScene(QScrollBar *s, QObject *parent)
    : QGraphicsScene(0, 0, 8000, 720, parent),
      scroll(s)
{
}

MyScene::~MyScene()
{
}