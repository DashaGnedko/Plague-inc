#ifndef VIEW_H
#define VIEW_H

#pragma once

#include "controller.h"
#include "rebuild.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>

#include <QDebug>

class View : public QGraphicsScene {
    Q_OBJECT;

signals:
    void openMenu();

public:
    View(Controller*, QWidget *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    QGraphicsView* getView();
    //void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget* = nullptr);
    void update(Rebuild&);

private:
    QGraphicsView* view = nullptr;
    Controller* controller = nullptr;

};

#endif // VIEW_H
