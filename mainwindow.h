#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGraphicsView* view;
    GraphicScene* scene;
    QVector<Point> points;
    QPropertyAnimation* animation;
    QPropertyAnimation* animation1;
    int currentPointIndex;
    QPushButton* button;
    int currentIndex;
    Point currentPoint;
    Point nextPoint;
    QTimer* timer;
    int interval;
    int direction;
    int a;
    int state;
    enum {LEFT, RIGHT};
    enum {MOVE, STOP};
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void  keyPressEvent(QKeyEvent *event);
    void  keyReleaseEvent(QKeyEvent *event);

signals:

public slots:
    void move();
    void moveLeft();
    int getY(int x, int k, int b);
    void increaseSpeed();
    void decreaseSpeed();
};

#endif // MAINWINDOW_H
