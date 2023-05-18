#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include <QPointF>
#include <random>
#include <QGraphicsItem>
#include <cmath>

class Circle {
public:
    Circle(double, double, QPointF, double maxRadius = 1e9);
    Circle(QPointF, QPointF, double maxRadius = 1e9);

    static double getDistance(QPointF, QPointF);

    QPointF position;
    QPointF localPosition;
    double radius;
    double transparent;
    //bool isActive;
    QGraphicsItem* item = nullptr;

};

#endif // POINT_H
