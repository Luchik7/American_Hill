#include "graphicscene.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>


GraphicScene::GraphicScene(int x, int y, int width, int height): QGraphicsScene(x , y, width, height)
{
    QPixmap pixmap(":/snake.JPG");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(pixmap);
    backgroundItem->setZValue(1);
    backgroundItem->setPos(0,0);
    addItem(backgroundItem);
}

