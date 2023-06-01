#include "plague.h"

Plague::Plague(const QString& name_) {
    name = name_;
    infectivity = 0;
    severity = 0;
    lethality = 0;
    dna = 10; // !!!!!!!!!!!!!!!!!!
    cure = 0;
}

int Plague::getInfectivity() {
    return infectivity;
}

int Plague::getSeverity() {
    return severity;
}

int Plague::getLethality() {
    return lethality;
}

int Plague::getDna() {
    return dna;
}

int Plague::getCure() {
    return std::ceil(cure);
}

double Plague::getDoubleCure() {
    return cure;
}

void Plague::setCure(double cure_) {
    cure = cure_;
}

void Plague::changeDna(int value) {
    dna += value;
}

void Plague::update(int infectivity_, int severity_, int lethality_, int dna_) {
    infectivity += infectivity_;
    severity += severity_;
    lethality += lethality_;
    dna += dna_;
}
