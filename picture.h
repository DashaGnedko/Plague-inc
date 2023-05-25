#ifndef PICTURE_H
#define PICTURE_H

#pragma once

#include <QString>
#include <QBitmap>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "customitem.h"

class Picture {
public:
    Picture(const QString&, const QPointF&, int, int, double angle = 0);
    Picture(Picture*);
    ~Picture();
    Picture(const Picture&);
    Picture& operator=(const Picture&);

    QString getFileName();
    QPointF getPosition();
    int getWidth();
    int getHeight();
    QPixmap* getPixmap();
    CustomItem* getItem();
    void setPixmap(const QPixmap&);
    void changePixmap(const QColor&);
    void setPixmapItemPosition(const QPointF&);
    void setZValue(double);
    void setRotation(double);
    bool isOnPicture(QPointF);
    bool isOnPicture(double, double);

private:
    QString fileName;
    QPointF position;
    int width;
    int height;
    QPixmap pixmap;
    //QBitmap bitmap;
    CustomItem* pixmapItem = nullptr;
    QPainterPath path;
};

#endif // PICTURE_H
