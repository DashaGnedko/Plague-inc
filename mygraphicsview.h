#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView {
public:
    MyGraphicsView(QGraphicsView* parent = nullptr);
    void paintEvent(QPaintEvent*);

private:
    QGraphicsView* parent = nullptr;
};

#endif // MYGRAPHICSVIEW_H
