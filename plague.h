#ifndef PLAGUE_H
#define PLAGUE_H

#pragma once

#include <QString>

class Plague {
public:
    Plague(const QString&);

private:
    QString name;
    double infectivity;
    double severity;
    double lethality;
    int dna;
    double cure;
};

#endif // PLAGUE_H
