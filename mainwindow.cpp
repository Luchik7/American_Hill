#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game(this);
    game->setGeometry(0, 0, 1000, 1000);
    game->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
    ui->Start->setFocusPolicy(Qt::NoFocus);
    ui->Rules->setFocusPolicy(Qt::NoFocus);
    ui->Exit->setFocusPolicy(Qt::NoFocus);
    ui->Start->hide();
    ui->Rules->hide();
    ui->Exit->hide();
    game->show();
    game->start();
}
