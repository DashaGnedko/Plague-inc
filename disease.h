#ifndef DISEASE_H
#define DISEASE_H

#pragma once

#include <QString>
#include "picture.h"
#include "diseasebar.h"
#include "controller.h"
#include "menubar.h"

class Disease {
public:
    Disease(const QString&, const QString&, int, int, int, int, Picture*);
    ~Disease();
    Disease(const Disease&);
    Disease& operator=(const Disease&);

    QString getName();
    QString getDescription();
    int getInfectivityChange();
    int getSeverityChange();
    int getLethalityChange();
    int getCost();
    Picture* getPicture();
    bool getBought();

    void setSelection(DiseaseBar*);
    void updateDisease(Controller*, DiseaseBar*, MenuBar*, MenuBar*, MenuBar*);
    void buy(Controller*, DiseaseBar*, MenuBar*, MenuBar*, MenuBar*);
    void sell(Controller*, DiseaseBar*, MenuBar*, MenuBar*, MenuBar*);

private:
    QString name;
    QString description;
    int infectivityChange;
    int severityChange;
    int lethalityChange;
    int cost;
    bool isBought;
    Picture* picture = nullptr;
};

#endif // DISEASE_H
