#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include <QKeyEvent>

#include <view.h>
#include "controller.h"
#include "rebuild.h"
#include "viewmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent*);
    void openWindow();

//signals:
//    void openMenu();

public slots:
    void timeOut();
    void openMenuWindow();

private:
    QStackedWidget* stack = nullptr;
    View* view = nullptr;
    ViewMenu* viewMenu = nullptr;
    Controller* controller = nullptr;
    ControllerMenu* controllerMenu = nullptr;
    QTimer* timer = nullptr;
};
#endif // MAINWINDOW_H
