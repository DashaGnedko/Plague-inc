#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QGraphicsView* parent_) : QGraphicsView(parent_) {
    parent = parent_;
}

void MyGraphicsView::paintEvent(QPaintEvent* event) {
   QGraphicsView::paintEvent(event);

   QPainter painter(viewport());
   painter.save();

   painter.drawLine(10, 10, 20, 20);

   painter.restore();
}
