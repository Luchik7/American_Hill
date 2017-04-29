#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include "graphicscene.h"
#include <QPropertyAnimation>
#include <QAction>
#include <QPushButton>
#include <QRect>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

struct Point {
    Point(int x, int y) : x(x), y(y){}
    Point(){}
    int x;
    int y;
};

class Game : public QWidget
{
    Q_OBJECT
private:
    QGraphicsView* view;
    GraphicScene* scene;
    QVector<Point> points;
    int currentPointIndex;
    QPushButton* button;
    int currentIndex;
    Point currentPoint;
    Point nextPoint;
    QTimer* timer;
    int interval;
    int direction;
    int oldDirection;
    int a;
    int state;
    int high;
    int dot;
    int up_y;
    enum {LEFT, RIGHT, UP, DOWN};
    enum {MOVE, STOP};
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void paintEvent(QPaintEvent *);
    void start();
    void  keyPressEvent(QKeyEvent *event);
    void  keyReleaseEvent(QKeyEvent *event);

signals:

public slots:
    void move();
    int getY(int x, int k, int b);

};

#endif // GAME_H
