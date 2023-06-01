#include "plane.h"

#include <QDebug>

Plane::Plane(Airport* start_, Airport* finish_, const QString& fileName, int width, int height) {
    timer = 0;
    startAirport = start_;
    start = start_->getPosition();
    finishAirport = finish_;
    finish = finish_->getPosition();
    current = start;
    isInfected = startAirport->getInfection();

    startAirport->setFlyingPlane(true);
    finishAirport->setFlyingPlane(true);

    double dx = finish.x() - start.x();
    double dy = finish.y() - start.y();
    double angle = atan2(dy, dx) + acos(-1) / 2;

    picture = new Picture(fileName, current, width, height, angle);

    deltaX = finish.x() - start.x();
    deltaY = finish.y() - start.y();
    double maximum = std::max(std::abs(deltaX), std::abs(deltaY));
    if (maximum < 1) {
        maximum = 1;
    }
    deltaX /= maximum;
    deltaY /= maximum;

    picture->setZValue(0.5);
}

Plane::~Plane() {
    delete picture;
}

Plane::Plane(const Plane& plane) {
    startAirport = plane.startAirport;
    finishAirport = plane.finishAirport;
    timer = plane.timer;
    start = plane.start;
    finish = plane.finish;
    current = plane.current;
    isInfected = plane.isInfected;
    deltaX = plane.deltaX;
    deltaY = plane.deltaY;
    picture = new Picture(plane.picture);
}

Plane& Plane::operator=(const Plane& plane) {
    if (&plane == this) {
        return *this;
    }
    startAirport = plane.startAirport;
    finishAirport = plane.finishAirport;
    timer = plane.timer;
    start = plane.start;
    finish = plane.finish;
    current = plane.current;
    isInfected = plane.isInfected;
    deltaX = plane.deltaX;
    deltaY = plane.deltaY;
    picture = new Picture(plane.picture);
    return *this;
}

QPointF Plane::getStart() {
    return start;
}

QPointF Plane::getFinish() {
    return finish;
}

QPointF Plane::getCurrent() {
    return current;
}

bool Plane::getInfected() {
    return isInfected;
}

Picture* Plane::getPicture() const {
    return picture;
}

void Plane::setInfected(bool infection) {
    isInfected = infection;
}

bool Plane::between(double x, double y, double z) {
    if (x > z) {
        std::swap(x, z);
    }
    return (x <= y && y <= z);
}

void Plane::update(int miliseconds) {
    timer += miliseconds;
    if (timer < 10) {
        return;
    }
    timer = 0;
    double newX = current.x() + deltaX;
    double newY = current.y() + deltaY;
    if (between(current.x(), finish.x(), newX)) {
        newX = finish.x();
    }
    if (between(current.y(), finish.y(), newY)) {
        newY = finish.y();
    }
    current = QPointF(newX, newY);
    picture->setPixmapItemPosition(current);
}

bool Plane::isReachDestination() {
    if (current == finish) {
        startAirport->setFlyingPlane(false);
        finishAirport->setFlyingPlane(false);
        if (isInfected) {
            finishAirport->setInfected(true);
        }
        return true;
    }
    return false;
}
