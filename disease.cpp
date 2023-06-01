#include "disease.h"

#include <QDebug>

Disease::Disease(const QString& name_, const QString& description_, int infectivityChange_,
                 int severityChange_, int lethalityChange_, int cost_, Picture* picture_) {
    name = name_;
    description = description_;
    infectivityChange = infectivityChange_;
    severityChange = severityChange_;
    lethalityChange = lethalityChange_;
    cost = cost_;
    isBought = false;
    picture = picture_;
}

Disease::~Disease() {
    delete picture;
}

Disease::Disease(const Disease& disease) {
    name = disease.name;
    description = disease.description;
    infectivityChange = disease.infectivityChange;
    severityChange = disease.severityChange;
    lethalityChange = disease.lethalityChange;
    cost = disease.cost;
    isBought = disease.isBought;
    picture = new Picture(disease.picture);
}

Disease& Disease::operator=(const Disease& disease) {
    if (&disease == this) {
        return *this;
    }
    name = disease.name;
    description = disease.description;
    infectivityChange = disease.infectivityChange;
    severityChange = disease.severityChange;
    lethalityChange = disease.lethalityChange;
    cost = disease.cost;
    isBought = disease.isBought;
    picture = new Picture(disease.picture);
    return *this;
}

QString Disease::getName() {
    return name;
}

QString Disease::getDescription() {
    return description;
}

int Disease::getInfectivityChange() {
    return infectivityChange;
}

int Disease::getSeverityChange() {
    return severityChange;
}

int Disease::getLethalityChange() {
    return lethalityChange;
}

int Disease::getCost() {
    return cost;
}

Picture* Disease::getPicture() {
    return picture;
}

bool Disease::getBought() {
    return isBought;
}

void Disease::setSelection(DiseaseBar* bar) {
    bar->setDisease(name, description, cost, picture, isBought);
}

void Disease::buy(Controller* mainController, DiseaseBar* bar, MenuBar* infectivityBar, MenuBar* severityBar, MenuBar* lethalityBar) {
    if (mainController->getPlague()->getDna() < cost) {
        return;
    }
    isBought = true;
    mainController->getPlague()->update(infectivityChange, severityChange, lethalityChange, -cost);
    bar->changeButton(isBought);

    infectivityBar->setCurrentLevel(mainController->getPlague()->getInfectivity());
    infectivityBar->setPrediction(0);

    severityBar->setCurrentLevel(mainController->getPlague()->getSeverity());
    severityBar->setPrediction(0);

    lethalityBar->setCurrentLevel(mainController->getPlague()->getLethality());
    lethalityBar->setPrediction(0);
}

void Disease::sell(Controller* mainController, DiseaseBar* bar, MenuBar* infectivityBar, MenuBar* severityBar, MenuBar* lethalityBar) {
    isBought = false;
    bar->changeButton(isBought);
    mainController->getPlague()->update(-infectivityChange, -severityChange, -lethalityChange, cost);

    infectivityBar->setCurrentLevel(mainController->getPlague()->getInfectivity());
    infectivityBar->setPrediction(infectivityChange);

    severityBar->setCurrentLevel(mainController->getPlague()->getSeverity());
    severityBar->setPrediction(severityChange);

    lethalityBar->setCurrentLevel(mainController->getPlague()->getLethality());
    lethalityBar->setPrediction(lethalityChange);
}

void Disease::updateDisease(Controller* mainController, DiseaseBar* bar, MenuBar* infectivity, MenuBar* severity, MenuBar* lethality) {
    if (!isBought) {
        buy(mainController, bar, infectivity, severity, lethality);
    } else {
        sell(mainController, bar, infectivity, severity, lethality);
    }
}
