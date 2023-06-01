#ifndef MYTEXT_H
#define MYTEXT_H

#pragma once

#include <QString>
#include <QGraphicsItem>


class MyText {
public:
    MyText(const QString&);
    MyText(const QString&, const QPointF&);

    void setText(const QString&);
    void setPosition(const QPointF&);

    void addPosition();

    //QString getText();
    //QGraphicsTextItem* getItem();

    //void setText(const QString&);
    //void setItem(QGraphicsTextItem*);

    QString text = "";
    QPointF position;
    QGraphicsTextItem* item = nullptr;
};

#endif // MYTEXT_H
