#include "country.h"

#include <QDebug>

std::mt19937 rnd(time(0));

Country::Country(Plague* plague_, const QString& name_, const QPointF& position_, int population_, int addDna_, int frequency_, const QString& fileName_, int width_, int height_) {
    timer = 0;
    name = name_;
    population = population_;
    infected = 0;
    dead = 0;
    frequency = frequency_;
    lastAirport = frequency_;
    addDna = addDna_;
    updateTimer = 0;
    infectionPosition = std::nullopt;
    infectionSpeed = std::nullopt;
    picture = new Picture(fileName_, position_, width_, height_);
    picture->setZValue(2.0);
    plague = plague_;
}

Country::~Country() {
    delete picture;
}

Country::Country(const Country& country) {
    timer = country.timer;
    updateTimer = country.updateTimer;
    name = country.name;
    population = country.population;
    infected = country.infected;
    dead = country.dead;
    addDna = country.addDna;
    frequency = country.frequency;
    lastAirport = country.lastAirport;
    infectionPosition = country.infectionPosition;
    infectionSpeed = country.infectionSpeed;
    picture = new Picture(country.picture);
    infectedZone = country.infectedZone;
    airports = country.airports;
    lastVisited = country.lastVisited;
    plague = country.plague;
}

Country& Country::operator=(const Country& country) {
    if (&country == this) {
        return *this;
    }
    timer = country.timer;
    updateTimer = country.updateTimer;
    name = country.name;
    population = country.population;
    infected = country.infected;
    dead = country.dead;
    addDna = country.addDna;
    frequency = country.frequency;
    lastAirport = country.lastAirport;
    infectionPosition = country.infectionPosition;
    infectionSpeed = country.infectionSpeed;
    picture = new Picture(country.picture);
    infectedZone = country.infectedZone;
    airports = country.airports;
    lastVisited = country.lastVisited;
    plague = country.plague;
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

void Country::generateInfection(QPointF point) {
    for (int it = 0; it < 3; it++)
    {
        for (int i = 0; i < static_cast<int>(infectedZone.size()); i++) {
            if (infectedZone.size() > 400) {
                break;
            }
            Circle* circle = infectedZone[i];
            double deltaX = circle->radius + 1 + rnd() % 10;
            double deltaY = circle->radius + 1 + rnd() % 10;

            for (int dx = -1; dx < 2; dx = (dx == -1 ? 1 : dx + 1)) {
                for (int dy = -1; dy < 2; dy = (dy == -1 ? 1 : dy + 1)) {
                    QPointF position(circle->localPosition.x() + dx * deltaX, circle->localPosition.y() + dy * deltaY);
                    if (Circle::getDistance(position, infectionPosition.value()) < Circle::getDistance(circle->localPosition, infectionPosition.value())) {
                        continue;
                    }
                    if (picture->isOnPicture(position)) {
                        Circle* newCircle = new Circle(Circle(circle->localPosition.x() + deltaX * dx, circle->localPosition.y() + deltaY * dy, picture->getPosition()));

                        bool isNear = false;
                        for (int j = 0; j < static_cast<int>(infectedZone.size()); j++) {
                            if (Circle::getDistance(infectedZone[j]->localPosition, newCircle->localPosition) < infectedZone[j]->radius) {
                                isNear = true;
                            }
                        }
                        if (isNear) {
                            continue;
                        }

                        infectedZone.push_back(newCircle);
                    }
                }
            }
        }
    }
    std::reverse(infectedZone.begin(), infectedZone.end());
}

// in local
void Country::startInfected(const QPointF& point) {
    if (infectionPosition != std::nullopt) {
        return;
    }
    infectionPosition = point;
    infectedZone.push_back(new Circle(point, picture->getPosition()));
    lastVisited.push_back(infectedZone.back());
    infected++;

    generateInfection(point);

    for (size_t i = 0; i < airports.size(); i++) {
        airports[i]->setInfected(true);
    }

    plague->changeDna(addDna);

    picture->changePixmap(QColor(200, 0, 0, 40));
}

Airport* Country::checkAirport() {
    if (lastAirport < frequency) {
        return nullptr;
    }
    lastAirport = 0;
    int size = airports.size();
    if (size == 0) {
        return nullptr;
    }
    int i = rnd() % size;
    return airports[i];
}

void Country::endInfection() {
    infectionPosition = std::nullopt;
    for (size_t i = 0; i < airports.size(); i++) {
        airports[i]->setInfected(false);
    }
}

void Country::recalculatePopulation(int infectivity, int severity, int lethality) {
    if (infectionPosition == std::nullopt) {
        return;
    }
    if (updateTimer < 1000) {
        return;
    }
    updateTimer = 0;
    int changeInf = std::min(static_cast<int>(std::ceil(1.0 * infected * lethality / 100.0)), infected);
    int changePop = std::min(static_cast<int>(std::ceil(1.0 * population * infectivity / 1000000.0)), population);
    dead += changeInf;
    infected -= changeInf;
    infected += changePop;
    population -= changePop;
}

Rebuild Country::update(int miliseconds) {
    timer += miliseconds;
    updateTimer += miliseconds;

    lastAirport++;
    Rebuild result;

    for (Airport* airport: airports) {
        airport->checkForInfection(infectedZone);
        airport->update(miliseconds);
        if (airport->getInfection()) {
            startInfected(airport->getLocalPosition(getPicture()->getPosition()));
        }
    }

    if (infectionPosition == std::nullopt) {
        return result;
    }

    if (timer < 1000) {
        return result;
    }

    timer = 0;

    int size = infectedZone.size();
    int add = 5 + rnd() % 5;
    add = std::min(add, size);
    while (add > 0) {
        result.addCircle.push_back(infectedZone.back());
        infectedZone.pop_back();
        add--;
    }

    return result;
}

