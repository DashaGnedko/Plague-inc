#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <view.h>
#include "controller.h"
#include "rebuild.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeOut();

private:
    View* view = nullptr;
    Controller* controller = nullptr;
    QTimer* timer = nullptr;
};
#endif // MAINWINDOW_H
