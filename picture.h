#ifndef PICTURE_H
#define PICTURE_H

#pragma once

#include <QString>
#include <QBitmap>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Picture {
public:
    Picture(const QString&, const QPointF&, int, int);
    Picture(Picture*);
    ~Picture();
    Picture(const Picture&);
    Picture& operator=(const Picture&);

    QString getFileName();
    QPointF getPosition();
    int getWidth();
    int getHeight();
    QPixmap* getPixmap();
    QGraphicsPixmapItem* getItem();
    void setPixmap(const QPixmap&);
    void setPixmapItemPosition(const QPointF&);
    void setZValue(double);
    bool isOnPicture(QPointF);
    bool isOnPicture(double, double);

private:
    QString fileName;
    QPointF position;
    int width;
    int height;
    QPixmap pixmap;
    //QBitmap bitmap;
    QGraphicsPixmapItem* pixmapItem = nullptr;
    QPainterPath path;
};

#endif // PICTURE_H
