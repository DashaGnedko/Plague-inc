#ifndef UPDATE_H
#define UPDATE_H

#pragma once

#include "disease.h"
#include <vector>

class Update {
public:
    Update();
    ~Update();

    void addDisease(Disease*);
    int size();
    Disease* getElement(int);

private:
    std::vector<Disease*> updates;
};

#endif // UPDATE_H
