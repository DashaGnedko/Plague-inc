#include "airport.h"

#include <QDebug>

std::mt19937 randomGen(std::time(0));

Airport::Airport(const QPointF& position_, const QString& fileName_, const QString& fileNameInfected_, int width_, int height_) {
    timer = 0;
    position = position_;
    isClosed = false;
    isInfected = false;
    picture = new Picture(fileName_, position, width_, height_);
    airport = new Picture(fileName_, position, width_, height_);
    airportInfected = new Picture(fileNameInfected_, position, width_, height_);
    picture->setZValue(1.0);
    airport->setZValue(1.0);
    airportInfected->setZValue(1.0);
    nextPlane = (randomGen() % 2 == 1 ? (1 + randomGen() % 4) * 60000 : (3 + randomGen() % 10) * 1000) + randomGen() % 1000;
    isFlyingPlane = false;
}

Airport::~Airport() {
    delete picture;
    delete airport;
    delete airportInfected;
}

Airport::Airport(const Airport& newAirport) {
    timer = newAirport.timer;
    position = newAirport.position;
    isClosed = newAirport.isClosed;
    isInfected = newAirport.isInfected;
    picture = new Picture(newAirport.picture);
    airport = new Picture(newAirport.airport);
    airportInfected = new Picture(newAirport.airportInfected);
    nextPlane = newAirport.nextPlane;
    isFlyingPlane = newAirport.isFlyingPlane;
}

Airport& Airport::operator=(const Airport& newAirport) {
    if (&newAirport == this) {
        return *this;
    }
    timer = newAirport.timer;
    position = newAirport.position;
    isClosed = newAirport.isClosed;
    isInfected = newAirport.isInfected;
    picture = new Picture(newAirport.picture);
    airport = new Picture(newAirport.airport);
    airportInfected = new Picture(newAirport.airportInfected);
    nextPlane = newAirport.nextPlane;
    isFlyingPlane = newAirport.isFlyingPlane;
    return *this;
}

QPointF Airport::getLocalPosition(const QPointF& point) {
    return QPointF(position.x() - point.x(), position.y() - point.y());
}

QPointF Airport::getPosition() {
    return picture->getPosition();
}

bool Airport::getInfection() {
    return isInfected;
}

Picture* Airport::getPicture() const {
    return picture;
}

bool Airport::getFlyingPlane() {
    return isFlyingPlane;
}

void Airport::setClosed(bool closed_) {
    isClosed = closed_;
}

void Airport::setFlyingPlane(bool change) {
    isFlyingPlane = change;
}

void Airport::setInfected(bool infection) {
    if (isInfected == infection) {
        return;
    }
    if (!infection) {
        picture->setPixmap(*airport->getPixmap());
    } else {
        picture->setPixmap(*airportInfected->getPixmap());
    }
    isInfected = infection;
}

void Airport::checkForInfection(const std::vector<Circle*>& infectedZone) {
    if (isInfected) {
        return;
    }
    int numberOfCircles = 0;
    double minDistance = 1000000000;
    QPointF position;
    for (Circle* circle: infectedZone) {
        if (numberOfCircles >= neededNumberOfInfected) {
            break;
        }
        minDistance = 1000000000;
        position = picture->getPosition();

        if (picture->isOnPicture(circle->position)) {
            numberOfCircles++;
            continue;
        }

        minDistance = std::min(minDistance, Circle::getDistance(circle->position, position));
        minDistance = std::min(minDistance, Circle::getDistance(circle->position,
                                                                QPointF(position.x() + picture->getWidth(), position.y())));
        minDistance = std::min(minDistance, Circle::getDistance(circle->position,
                                                                QPointF(position.x(), position.y() + picture->getHeight())));
        minDistance = std::min(minDistance, Circle::getDistance(circle->position,
                                                                QPointF(position.x() + picture->getWidth(), position.y() + picture->getHeight())));
        numberOfCircles += (minDistance < circle->radius);
    }
    if (numberOfCircles >= neededNumberOfInfected) {
        setInfected(true);
    }
}

void Airport::update(int miliseconds) {
    timer += miliseconds;

}


