#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

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
    connect(viewMenu, &ViewMenu::closeMenu, this, &MainWindow::openWindow);
}

MainWindow::~MainWindow() {
    delete controller;
    delete view;
    delete timer;
    delete viewMenu;
    delete result;
}

void MainWindow::openWindow() {
    stack->removeWidget(viewMenu->getView());
    stack->setCurrentWidget(view->getView());
    viewMenu->getView()->setEnabled(false);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (state != 0) {
        if (event->key() == Qt::Key_Escape) {
            exit(0);
        }
    }
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
    state = controller->checkCurrentState();
    qDebug() << state;
    if (state == 1) {
        viewMenu->getView()->setEnabled(false);
        view->getView()->setEnabled(false);
        result = new MyWidget(":/icons/defeat.png", this);
        stack->addWidget(result);
        stack->setCurrentWidget(result);
        timer->stop();
        return;
    } else if (state == 2) {
        viewMenu->getView()->setEnabled(false);
        view->getView()->setEnabled(false);
        result = new MyWidget(":/icons/victory.png", this);
        stack->addWidget(result);
        stack->setCurrentWidget(result);
        timer->stop();
        return;
    }
    Rebuild updates = controller->update(1);
    view->update(updates);
}

void MainWindow::openMenuWindow() {
    stack->addWidget(viewMenu->getView());
    stack->setCurrentWidget(viewMenu->getView());
    viewMenu->getView()->setEnabled(true);
    controllerMenu->recalculateDna();
}

