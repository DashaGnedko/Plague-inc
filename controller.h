#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include "continent.h"
#include "plane.h"

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

private:
    std::vector<Continent*> continents;
    std::vector<Plane*> planes;
};

#endif // CONTROLLER_H
