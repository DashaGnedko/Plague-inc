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
    std::vector<Disease*> getDisease();
    Disease* getCurrentDisease();
    void setCurrentDisease(Disease*);

    Disease* updateSelection(QGraphicsItem*, DiseaseBar*);

private:
    std::vector<Disease*> updates;
    Disease* currentSelection = nullptr;
};

#endif // UPDATE_H
