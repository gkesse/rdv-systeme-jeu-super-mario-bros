#include "backgrounditem.h"

BackgroundItem::BackgroundItem(const QPixmap &pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent)
{
}

BackgroundItem::~BackgroundItem()
{
}