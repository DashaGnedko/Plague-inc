#include "airport.h"

#include <QDebug>

Airport::Airport(const QPointF& position_, const QString& fileName_, const QString& fileNameInfected_, int width_, int height_) {
    timer = 0;
    //localPosition = localPosition_;
    position = position_;
    isClosed = false;
    isInfected = false;
    picture = new Picture(fileName_, position, width_, height_);
    airport = new Picture(fileName_, position, width_, height_);
    airportInfected = new Picture(fileNameInfected_, position, width_, height_);
}

Airport::~Airport() {
    delete picture;
    delete airport;
    delete airportInfected;
//    for (Plane* plane: planes) {
//        delete plane;
//    }
}

Airport::Airport(const Airport& newAirport) {
    timer = newAirport.timer;
    position = newAirport.position;
    isClosed = newAirport.isClosed;
    isInfected = newAirport.isInfected;
    picture = new Picture(newAirport.picture);
    airport = new Picture(newAirport.airport);
    airportInfected = new Picture(newAirport.airportInfected);
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
    return *this;
}

//int Airport::size() {
//    return static_cast<int>(planes.size());
//}

//Plane* Airport::operator[](int index) {
//    return planes[index];
//}

QPointF Airport::getLocalPosition(const QPointF& point) {
    return QPointF(position.x() - point.x(), position.y() - point.y());
}

QPointF Airport::getPosition() {
    return picture->getPosition();
}

bool Airport::getInfection() {
    return isInfected;
}
//std::vector<Plane*> Airport::getPlane() const {
//    return planes;
//}

Picture* Airport::getPicture() const {
    return picture;
}

void Airport::setClosed(bool closed_) {
    isClosed = closed_;
}

//void Airport::addPlane(Plane* plane) {
//    planes.push_back(plane);
//}

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
//    for (Plane* plane: planes) {
//        plane->update(miliseconds);
//    }
}

Airport* Airport::askForPlane(const std::vector<Airport*>& airports) {
    std::mt19937 rnd(235345);
    if (timer < 3000) {
        return nullptr;
    }
    timer = 0;
    int size = static_cast<int>(airports.size());
    if (size < 2) {
        return nullptr;
    }
    int index = rnd() % size;
    while (airports[index] == this) {
        index = rnd() % size;
    }
    qDebug() << index;
    return airports[index];
}


