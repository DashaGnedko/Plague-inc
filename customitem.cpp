#include "customitem.h"

CustomItem::CustomItem(const QPixmap& pixmap) : QGraphicsPixmapItem(pixmap) {
    isRed = false;
}

void CustomItem::setRed(bool red) {
    isRed = red;
}

void CustomItem::setSelection(bool selection) {
    isSelection = selection;
}

void CustomItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->save();

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, pixmap());

//    if (isSelection) {
//        QPixmap pix = pixmap();
//        QPainter pixPainter(&pix);
//        pixPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//        pixPainter.fillRect(pix.rect(), QColor(0, 0, 0, 100));
//        pixPainter.end();

//        painter->drawPixmap(0, 0, pix);
//        return;
//    }

    if (isRed) {
        QPixmap pix = pixmap();
        QPainter pixPainter(&pix);
        pixPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        pixPainter.fillRect(pix.rect(), QColor(255, 0, 0, 150));
        pixPainter.end();

        painter->drawPixmap(0, 0, pix);
    }

    painter->restore();
}
