#ifndef VIEWMENU_H
#define VIEWMENU_H

#pragma once

#include "controllermenu.h"
#include "rebuild.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>

#include <QDebug>

class ViewMenu : public QGraphicsScene {
    Q_OBJECT;

public:
    ViewMenu(ControllerMenu*, QWidget *parent = nullptr);
    ~ViewMenu();

    QGraphicsView* getView();
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:
    QGraphicsView* view = nullptr;
    ControllerMenu* controller = nullptr;
};

#endif // VIEWMENU_H
