#include "view.h"

View::View(Controller* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

    QPalette palette;
    palette.setColor(QPalette::Base, QColor(148, 189, 229));
    view->setAutoFillBackground(true);
    view->setPalette(palette);
    //view->setDragMode(QGraphicsView::NoDrag);
    //view->setFocusPolicy(Qt::NoFocus);
    //view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    Country jeju("Jeju", QPointF(300, 300), 2345, "D:/Code QT/Plague-inc/jeju-island.png", 200, 200);
    qDebug() << jeju.getPosition();
        this->addItem(jeju.getPicture()->getItem());



    Country* country = nullptr;
    for (int i = 0; i < controller->size(); i++) {
        for (int j = 0; j < controller->getIndex(i)->size(); j++) {
            country = controller->getIndex(i)->getIndex(j);
            this->addItem(country->getPicture()->getItem());
//            std::vector<Airport> airports = country->getAirport();
//            for (const Airport& airport: airports) {
//               for (const Plane& plane: airport.getPlane()) {
//                   this->addItem(plane.getPicture()->getItem());
//               }
//            }
        }
    }

//    QPixmap pixmap;
//    //QBitmap bitmap;
//    QGraphicsPixmapItem* pixmapItem = nullptr;
//    QPainterPath path;

//    pixmap.load("D:/Code QT/Plague-inc/plane.png");
//    pixmap = pixmap.scaled(100, 100);
//    pixmapItem = new QGraphicsPixmapItem(pixmap);
//    pixmapItem->setPos(QPointF(100, 100));

//    Picture picture("D:/Code QT/Plague-inc/plane.png", QPointF(0, 0), 100, 100);
//    this->addItem(picture.getItem());

    //Country jeju("Jeju", QPointF(300, 300), 2345, "D:/Code QT/Plague-inc/jeju-island.png", 200, 200);
    //this->addItem(jeju.getPicture()->getItem());

    for (int i = 0; i < controller->size(); i++) {
        for (int j = 0; j < controller->getIndex(i)->size(); j++) {
            country = controller->getIndex(i)->getIndex(j);
            //this->addItem(country->getPicture()->getItem());
            std::vector<Airport*> airports = country->getAirport();
            for (const Airport* airport: airports) {
                this->addItem(airport->getPicture()->getItem());
                //qDebug() << airport.getPlane().size();

            }
        }
    }

    std::vector<Plane*> planes = controller->getPlanes();
    for (int i = 0; i < static_cast<int>(planes.size()); i++) {
        this->addItem(planes[i]->getPicture()->getItem());
    }


    //exit(0);

    //this->addItem(pixmapItem);
//    //scene->addLine(10, 10, 20, 20);
//    //scene->add

    //this->setFocusItem(pixmapItem);
    //qDebug() << scene->items().size();
}

QGraphicsView* View::getView() {
    return view;
}

//void QGraphicsView::update(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
//    qDebug() << "Aaa";
//    painter->save();
//    Q_UNUSED(option);
//    Q_UNUSED(widget);


//    std::vector<Point> array;

//    for (int i = 0; i < controller->size(); i++) {
//        for (int j = 0; j < controller->getIndex(i)->size(); j++) {
//            array = controller->getIndex(i)->getIndex(j)->getInfectedZone();
//            qDebug() << array.size();
//            for (const Point& point: array) {
//                painter->setBrush(QColor(200, 0, 0, 50));
//                painter->drawEllipse(point.position, point.radius, point.radius);
//                painter->setBrush(QColor(200, 0, 0));
//                painter->drawEllipse(point.position, point.radius, point.radius);
//                this->addEllipse(point.position.x(), point.position.y(), point.radius, point.radius);
//                //this->addEllipse()
//            }
//        }
//    }


//    painter->restore();
//}

void View::update(Rebuild& updates) {
    for (Circle* circle: updates.addCircle) {
        circle->item = this->addEllipse(circle->position.x() - circle->transparent / 2,
                                        circle->position.y() - circle->transparent / 2,
                                        circle->transparent, circle->transparent,
                                        QColor(200, 0, 0, 50), QBrush(QColor(200, 0, 0, 50)));
        circle->item = this->addEllipse(circle->position.x() - circle->radius / 2,
                                        circle->position.y() - circle->radius / 2,
                                        circle->radius, circle->radius, QColor(200, 0, 0),
                                        QBrush(QColor(200, 0, 0)));
    }
    for (Plane* plane: updates.addPlane) {
        this->addItem(plane->getPicture()->getItem());
    }
}

void View::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//exit(0);
    if (event->button() == Qt::LeftButton)
            {
//                QPointF mousePos = event->pos();
                //qDebug() << "Левая кнопка мыши нажата.";
                //QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
                //qDebug() << "Позиция мыши:" << event->scenePos() << " " << (ptr == nullptr) << " " << ptr->mapFromScene(event->scenePos());
//                //exit(0);
                //update();
            }
            else if (event->button() == Qt::RightButton)
            {
//                qDebug() << "Правая кнопка мыши нажата.";
//                qDebug() << "Позиция мыши:" << event->scenePos() << " " << event->pos();
            }

            //QGraphicsScene::mousePressEvent(event);



}
