#include "plane.h"

#include <QDebug>

Plane::Plane(Airport* start_, Airport* finish_, const QString& fileName, int width, int height) {
    timer = 0;
    startAirport = start_;
    start = start_->getPosition();
    finishAirport = finish_;
    finish = finish_->getPosition();
    current = start;
    isInfected = false;
    picture = new Picture(fileName, current, width, height);
    deltaX = finish.x() - start.x();
    deltaY = finish.y() - start.y();
    double maximum = std::max(std::abs(deltaX), std::abs(deltaY));
    if (maximum < 1) {
        maximum = 1;
    }
    deltaX /= maximum;
    deltaY /= maximum;

    timerFromStart = 0;
}

Plane::~Plane() {
    delete picture;
}

Plane::Plane(const Plane& plane) {
    timer = plane.timer;
    start = plane.start;
    finish = plane.finish;
    current = plane.current;
    isInfected = plane.isInfected;
    picture = new Picture(plane.picture);

    timerFromStart = plane.timerFromStart;
}

Plane& Plane::operator=(const Plane& plane) {
    if (&plane == this) {
        return *this;
    }
    timer = plane.timer;
    start = plane.start;
    finish = plane.finish;
    current = plane.current;
    isInfected = plane.isInfected;
    picture = new Picture(plane.picture);

    timerFromStart = plane.timerFromStart;
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
    //qDebug() << current;
    timer += miliseconds;
    timerFromStart += miliseconds;
    if (timerFromStart < 15000) {
        timer = 0;
        return;
    }
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
        if (isInfected) {
            finishAirport->setInfected(true);
        }
        return true;
    }
    return false;
}
