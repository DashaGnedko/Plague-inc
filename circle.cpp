#include "circle.h"

std::mt19937 gen(12345);

Circle::Circle(double x, double y, QPointF actual, double maxRadius) {
    localPosition = QPointF(x, y);
    position = QPointF(x + actual.x(), y + actual.y());
    radius = 4 + gen() % 5;
    radius = std::min(radius, maxRadius);
    transparent = radius + 1 + gen() % 3;
}

Circle::Circle(QPointF position_, QPointF actual, double maxRadius) {
    localPosition = position_;
    position = QPointF(position_.x() + actual.x(), position_.y() + actual.y());
    radius = (gen() % 3) / 1.0;
    radius = std::min(radius, maxRadius);
    transparent = radius + 1 + gen() % 3;
}

double Circle::getDistance(QPointF first, QPointF second) {
    return std::sqrt((first.x() - second.x()) * (first.x() - second.x()) + (first.y() - second.y()) * (first.y() - second.y()));
}
