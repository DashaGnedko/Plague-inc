#include "picture.h"

#include <QDebug>
#include <cmath>

// Rotation
Picture::Picture(const QString& fileName_, const QPointF& position_, int width_, int height_, double angle) {
    fileName = fileName_;
    position = position_;
    pixmap.load(fileName);
    width = (width_ == INT_MAX ? pixmap.width() : width_);
    height = (height_ == INT_MAX ? pixmap.height() : height_);
    pixmap = pixmap.scaled(width, height).transformed(QTransform().rotateRadians(angle));
    pixmapItem = new CustomItem(pixmap);
//    pixmapItem->setTransformOriginPoint(width / 2, height / 2);
////    if (angle != 0) {
////        qDebug() << "???????????????? " << angle;
////    }
//    pixmapItem->setRotation(angle);
    pixmapItem->setPos(position);
    path = pixmapItem->shape();
}

Picture::Picture(Picture* picture) {
    fileName = picture->fileName;
    position = picture->position;
    width = picture->width;
    height = picture->height;
    pixmap.load(fileName);
    pixmap = pixmap.scaled(width, height);
    //bitmap = pixmap.mask();
    pixmapItem = new CustomItem(pixmap);
    pixmapItem->setPos(position);
    path = pixmapItem->shape();
}

Picture::~Picture() {
    delete pixmapItem;
}

Picture::Picture(const Picture& picture) {
    fileName = picture.fileName;
    position = picture.position;
    width = picture.width;
    height = picture.height;
    pixmap = picture.pixmap;
    //bitmap = picture.bitmap;
    pixmapItem = new CustomItem(pixmap);
    path = pixmapItem->shape();
}

Picture& Picture::operator=(const Picture& picture) {
    if (&picture == this) {
        return *this;
    }
    fileName = picture.fileName;
    position = picture.position;
    width = picture.width;
    height = picture.height;
    pixmap = picture.pixmap;
    //bitmap = picture.bitmap;
    pixmapItem = new CustomItem(pixmap);
    path = pixmapItem->shape();
    return *this;
}

QString Picture::getFileName() {
    return fileName;
}

QPointF Picture::getPosition() {
    return position;
}

int Picture::getWidth() {
    return width;
}

int Picture::getHeight() {
    return height;
}

QPixmap* Picture::getPixmap() {
    return &pixmap;
}

CustomItem* Picture::getItem() {
    return pixmapItem;
}

void Picture::setPixmap(const QPixmap& pixmap_) {
    pixmap = pixmap_;
    pixmapItem->setPixmap(pixmap_);
}

// Add color to CustomItem
void Picture::changePixmap(const QColor& color) {
    pixmapItem->setRed(true);
    pixmapItem->update();
}

void Picture::setSelection(bool isSelected) {
    pixmapItem->setSelection(isSelected);
    pixmapItem->update();
}

void Picture::setPixmapItemPosition(const QPointF& point) {
    position = point;
    pixmapItem->setPos(point);
}

void Picture::setZValue(double value) {
    pixmapItem->setZValue(value);
}

void Picture::setRotation(double degree) {
    pixmapItem->setRotation(degree);
}

bool Picture::isOnPicture(QPointF point) {
    return path.contains(point);
}

bool Picture::isOnPicture(double x, double y) {
    return path.contains(QPointF(x, y));
}
