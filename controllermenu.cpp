#include "controllermenu.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

ControllerMenu::ControllerMenu(Controller* mainController_) {
    mainController = mainController_;

    dnaNumber = new MyText(QString::number(mainController->getPlague()->getDna()), QPointF(120, 1030));

    infectivity = new MenuBar(nullptr, 0, 98, QPointF(389, 1038), QPointF(753, 1061), QColor(179, 0, 120), QBrush(QColor(179, 0, 120)));
    severity = new MenuBar(nullptr, 0, 98, QPointF(963, 1038), QPointF(1326, 1061), QColor(255, 255, 69), QBrush(QColor(255, 255, 69)));
    lethality = new MenuBar(nullptr, 0, 98, QPointF(1534, 1038), QPointF(1898, 1061), QColor(124, 20, 198), QBrush(QColor(124, 20, 198)));
    //severity = new MenuBar(new MyText("SEVERITY", QPointF(750, 1035)), new MyRectangle(850, 1035, 1070, 1065, QColor(242, 253, 77), QBrush(QColor(242, 253, 77, 40))));
    //lethality = new MenuBar(new MyText("LETHALITY", QPointF(1150, 1035)), new MyRectangle(1250, 1035, 1470, 1065, QColor(124, 34, 91), QBrush(QColor(124, 34, 91, 40))));

    update = new Update();
    readFromFile(update);

    update->setCurrentDisease(update->getElement(0));


    //updates.push_back(update);


    diseaseBar = new DiseaseBar(new MyText(update->getElement(0)->getName(), QPointF(20, 766)),
                                new MyText("\\\\ " + update->getElement(0)->getDescription(), QPointF(207, 886)),
                                new MyText("\\\\ " + QString::number(update->getElement(0)->getCost()) + " DNA Points", QPointF(1050, 890)),
                                update->getElement(0)->getPicture(),
                                new Picture("D:/Code QT/Plague-inc/devolve-button.png", QPointF(1050, 924)),
                                new Picture("D:/Code QT/Plague-inc/evolve-button.png", QPointF(1050, 924)));

    update->getElement(0)->buy(mainController, diseaseBar, infectivity, severity, lethality);
}

ControllerMenu::~ControllerMenu() {
    delete infectivity;
    delete severity;
    delete lethality;
    delete update;
}

void ControllerMenu::readFromFile(Update* update) {
    QFile countriesFile(":/json/disease.json");
    countriesFile.open(QIODevice::ReadOnly);
    QJsonDocument countriesJson(QJsonDocument::fromJson(countriesFile.readAll()));
    QJsonArray countriesArr = countriesJson.array();
    for (int i = 0; i < countriesArr.size(); i++) {
        auto dis = countriesArr[i].toObject();
        Disease* disease = new Disease(dis["name"].toString(),
                                       dis["description"].toString(),
                                       dis["infectivity"].toInt(),
                                       dis["severity"].toInt(),
                                       dis["lethality"].toInt(),
                                       dis["cost"].toInt(),
                                       new Picture(dis["file"].toString(), QPointF(dis["x"].toInt(), dis["y"].toInt())));
        update->addDisease(disease);
    }
    countriesFile.close();
}

MyText* ControllerMenu::getDnaNumber() {
    return dnaNumber;
}

MenuBar* ControllerMenu::getInfectivity() {
    return infectivity;
}

MenuBar* ControllerMenu::getSeverity() {
    return severity;
}

MenuBar* ControllerMenu::getLethality() {
    return lethality;
}

Update* ControllerMenu::getUpdates() {
    return update;
}

DiseaseBar* ControllerMenu::getDiseaseBar() {
    return diseaseBar;
}

void ControllerMenu::setPrediction(Disease* disease) {
    if (disease->getBought()) {
        infectivity->setPrediction(0);
        severity->setPrediction(0);
        lethality->setPrediction(0);
        return;
    }
    infectivity->setPrediction(disease->getInfectivityChange());
    severity->setPrediction(disease->getSeverityChange());
    lethality->setPrediction(disease->getLethalityChange());
}

void ControllerMenu::updateCurrentDisease() {
    update->getCurrentDisease()->updateDisease(mainController, diseaseBar, infectivity, severity, lethality);
    dnaNumber->text = QString::number(mainController->getPlague()->getDna());
    dnaNumber->item->setPlainText(dnaNumber->text);
    mainController->recalculateDna();
}

void ControllerMenu::recalculateDna() {
    dnaNumber->text = QString::number(mainController->getPlague()->getDna());
    dnaNumber->item->setPlainText(dnaNumber->text);
}
