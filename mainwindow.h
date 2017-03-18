#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "graphicscene.h"
#include <QPropertyAnimation>
#include <QAction>
#include <QPushButton>
#include <QRect>

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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void moveRight();
    void moveLeft();
    int getY(int x, int k, int b);
};

#endif // MAINWINDOW_H
