#include "view.h"

#include <QGraphicsScene>

View::View()
{
    setFixedSize(QSize(1280, 720));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

View::~View()
{
}

void View::sceneSet(QGraphicsScene *scene)
{
    setScene(scene);
    emit sceneChanged();
}
