#include "controller.h"

#include <QDebug>

Controller::Controller() {
    Continent* continent = new Continent("Jeju island");
    Country* jeju = new Country("Jeju", QPointF(300, 300), 2345, "D:/Code QT/Plague-inc/jeju-island.png", 200, 200);
    Country* island = new Country("Island", QPointF(50, 50), 2345, "D:/Code QT/Plague-inc/island.png", 150, 150);
    continent->addCountry(jeju);
    continent->addCountry(island);

    Airport* airport = new Airport(QPointF(450, 350), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airport->getPicture()->setZValue(1.0);
    jeju->addAirport(airport);
    jeju->startInfected(QPointF(74, 78));

    Airport* airportIsland = new Airport(QPointF(120, 120), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland->getPicture()->setZValue(1.0);
    island->addAirport(airportIsland);

    Plane* plane = new Plane(airport, airportIsland, "D:/Code QT/Plague-inc/plane.png", 25, 25);
    plane->getPicture()->setZValue(0.5);
    plane->setInfected(true); // !!!
    addPlane(plane);

    //qDebug() << plane->getPicture()->getPosition() << " " << airport->getPicture()->getPosition();
    //exit(0);

    addContinent(continent);
}

Continent* Controller::operator[](int index) {
    return continents[index];
}

Continent* Controller::getIndex(int index) {
    return continents[index];
}

int Controller::size() {
    return continents.size();
}

void Controller::addContinent(Continent* continent) {
    continents.push_back(continent);
}

void Controller::addPlane(Plane* plane) {
    planes.push_back(plane);
}

std::vector<Plane*> Controller::getPlanes() {
    return planes;
}

Rebuild Controller::update(int miliseconds) {
    Rebuild result;
    for (Continent* continent: continents) {
        result.merge(continent->update(miliseconds));
    }
    int newSize = 0;
    for (int i = 0; i < static_cast<int>(planes.size()); i++) {
        Plane* plane = planes[i];
        plane->update(miliseconds);
        if (plane->isReachDestination()) {
            delete plane;
            continue;
        }
        planes[newSize++] = planes[i];
    }
    while (static_cast<int>(planes.size()) > newSize) {
        planes.pop_back();
    }
    return result;
}
