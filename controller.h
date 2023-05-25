#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include "continent.h"
#include "plane.h"
#include "infobar.h"
#include "progress.h"

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

private:
    std::vector<Continent*> continents;
    std::vector<Plane*> planes;
    InfoBar* infobar = nullptr;
    Progress* progress = nullptr;
};

#endif // CONTROLLER_H
