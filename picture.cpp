#include "picture.h"

Picture::Picture(const QString& fileName_, const QPointF& position_, int width_, int height_) {
    fileName = fileName_;
    position = position_;
    width = width_;
    height = height_;
    pixmap.load(fileName);
    pixmap = pixmap.scaled(width, height);
    pixmapItem = new QGraphicsPixmapItem(pixmap);
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
    pixmapItem = new QGraphicsPixmapItem(pixmap);
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
    pixmapItem = new QGraphicsPixmapItem(pixmap);
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
    pixmapItem = new QGraphicsPixmapItem(pixmap);
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

QGraphicsPixmapItem* Picture::getItem() {
    return pixmapItem;
}

void Picture::setPixmap(const QPixmap& pixmap_) {
    pixmap = pixmap_;
    pixmapItem->setPixmap(pixmap_);
}

void Picture::setPixmapItemPosition(const QPointF& point) {
    position = point;
    pixmapItem->setPos(point);
}

void Picture::setZValue(double value) {
    pixmapItem->setZValue(value);
}

bool Picture::isOnPicture(QPointF point) {
    return path.contains(point);
}

bool Picture::isOnPicture(double x, double y) {
    return path.contains(QPointF(x, y));
}
