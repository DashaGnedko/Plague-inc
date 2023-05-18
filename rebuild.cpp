#include "rebuild.h"

void Rebuild::merge(const Rebuild& rebuild) {
    for (Circle* circle: rebuild.deleteCircle) {
        deleteCircle.push_back(circle);
    }
    for (Circle* circle: rebuild.addCircle) {
        addCircle.push_back(circle);
    }
    for (Plane* plane: rebuild.addPlane) {
        addPlane.push_back(plane);
    }
}
