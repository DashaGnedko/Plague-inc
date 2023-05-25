#include "update.h"

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
