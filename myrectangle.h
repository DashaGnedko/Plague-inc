#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#pragma once

#include <QPointF>
#include <QGraphicsItem>
#include <QRectF>
#include <QPen>
#include <QBrush>

class MyRectangle {
public:
    MyRectangle(double, double, double, double, QPen, QBrush);
    //~Rectangle();
    MyRectangle(const MyRectangle&);
    MyRectangle operator[](const MyRectangle&);

    QRectF rect;
    QPointF begin;
    QPointF end;
    QPen pen;
    QBrush brush;
    QGraphicsItem* item = nullptr;
};

#endif // MYRECTANGLE_H
