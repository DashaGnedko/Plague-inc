#ifndef COUNTRY_H
#define COUNTRY_H

#pragma once

#include <QString>
#include <QPointF>
#include <optional>
#include <random>

#include "picture.h"
#include "circle.h"
#include "rebuild.h"
#include "airport.h"
#include "plague.h"

class Country {
public:
    Country(Plague*, const QString&, const QPointF&, int, int, int, const QString&, int, int);
    ~Country();
    Country(const Country&);
    Country& operator=(const Country&);

    QString getName();
    QPointF getPosition();
    int getPopulation();
    int getInfected();
    int getDead();
    Picture* getPicture();
    std::vector<Circle*> getInfectedZone();
    std::vector<Airport*> getAirport();

    void addAirport(Airport*);
    Airport* checkAirport();

    void generateInfection(QPointF);
    void startInfected(const QPointF&);
    Rebuild update(int);

    void recalculatePopulation(int, int, int);
    void endInfection();

private:
    int timer = 0;

    QString name;
    int population;
    int infected;
    int dead;
    int frequency;
    int lastAirport;
    int updateTimer;
    int addDna;
    std::optional<QPointF> infectionPosition;
    std::optional<double> infectionSpeed;
    Picture* picture = nullptr;
    std::vector<Circle*> infectedZone;
    std::vector<Airport*> airports;
    std::vector<Circle*> lastVisited;
    Plague* plague;
};

#endif // COUNTRY_H
