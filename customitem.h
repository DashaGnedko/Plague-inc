#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class CustomItem : public QGraphicsPixmapItem {
public:
    CustomItem(const QPixmap&);
    void setRed(bool);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget* widget = nullptr) override;

private:
    bool isRed = false;
};

#endif // CUSTOMITEM_H
