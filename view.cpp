#include "view.h"

View::View(Controller* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

//    QPixmap waterBackground("D:/Code QT/Plague-inc/water-background.png");
//    waterBackground = waterBackground.scaled(parent->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, waterBackground);
//    view->setPalette(palette);

    view->setStyleSheet("background-image: url(D:/Code QT/Plague-inc/water-background-copy.png);"
                          "background-repeat: no-repeat;"
                          "background-position: center;"
                          "background-size: cover;");


    //view->setStyleSheet("background-image:url(D:/Code QT/Plague-inc/water-background.png)");

//    QPalette palette;
//    palette.setColor(QPalette::Base, QColor(148, 189, 229));
//    view->setAutoFillBackground(true);
//    view->setPalette(palette);

    //qDebug() << parent->width() << " " << parent->height();
    //view->resize(parent->width() - 1, parent->height() - 1);
    this->setSceneRect(0, 0, parent->width() - 2, parent->height() - 2);



    //view->setDragMode(QGraphicsView::NoDrag);
    //view->setFocusPolicy(Qt::NoFocus);
    //view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //Country jeju("Jeju", QPointF(300, 300), 2345, "D:/Code QT/Plague-inc/jeju-island.png", 200, 200);
    //qDebug() << jeju.getPosition();
      //  this->addItem(jeju.getPicture()->getItem());



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

    InfoBar* infobar = controller->getInfobar();
    infobar->getBackBar()->item = this->addRect(infobar->getBackBar()->rect, infobar->getBackBar()->pen, infobar->getBackBar()->brush);

    this->addItem(infobar->getBack()->getItem());
    infobar->getName()->item = this->addText(infobar->getName()->text, QFont("Arial", 14, 3));
    infobar->getName()->item->setDefaultTextColor(Qt::white);
    infobar->getName()->setPosition(infobar->getName()->position);

    infobar->getInfectedTitle()->item = this->addText(infobar->getInfectedTitle()->text);
    infobar->getInfectedTitle()->item->setDefaultTextColor(Qt::white);
    infobar->getInfectedTitle()->setPosition(infobar->getInfectedTitle()->position);

    infobar->getDeadTitle()->item = this->addText(infobar->getDeadTitle()->text);
    infobar->getDeadTitle()->item->setDefaultTextColor(Qt::white);
    infobar->getDeadTitle()->setPosition(infobar->getDeadTitle()->position);

    // ----

    this->addItem(infobar->getInfected()->getItem());
    this->addItem(infobar->getDead()->getItem());

    infobar->getProgressBar()->item = this->addRect(infobar->getProgressBar()->rect, infobar->getProgressBar()->pen, infobar->getProgressBar()->brush);
    infobar->getProgressBarInfected()->item = this->addRect(infobar->getProgressBarInfected()->rect, infobar->getProgressBarInfected()->pen, infobar->getProgressBarInfected()->brush);


    // --------------------------------------

    Progress* progress = controller->getProgress();
    progress->getBack()->item = this->addRect(progress->getBack()->rect, progress->getBack()->pen, progress->getBack()->brush);
    this->addItem(progress->getButton()->getItem());
}

QGraphicsView* View::getView() {
    return view;
}

//void View::resizeEvent(QResizeEvent* event) {

//}

void View::update(Rebuild& updates) {
    for (Circle* circle: updates.addCircle) {
        circle->item = this->addEllipse(circle->position.x() - circle->transparent / 2,
                                        circle->position.y() - circle->transparent / 2,
                                        circle->transparent, circle->transparent,
                                        QColor(160, 0, 0, 50), QBrush(QColor(160, 0, 0, 50)));
        circle->item = this->addEllipse(circle->position.x() - circle->radius / 2,
                                        circle->position.y() - circle->radius / 2,
                                        circle->radius, circle->radius, QColor(160, 0, 0),
                                        QBrush(QColor(160, 0, 0)));
    }
    //qDebug() << updates.addPlane.size();
    for (Plane* plane: updates.addPlane) {
        this->addItem(plane->getPicture()->getItem());
    }
}

void View::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//exit(0);
    if (event->button() == Qt::LeftButton)
            {
                QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
                if (ptr == controller->getProgress()->getButton()->getItem()) {
                    emit openMenu();
                    return;
                }
//                QPointF mousePos = event->pos();
                //qDebug() << "Левая кнопка мыши нажата.";
                //QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
                //qDebug() << "Позиция мыши:" << event->scenePos() << " " << (&ptr == nullptr) << " " << ptr->mapFromScene(event->scenePos());
//                //exit(0);
                //update();
            }
            else if (event->button() == Qt::RightButton)
            {
//                qDebug() << "Правая кнопка мыши нажата.";
                qDebug() << "Позиция мыши:" << event->scenePos() << " " << event->pos();
            }

            //QGraphicsScene::mousePressEvent(event);

}
