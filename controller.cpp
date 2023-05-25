#include "controller.h"

#include <QDebug>

Controller::Controller() {
    Continent* continent = new Continent("Jeju island");
    Country* jeju = new Country("Jeju", QPointF(300, 300), 2345, "D:/Code QT/Plague-inc/jeju-island.png", 200, 200);
    Country* island = new Country("Island", QPointF(50, 50), 2345, "D:/Code QT/Plague-inc/island.png", 150, 150);
    Country* island1 = new Country("Jeju", QPointF(1037, 212), 2345, "D:/Code QT/Plague-inc/island-1.png", 300, 300);
    Country* island2 = new Country("Island", QPointF(1177, 635), 2345, "D:/Code QT/Plague-inc/island-2.png", 200, 200);
    Country* island3 = new Country("Island", QPointF(1620, 299), 2345, "D:/Code QT/Plague-inc/island-3.png", 200, 200);
    continent->addCountry(jeju);
    continent->addCountry(island);
    continent->addCountry(island1);
    continent->addCountry(island2);
    continent->addCountry(island3);

    Airport* airport = new Airport(QPointF(450, 350), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airport->getPicture()->setZValue(1.0);
    jeju->addAirport(airport);
    jeju->startInfected(QPointF(74, 78));

    Airport* airportIsland = new Airport(QPointF(120, 120), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland->getPicture()->setZValue(1.0);
    island->addAirport(airportIsland);

    Airport* airportIsland1 = new Airport(QPointF(1260, 307), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland1->getPicture()->setZValue(1.0);
    island1->addAirport(airportIsland1);

    Airport* airportIsland2 = new Airport(QPointF(1098, 306), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland2->getPicture()->setZValue(1.0);
    island1->addAirport(airportIsland2);

    Airport* airportIsland3 = new Airport(QPointF(1328, 728), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland3->getPicture()->setZValue(1.0);
    island2->addAirport(airportIsland3);

    Airport* airportIsland4 = new Airport(QPointF(1792, 433), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
    airportIsland4->getPicture()->setZValue(1.0);
    island3->addAirport(airportIsland4);

//    Plane* plane = new Plane(airportIsland, airport, "D:/Code QT/Plague-inc/plane.png", 25, 25);
//    plane->getPicture()->setZValue(0.5);
//    //plane->setInfected(true); // !!!
//    addPlane(plane);

    //qDebug() << plane->getPicture()->getPosition() << " " << airport->getPicture()->getPosition();
    //exit(0);

    addContinent(continent);


    // -----------------------------------------------------------

    infobar = new InfoBar(new MyText("World", QPointF(865, 930)),
                          new MyText(("Infected"), QPointF(900, 970)),
                          new MyText(("Dead"), QPointF(1035, 970)),
                          new MyText(("Infected number"), QPointF(0, 600)),
                          new MyText(("Dead number"), QPointF(20, 600)),
                          new Picture("D:/Code QT/Plague-inc/world_icon.png", QPointF(733, 955), 100, 100),
                          new Picture("D:/Code QT/Plague-inc/virus.png", QPointF(865, 970), 30, 30),
                          new Picture("D:/Code QT/Plague-inc/skull.png", QPointF(1000, 970), 30, 30),
                          new MyRectangle(700, 920, 1276, 1077, QColor(14, 33, 40), QBrush(QColor(14, 33, 40, 200))),
                          new MyRectangle(875, 1031, 1200, 1050, QColor(0, 0, 255), QBrush(QColor(0, 0, 255))),
                          new MyRectangle(875, 1031, 900, 1050, QColor(142, 33, 43), QBrush(QColor(76, 9, 16))));


    progress = new Progress(new MyText("Disease", QPointF(20, 600)),
                            new MyText("39", QPointF(40, 600)),
                            new Picture("D:/Code QT/Plague-inc/dna.png", QPointF(20, 650), 30, 30),
                            new Picture("D:/Code QT/Plague-inc/menu.png", QPointF(210, 1005), 30, 30),
                            new MyRectangle(0, 1000, 250, 1072, QColor(14, 33, 40), QBrush(QColor(14, 33, 40, 200))),
                            new MyRectangle(170, 680, 270, 690, QColor(0, 0, 255), QBrush(QColor(0, 0, 255))),
                            new MyRectangle(170, 680, 270, 690, QColor(0, 0, 255), QBrush(QColor(0, 0, 255)))
                            );

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
    qDebug() << "!!! " << plane->getStart() << " " << plane->getFinish();
    planes.push_back(plane);
}

std::vector<Plane*> Controller::getPlanes() {
    return planes;
}

InfoBar* Controller::getInfobar() {
    return infobar;
}

Progress* Controller::getProgress() {
    return progress;
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

    std::vector<Airport*> airports;
    for (Continent* continent: continents) {
        std::vector<Country*> allCountries = continent->getCountries();
        for (Country* country: allCountries) {
            for (Airport* airport: country->getAirport()) {
                airports.push_back(airport);
            }
        }
    }

    for (Airport* airport: airports) {
        Airport* finish = airport->askForPlane(airports);
        if (finish != nullptr) {
            //qDebug() << "NEW PLANE";
            Plane* newPlane = new Plane(airport, finish, "D:/Code QT/Plague-inc/plane.png", 25, 25);
            addPlane(newPlane);
            result.addPlane.push_back(newPlane);
            break;
        }
    }


    return result;
}
