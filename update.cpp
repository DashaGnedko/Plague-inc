#include "update.h"

#include <QDebug>

Update::Update() {
}

Update::~Update() {
    for (size_t i = 0; i < updates.size(); i++) {
        delete updates[i];
    }
}

void Update::addDisease(Disease* disease) {
    updates.push_back(disease);
}

int Update::size() {
    return static_cast<int>(updates.size());
}

Disease* Update::getElement(int index) {
    return updates[index];
}

std::vector<Disease*> Update::getDisease() {
    return updates;
}

Disease* Update::getCurrentDisease() {
    return currentSelection;
}

void Update::setCurrentDisease(Disease* disease) {
    currentSelection = disease;
}

Disease* Update::updateSelection(QGraphicsItem* ptr, DiseaseBar* bar) {
    if (currentSelection->getPicture()->getItem() == ptr) {
        return nullptr;
    }
    for (size_t i = 0; i < updates.size(); i++) {
        if (updates[i]->getPicture()->getItem() == ptr) {
            qDebug() << updates[i]->getName();
            if (currentSelection != updates[i]) {
                currentSelection = updates[i];
                updates[i]->setSelection(bar);
                return currentSelection;
            }
            break;
        }
    }
    return nullptr;
}
