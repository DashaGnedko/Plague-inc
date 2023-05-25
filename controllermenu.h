#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#pragma once

#include "menubar.h"

class ControllerMenu {
public:
    ControllerMenu();
    ~ControllerMenu();

    MenuBar* getInfectivity();
    MenuBar* getSeverity();
    MenuBar* getLethality();

private:
    MenuBar* infectivity = nullptr;
    MenuBar* severity = nullptr;
    MenuBar* lethality = nullptr;
};

#endif // CONTROLLERMENU_H
