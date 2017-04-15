#include "mainwindow.h"
#include <QGraphicsView>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QRect>
#include <QPushButton>
#include <QShortcut>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 1));
    points.push_back(Point(2, 3));
    points.push_back(Point(3, 3));
    points.push_back(Point(4, 2));
    points.push_back(Point(5, 3));
    points.push_back(Point(6, 2));
    points.push_back(Point(7, 2));
    points.push_back(Point(8, 1));
    points.push_back(Point(9, 1));
    points.push_back(Point(10, 3));

    currentPoint = points[0];
    nextPoint = points[1];
    currentIndex = 1;

    button = new QPushButton("Animated Button", this);
    button->show();
    button->setFocusPolicy(Qt::NoFocus);

    animation = new QPropertyAnimation(button, "geometry");
    animation->setDuration(10000);
    for (auto i = 0; i < points.size(); i++) {
        animation->setKeyValueAt(0.1 * i, QRect(points[i].x * 100, points[i].y * 100, 100, 30));
    }

    interval = 20;
    direction = RIGHT;
    state = MOVE;
    a = 1;
    QTimer::singleShot(interval, this, SLOT(move()));

    animation1 = new QPropertyAnimation(button, "geometry");
    animation1->setDuration(5000);

    for (auto i = 0; i < points.size(); i++) {
        animation1->setKeyValueAt(0.1 * i, QRect(points[points.size() - i - 1].x * 100, points[points.size() - i - 1].y * 100, 100, 30));
    }
}

MainWindow::~MainWindow()
{
    delete animation;
    delete animation1;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;
    path.moveTo(0, 0);
    for (auto p: points) {
        path.lineTo(p.x * 100, p.y * 100);
    }
    painter.setPen(Qt::blue);
    painter.drawPath(path);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    if (event->key() == Qt::Key_Right) {
        interval = 20;
    }
    else if (event->key() == Qt::Key_Left) {
        interval = 20;
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    if (event->key() == Qt::Key_Right) {
        direction = RIGHT;
        if (state == STOP) {
            state = MOVE;
            move();
        }
        a = 1;
        interval = 5;
    }
    else if(event->key() == Qt::Key_Left) {
        direction = LEFT;
        if (state == STOP) {
            state = MOVE;
            move();
        }
        a = -1;
        interval = 5;
    }
}

void MainWindow::move()
{
    if ((currentIndex > 10 && direction == RIGHT) || (currentIndex < 0 && direction == LEFT)){
        state = STOP;
        return;
    }


    int x1 = currentPoint.x * 100;
    int y1 = currentPoint.y * 100;

    int x2 = nextPoint.x * 100;
    int y2 = nextPoint.y * 100;

    int k = (y2 -  y1) / (x2 - x1);
    int b = y1 - x1 * k;
    int x = button->geometry().x() + a;
    int y = getY(x, k, b);

    if (direction == RIGHT){
        if(x >= x2) {
            currentIndex++;
            if (currentIndex > 10){
                state = STOP;
                return;
            }
            currentPoint = nextPoint;
            nextPoint = points[currentIndex];
        }
     }
    else {
        if(x <= x2){
            currentIndex--;
            if (currentIndex < 0){
                state = STOP;
                return;
            }
            currentPoint = nextPoint;
            nextPoint = points[currentIndex];

        }
    }

    button->setGeometry(QRect(x, y, 100, 30));
    QTimer::singleShot(interval, this, SLOT(move()));

}

void MainWindow::moveLeft()
{
    animation1->start();
}

int MainWindow::getY(int x, int k, int b)
{
    return k * x + b;
}

void MainWindow::increaseSpeed()
{
    //timer->stop();
    //timer->setInterval(10);
    //timer->start();
}

void MainWindow::decreaseSpeed()
{
    //timer->stop();
    //timer->setInterval(20);
    //timer->start();
}


