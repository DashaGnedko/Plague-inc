#include "controller.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

std::mt19937 randomGeneration(std::time(0));

Controller::Controller() {
    plague = new Plague("Vova");

    Continent* southAmerica = new Continent("South America");
    readFromFile(":/json/south-america.json", southAmerica);
    Continent* northAmerica = new Continent("North America");
    readFromFile(":/json/north-america.json", northAmerica);
    Continent* greenland = new Continent("Greenland");
    readFromFile(":/json/greenland.json", northAmerica);

    addContinent(southAmerica);
    addContinent(northAmerica);
    addContinent(greenland);

    southAmerica->getIndex(0)->startInfected(QPointF(100, 100));

//    Airport* airport = new Airport(QPointF(450, 350), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airport->getPicture()->setZValue(1.0);
//    jeju->addAirport(airport);
//    jeju->startInfected(QPointF(74, 78));

//    Airport* airportIsland = new Airport(QPointF(120, 120), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airportIsland->getPicture()->setZValue(1.0);
//    island->addAirport(airportIsland);

//    Airport* airportIsland1 = new Airport(QPointF(1260, 307), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airportIsland1->getPicture()->setZValue(1.0);
//    island1->addAirport(airportIsland1);

//    Airport* airportIsland2 = new Airport(QPointF(1098, 306), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airportIsland2->getPicture()->setZValue(1.0);
//    island1->addAirport(airportIsland2);

//    Airport* airportIsland3 = new Airport(QPointF(1328, 728), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airportIsland3->getPicture()->setZValue(1.0);
//    island2->addAirport(airportIsland3);

//    Airport* airportIsland4 = new Airport(QPointF(1792, 433), "D:/Code QT/Plague-inc/airport.png", "D:/Code QT/Plague-inc/airport-infected.png", 30, 30);
//    airportIsland4->getPicture()->setZValue(1.0);
//    island3->addAirport(airportIsland4);

//    Plane* plane = new Plane(airportIsland, airport, "D:/Code QT/Plague-inc/plane.png", 25, 25);
//    plane->getPicture()->setZValue(0.5);
//    //plane->setInfected(true); // !!!
//    addPlane(plane);

    //qDebug() << plane->getPicture()->getPosition() << " " << airport->getPicture()->getPosition();
    //exit(0);


    // -----------------------------------------------------------

    infobar = new InfoBar(new MyText("World", QPointF(745, 912)),
                          new MyText(("0"), QPointF(780, 990)),
                          new MyText(("0"), QPointF(987, 990)),
                          new Picture("D:/Code QT/Plague-inc/world_icon.png", QPointF(733, 955), 100, 100),
                          new MyRectangle(875, 1031, 1200, 1050, QColor(0, 0, 255), QBrush(QColor(0, 0, 255))),
                          new MyRectangle(875, 1031, 900, 1050, QColor(142, 33, 43), QBrush(QColor(76, 9, 16))));


    progress = new Progress(new MyText(QString::number(plague->getDna()), QPointF(66, 1033)),
                            new Picture("D:/Code QT/Plague-inc/menu.png", QPointF(197, 985), INT_MAX, INT_MAX),
                            new MyRectangle(0, 1000, 250, 1072, QColor(14, 33, 40), QBrush(QColor(14, 33, 40, 200)))
                            );

    cureProgress = new MyText(QString::number(plague->getCure()) + "%", QPointF(1695, 1034));

}

void Controller::readFromFile(const QString& file, Continent* continent) {
    QFile countriesFile(file);
    countriesFile.open(QIODevice::ReadOnly);
    QJsonDocument countriesJson(QJsonDocument::fromJson(countriesFile.readAll()));
    QJsonArray countriesArr = countriesJson.array();
    for (int i = 0; i < countriesArr.size(); i++) {
        auto country = countriesArr[i].toObject();
        Country* result = new Country(plague,
                                      country["name"].toString(),
                                      QPointF(country["x"].toInt(), country["y"].toInt()),
                                      country["population"].toInt(),
                                      country["dna"].toInt(),
                                      1000,
                                      country["file"].toString(), INT_MAX, INT_MAX);
        if (country.contains("airports")) {
            QJsonValue value = country["airports"];
            QJsonArray array = value.toArray();
            for (int j = 0; j < array.size(); j++) {
                auto air = array[j].toObject();
                Airport* airport = new Airport(QPointF(air["x"].toInt(), air["y"].toInt()),
                                               ":/icons/airport.png", ":/icons/airport-infected.png", INT_MAX, INT_MAX);
                result->addAirport(airport);
            }
        }
        result->getPicture()->getItem()->setFlag(QGraphicsItem::ItemHasNoContents);
        continent->addCountry(result);
    }
    countriesFile.close();
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
    //qDebug() << "!!! " << plane->getStart() << " " << plane->getFinish();
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

Plague* Controller::getPlague() {
    return plague;
}

void Controller::recalculateDna() {
    progress->setDna(plague->getDna());
}

void Controller::setCurrentCountry(Country* item) {
    currentCountry = item;
}

MyText* Controller::getCureProgress() {
    return cureProgress;
}

void Controller::recalculateMenuBar() {
    if (currentCountry != nullptr) {
        infobar->setInfectedNumber(currentCountry->getInfected());
        infobar->setDeadNumber(currentCountry->getDead());
        infobar->setName(currentCountry->getName());
        return;
    }
    int infected = 0;
    int dead = 0;
    for (Continent* continent: continents) {
        for (int i = 0; i < continent->size(); i++) {
            Country* country = continent->getIndex(i);
            infected += country->getInfected();
            dead += country->getDead();
        }
    }
    infobar->setInfectedNumber(infected);
    infobar->setDeadNumber(dead);
    infobar->setName("World");
}

void Controller::updateSelection(QGraphicsItem* item) {
    if (currentCountry != nullptr) {
        currentCountry->getPicture()->getItem()->setFlag(QGraphicsItem::ItemHasNoContents);
        currentCountry = nullptr;
    }
    for (Continent* continent: continents) {
        for (int i = 0; i < continent->size(); i++) {
            Country* country = continent->getIndex(i);
            if (country->getPicture()->getItem() == item) {
                currentCountry = country;
                currentCountry->getPicture()->getItem()->setFlag(QGraphicsItem::ItemHasNoContents, false);
                break;
            }
        }
        if (currentCountry != nullptr) {
            break;
        }
    }
    recalculateMenuBar();
}

Rebuild Controller::update(int miliseconds) {
    Rebuild result;
    for (Continent* continent: continents) {
        result.merge(continent->update(miliseconds));
    }
    std::vector<Plane*> newPlanes;
    for (int i = 0; i < static_cast<int>(planes.size()); i++) {
        Plane* plane = planes[i];
        plane->update(miliseconds);
        if (plane->isReachDestination()) {
            delete plane;
            continue;
        }
        newPlanes.push_back(planes[i]);
    }
    planes = newPlanes;

    std::vector<Airport*> airports;
    for (Continent* continent: continents) {
        std::vector<Country*> allCountries = continent->getCountries();
        for (Country* country: allCountries) {
            Airport* airport = country->checkAirport();
            if (airport == nullptr) {
                continue;
            }
            airports.push_back(airport);
        }
    }

    if (airports.size() > 1)
    {
        int size = airports.size();
        int i = randomGeneration() % size;
        int j = randomGeneration() % size;
        while (i == j) {
            j = randomGeneration() % size;
        }

        Plane* newPlane = new Plane(airports[i], airports[j], ":/icons/plane.png", 25, 25);
        addPlane(newPlane);
        result.addPlane.push_back(newPlane);
    }

    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < getIndex(i)->size(); j++) {
            getIndex(i)->getIndex(j)->recalculatePopulation(plague->getInfectivity(),
                                                            plague->getSeverity(),
                                                            plague->getLethality());
        }
    }

    double cure =  plague->getDoubleCure();
    //qDebug() << cure << " " << plague->getLethality() / 500.0;
    cure += plague->getLethality() / 10000.0;
    cure += plague->getSeverity() / 100000.0;
    cure += plague->getInfectivity() / 100000.0;
    cure = std::min(cure, 100.0);
    plague->setCure(cure);
    cureProgress->setText(QString::number(plague->getCure()) + "%");

    progress->getProgress()->setText(QString::number(plague->getDna()));

    recalculateMenuBar();

    return result;
}

