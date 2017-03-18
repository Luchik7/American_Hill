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
    /*
    scene = new GraphicScene(0, 0, 800, 600);
    view = new QGraphicsView(scene, this);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setCentralWidget(view);
    */
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

    //currentPointIndex = 0;
    //currentPosition = QRect(0, 0, 100, 30);

    button = new QPushButton("Animated Button", this);
    button->show();


    animation = new QPropertyAnimation(button, "geometry");
    animation->setDuration(5000);
    for (auto i = 0; i < points.size(); i++) {
        animation->setKeyValueAt(0.1 * i, QRect(points[i].x * 100, points[i].y * 100, 100, 30));
    }

    QShortcut* moveRightShortcut = new QShortcut(Qt::Key_Right, this);
    connect(moveRightShortcut, SIGNAL(activated()), this, SLOT(moveRight()));

    //currentPosition = QRect(points[points.size() - 1].x * 100, points[points.size() - 1].y * 100, 100, 30);

    animation1 = new QPropertyAnimation(button, "geometry");
    animation1->setDuration(5000);

    for (auto i = 0; i < points.size(); i++) {
        animation1->setKeyValueAt(0.1 * i, QRect(points[points.size() - i - 1].x * 100, points[points.size() - i - 1].y * 100, 100, 30));
    }

    QShortcut* moveLeftShortcut = new QShortcut(Qt::Key_Left, this);
    connect(moveLeftShortcut, SIGNAL(activated()), this, SLOT(moveLeft()));


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

void MainWindow::moveRight()
{
    int x1 = currentPoint.x;
    int y1 = currentPoint.y;

    int x2 = nextPoint.x;
    int y2 = nextPoint.y;


    int k = (y2 - y1) / (x2 - x1);
    int b = y1 - x1 * k;
    int x = button->geometry().x() + 1;
    int y = getY(x, k, b);

    if(x == x2 && y == y2) {
        currentIndex++;
        currentPoint = nextPoint;
        nextPoint = points[currentIndex];
    }

    button->setGeometry(QRect(x, y, 100, 30));

}

void MainWindow::moveLeft()
{
    animation1->start();
}

int MainWindow::getY(int x, int k, int b)
{
    return k * x + b;
}


