#include "continent.h"

Continent::Continent(const QString& name_) {
    name = name_;
}

void Continent::addCountry(Country* country) {
    countries.push_back(country);
}

int Continent::size() {
    return countries.size();
}

Country* Continent::operator[](int index) {
    return countries[index];
}

Country* Continent::getIndex(int index) {
    return countries[index];
}

std::vector<Country*> Continent::getCountries() {
    return countries;
}

Rebuild Continent::update(int miliseconds) {
    timer += miliseconds;
    Rebuild result;
    for (Country* country: countries) {
        result.merge(country->update(miliseconds));
    }
    return result;
}
