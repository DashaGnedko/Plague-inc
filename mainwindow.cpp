#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    //resize(1000, 1000);

    showFullScreen();

    controller = new Controller();
    controllerMenu = new ControllerMenu(controller);

    stack = new QStackedWidget(this);

    view = new View(controller, this);
    view->getView()->setEnabled(true);
    stack->addWidget(view->getView());

    setCentralWidget(stack);

    viewMenu = new ViewMenu(controllerMenu, this);
    viewMenu->getView()->setEnabled(false);

    timer = new QTimer();
    timer->start(1);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeOut);

    connect(view, &View::openMenu, this, &MainWindow::openMenuWindow);

}

MainWindow::~MainWindow() {
    delete controller;
    delete view;
    delete timer;
    delete viewMenu;
}

void MainWindow::openWindow() {
    stack->removeWidget(viewMenu->getView());
    stack->setCurrentWidget(view->getView());
    viewMenu->getView()->setEnabled(false);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Escape) {
        if (viewMenu->getView()->isEnabled()) {
            openWindow();
            return;
        }
        else {
           exit(0);
        }
    }
}

void MainWindow::timeOut() {
    Rebuild updates = controller->update(1);
    view->update(updates);
}

void MainWindow::openMenuWindow() {
    stack->addWidget(viewMenu->getView());
    stack->setCurrentWidget(viewMenu->getView());
    viewMenu->getView()->setEnabled(true);
    controllerMenu->recalculateDna();
    //qDebug() << "????? " << (stack->currentWidget() == view->getView());
}
