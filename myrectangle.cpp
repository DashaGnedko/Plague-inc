#include "myrectangle.h"

MyRectangle::MyRectangle(double startX, double startY, double endX, double endY, QPen pen_, QBrush brush_, QGraphicsRectItem* ptr_) {
    rect = QRectF(QPointF(startX, startY), QPointF(endX, endY));
    pen = pen_;
    brush = brush_;
    begin = QPointF(startX, startY);
    end = QPointF(endX, endY);
    item = ptr_;
}

MyRectangle::MyRectangle(const MyRectangle& rectangle) {
    rect = rectangle.rect;
    begin = rectangle.begin;
    end = rectangle.end;
    pen = rectangle.pen;
    brush = rectangle.brush;
    item = nullptr;
}

MyRectangle MyRectangle::operator[](const MyRectangle& rectangle) {
    if (&rectangle == this) {
        return *this;
    }
    rect = rectangle.rect;
    begin = rectangle.begin;
    end = rectangle.end;
    pen = rectangle.pen;
    brush = rectangle.brush;
    item = nullptr;
    return *this;
}

void MyRectangle::change(double startX, double startY, double endX, double endY, QPen pen_, QBrush brush_) {
    rect = QRectF(QPointF(startX, startY), QPointF(endX, endY));
    pen = pen_;
    brush = brush_;
    begin = QPointF(startX, startY);
    end = QPointF(endX, endY);
}
