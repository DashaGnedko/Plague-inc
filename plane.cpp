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
    double angle = dy;
    angle /= std::sqrt(dx * dx + dy * dy);
    angle = acos(angle);
    angle *= 360 /  acos(-1);
//    if (dx > 0) {
//        angle = 360 - angle;
//    }

    //if (angle != 0) qDebug() << "!!!! " << angle << " " << dx;


    //exit(0);



    picture = new Picture(fileName, current, width, height, angle);
    //picture->setRotation(275);
    //picture->setRotation(360 - QLineF(0, 0, 0, -1).angleTo(QLineF(0, 0, deltaX, deltaY)));

    deltaX = finish.x() - start.x();
    deltaY = finish.y() - start.y();
    double maximum = std::max(std::abs(deltaX), std::abs(deltaY));
    if (maximum < 1) {
        maximum = 1;
    }
    deltaX /= maximum;
    deltaY /= maximum;

    //picture = new Picture(fileName, current, width, height, 275);
    picture->setZValue(0.5);
    //picture->setRotation(275);
    //picture->setRotation(360 - QLineF(0, 0, 0, -1).angleTo(QLineF(0, 0, deltaX, deltaY)));
    //qDebug() << deltaX << " " << deltaY << " " << QLineF(0, 0, deltaX, deltaY).angleTo(QLineF(0, 0, 0, -1));

    //timerFromStart = 0;
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

    //timerFromStart = plane.timerFromStart;
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

    //timerFromStart = plane.timerFromStart;
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
//    timerFromStart += miliseconds;
//    if (timerFromStart < 15000) {
//        timer = 0;
//        return;
//    }
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
