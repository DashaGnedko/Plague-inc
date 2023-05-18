#include "country.h"

#include <QDebug>

std::mt19937 rnd(12345);

Country::Country(const QString& name_, const QPointF& position_, int population_, const QString& fileName_, int width_, int height_) {
    timer = 0;
    name = name_;
    population = population_;
    infected = 0;
    dead = 0;
    infectionPosition = std::nullopt;
    infectionSpeed = std::nullopt;
    picture = new Picture(fileName_, position_, width_, height_);
}

Country::~Country() {
    delete picture;
}

Country::Country(const Country& country) {
    timer = country.timer;
    name = country.name;
    population = country.population;
    infected = country.infected;
    dead = country.dead;
    infectionPosition = country.infectionPosition;
    infectionSpeed = country.infectionSpeed;
    picture = new Picture(country.picture);
    infectedZone = country.infectedZone;
    airports = country.airports;
}

Country& Country::operator=(const Country& country) {
    if (&country == this) {
        return *this;
    }
    timer = country.timer;
    name = country.name;
    population = country.population;
    infected = country.infected;
    dead = country.dead;
    infectionPosition = country.infectionPosition;
    infectionSpeed = country.infectionSpeed;
    picture = new Picture(country.picture);
    infectedZone = country.infectedZone;
    airports = country.airports;
    return *this;
}

QString Country::getName() {
    return name;
}

QPointF Country::getPosition() {
    return picture->getPosition();
}

int Country::getPopulation() {
    return population;
}

int Country::getInfected() {
    return infected;
}

int Country::getDead() {
    return dead;
}

Picture* Country::getPicture() {
    return picture;
}

std::vector<Circle*> Country::getInfectedZone() {
    return infectedZone;
}

std::vector<Airport*> Country::getAirport() {
    return airports;
}

void Country::addAirport(Airport* airport) {
    airports.push_back(airport);
}

// in local
void Country::startInfected(const QPointF& point) {
    if (infectionPosition == std::nullopt) {
        infectionPosition = point;
    }

    infectedZone.push_back(new Circle(point, picture->getPosition()));
    qDebug() << "start infected" << " " << infectionPosition.value();
}

Rebuild Country::update(int miliseconds) {
    timer += miliseconds;
    //qDebug() << "!! " << infectedZone.size();
    Rebuild result;
//    if (infectedZone.empty()) {

//        return result;
//    }

    for (Airport* airport: airports) {
        airport->checkForInfection(infectedZone);
        airport->update(miliseconds);
        if (airport->getInfection()) {
            startInfected(airport->getLocalPosition(getPicture()->getPosition()));
        }
//        Airport* next = airport->askForPlane(airports);
//        if (next != nullptr) {
//            result.addPlane.push_back(new Plane(airport, next, "D:/Code QT/Plague-inc/plane.png", 25, 25));
//        }
    }

    if (infectionPosition == std::nullopt) {
        return result;
    }

    if (timer < 1000) {
        return result;
    }

    timer = 0;

    int size = static_cast<int>(infectedZone.size());
    for (int i = size - 1; i >= 0; i--) {
    //for (int i = 0; i < infectedZone.size(); i++) {
        Circle* circle = infectedZone[i];
        double deltaX = circle->radius + 1 + rnd() % 10;
        double deltaY = circle->radius + 1 + rnd() % 10;
        //bool isOnPicture = false;

        for (int dx = -1; dx < 2; dx = (dx == -1 ? 1 : dx + 1)) {
            for (int dy = -1; dy < 2; dy = (dy == -1 ? 1 : dy + 1)) {
                QPointF position(circle->localPosition.x() + dx * deltaX, circle->localPosition.y() + dy * deltaY);
                if (Circle::getDistance(position, infectionPosition.value()) < Circle::getDistance(circle->localPosition, infectionPosition.value())) {
                    continue;
                }
                if (picture->isOnPicture(position)) {
                    //isOnPicture = true;
                    //deltaX *= dx;
                    //deltaY *= dy;
                    Circle* newCircle = new Circle(Circle(circle->localPosition.x() + deltaX * dx, circle->localPosition.y() + deltaY * dy, picture->getPosition()));

                    bool isNear = false;
                    for (int j = 0; j < static_cast<int>(infectedZone.size()); j++) {
                        if (Circle::getDistance(infectedZone[j]->localPosition, newCircle->localPosition) < infectedZone[j]->radius) {
                            isNear = true;
                            break;
                        }
                    }
                    if (isNear) {
                        continue;
                    }

                    infectedZone.push_back(newCircle);
                    result.addCircle.push_back(newCircle);
                    //break;
                }
            }
//            if (isOnPicture) {
//                break;
//            }
        }
//        if (isOnPicture) {
//            Circle newCircle = Circle(Circle(circle.position.x() + deltaX, circle.position.y() + deltaY, picture->getPosition()));
//            infectedZone.push_back(newCircle);
//            result.addCircle.push_back(newCircle);
//            //break;
//        }
    }

    return result;
}

