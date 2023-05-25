#ifndef AIRPORT_H
#define AIRPORT_H

#pragma once

#include "circle.h"
#include "picture.h"

#include <QPointF>
#include <vector>

class Airport {
public:
    Airport(const QPointF&, const QString&, const QString&, int, int);
    ~Airport();
    Airport(const Airport&);
    Airport& operator=(const Airport&);

    //int size();
    //Plane* operator[](int);

    QPointF getLocalPosition(const QPointF&);
    QPointF getPosition();
    bool getInfection();
    //std::vector<Plane*> getPlane() const;
    Picture* getPicture() const;
    void setClosed(bool);
    //void addPlane(Plane*);
    void setInfected(bool);

    bool getFlyingPlane();
    void setFlyingPlane(bool change);

    void checkForInfection(const std::vector<Circle*>&);
    void update(int);

//    QPointF getCenter();

    Airport* askForPlane(const std::vector<Airport*>&);

private:
    const int neededNumberOfInfected = 5;
    int timer = 0;

    QPointF localPosition;
    QPointF position;
    bool isClosed;
    bool isInfected;
    Picture* picture = nullptr;
    Picture* airport = nullptr;
    Picture* airportInfected = nullptr;
    int nextPlane = 0;
    bool isFlyingPlane = false;
    //std::vector<Plane*> planes;
};

#endif // AIRPORT_H
