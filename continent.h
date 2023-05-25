#ifndef CONTINENT_H
#define CONTINENT_H

#pragma once

#include <Country.h>
#include <vector>

class Continent {
public:
    Continent(const QString&);
    void addCountry(Country*);
    int size();
    Country* operator[](int);
    Country* getIndex(int);
    Rebuild update(int miliseconds);
    std::vector<Country*> getCountries();

private:
    int timer = 0;

    QString name = "";
    std::vector<Country*> countries;
};

#endif // CONTINENT_H
