#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H

#include <QGraphicsScene>
#include <QPaintEvent>

class GraphicScene : public QGraphicsScene
{

public:
    GraphicScene(int x, int y, int width, int height);
};

#endif // GRAPHICSCENE_H
