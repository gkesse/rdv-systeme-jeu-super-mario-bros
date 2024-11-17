#include "title.h"
#include "view.h"

#include <QScrollBar>
#include <QPropertyAnimation>

Title::Title(View *view, QWidget *parent)
    : QGraphicsScene(parent)
{
    viewer = view;

    viewer->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    background = new AnimatedGraphicsItem;
    background->setPixmap(QPixmap(":/images/background.png"));
    animation = new QPropertyAnimation(background, "pos");
    animation->setLoopCount(-1);
    animation->setDuration(150000);
    animation->setStartValue(QPoint(-width, 0));
    animation->setEndValue(QPoint(0, 0));
    animation->start();
    addItem(background);

    viewer->sceneSet(this);

    scroll = viewer->horizontalScrollBar();
}

Title::~Title()
{
}
