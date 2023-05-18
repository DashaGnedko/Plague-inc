#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    resize(2000, 1000);

    controller = new Controller();

    view = new View(controller, this);
    setCentralWidget(view->getView());

    timer = new QTimer();
    timer->start(1);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeOut);

    //showFullScreen();

}

MainWindow::~MainWindow() {
    delete controller;
    delete view;
}

void MainWindow::timeOut() {
    Rebuild updates = controller->update(1);
    view->update(updates);
}
