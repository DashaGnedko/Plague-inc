#include "mytext.h"

MyText::MyText(const QString& text_) {
    text = text_;
    position = QPointF(0, 0);
}

MyText::MyText(const QString& text_, const QPointF& position_) {
    text = text_;
    position = position_;
}

void MyText::setText(const QString& text_) {
    text = text_;
    if (item != nullptr) {
        item->setPlainText(text_);
    }
}

void MyText::setPosition(const QPointF& position_) {
    position = position_;
    item->setPos(position);
}

void MyText::addPosition() {
    item->setPos(position);
}

//QString MyText::getText() {
//    return text;
//}

//QGraphicsTextItem* MyText::getItem() {
//    return item;
//}

//void MyText::setText(const QString& text_) {
//    text = text_;
//}

//void MyText::setItem(QGraphicsTextItem* item_) {
//    item = item_;
//}
