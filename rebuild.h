#ifndef REBUILD_H
#define REBUILD_H

#pragma once

#include "circle.h"
#include "plane.h"
#include <vector>

class Rebuild {
public:
    std::vector<Circle*> deleteCircle;
    std::vector<Circle*> addCircle;
    std::vector<Plane*> addPlane;

    void merge(const Rebuild&);
};

#endif // REBUILD_H
