#ifndef PLAGUE_H
#define PLAGUE_H

#pragma once

#include <QString>
#include <cmath>

class Plague {
public:
    Plague(const QString&);

    int getInfectivity();
    int getSeverity();
    int getLethality();
    int getDna();
    int getCure();
    double getDoubleCure();

    void setCure(double);

    void changeDna(int);
    void update(int, int, int, int);

private:
    QString name;
    int infectivity = 0; //
    int severity = 0; //
    int lethality = 0; //
    int dna;
    double cure;
};

#endif // PLAGUE_H
