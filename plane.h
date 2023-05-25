#ifndef PLANE_H
#define PLANE_H

#pragma once

#include "picture.h"
#include "airport.h"
#include <cmath>

class Plane {
public:
    Plane(Airport*, Airport*, const QString&, int, int);
    ~Plane();
    Plane(const Plane&);
    Plane& operator=(const Plane&);

    QPointF getStart();
    QPointF getFinish();
    QPointF getCurrent();
    bool getInfected();
    Picture* getPicture() const;

    void setInfected(bool);
    bool between(double, double, double);
    void update(int);
    bool isReachDestination();

private:
    const double eps = 0.00000001;
    int timer = 0;
    int timerFromStart = 0;

    Airport* startAirport;
    Airport* finishAirport;
    QPointF start;
    QPointF finish;
    QPointF current;
    double deltaX;
    double deltaY;
    bool isInfected;
    Picture* picture = nullptr;
};

#endif // PLANE_H
