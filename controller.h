#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include "continent.h"
#include "plane.h"
#include "infobar.h"
#include "progress.h"
#include "plague.h"
#include <QFile>

class Controller {
public:
    Controller();
    Continent* operator[](int);
    Continent* getIndex(int);
    int size();
    void addContinent(Continent*);
    void addPlane(Plane*);
    Rebuild update(int);
    std::vector<Plane*> getPlanes();
    InfoBar* getInfobar();
    Progress* getProgress();
    Plague* getPlague();
    void setCurrentCountry(Country*);
    MyText* getCureProgress();

    void recalculateDna();
    void updateSelection(QGraphicsItem*);
    void recalculateMenuBar();

    void readFromFile(const QString&, Continent*);

private:
    std::vector<Continent*> continents;
    std::vector<Plane*> planes;
    InfoBar* infobar = nullptr;
    Progress* progress = nullptr;
    MyText* cureProgress = nullptr;
    Plague* plague = nullptr;
    Country* currentCountry = nullptr;
};

#endif // CONTROLLER_H
