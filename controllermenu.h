#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#pragma once

#include "menubar.h"
#include "update.h"
#include "controller.h"

class ControllerMenu {
public:
    ControllerMenu(Controller*);
    ~ControllerMenu();

    MyText* getDnaNumber();
    MenuBar* getInfectivity();
    MenuBar* getSeverity();
    MenuBar* getLethality();
    Update* getUpdates();
    DiseaseBar* getDiseaseBar();

    void setPrediction(Disease*);
    void updateCurrentDisease();
    void readFromFile(Update*);

    void recalculateDna();

private:
    //MyText* plagueName = nullptr;
    MyText* dnaNumber = nullptr;
    Controller* mainController = nullptr;
    MenuBar* infectivity = nullptr;
    MenuBar* severity = nullptr;
    MenuBar* lethality = nullptr;
    Update* update = nullptr;
    DiseaseBar* diseaseBar = nullptr;
};

#endif // CONTROLLERMENU_H
