#pragma once

#include <QGraphicsView>

class QGraphicsScene;

class View : public QGraphicsView
{
    Q_OBJECT

public:
    explicit View();
    ~View();
    void sceneSet(QGraphicsScene *);

signals:
    void sceneChanged();
};
