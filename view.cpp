#include "view.h"

View::View(Controller* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

    view->setStyleSheet("background-image: url(D:/Code QT/Plague-inc/main-background.png);"
                          "background-repeat: no-repeat;"
                          "background-position: center;"
                          "background-size: cover;");
    view->setContentsMargins(QMargins(0, 0, 0, 0));
    this->setSceneRect(0, 0, parent->width() - 2, parent->height() - 2);


    Country* country = nullptr;
    for (int i = 0; i < controller->size(); i++) {
        for (int j = 0; j < controller->getIndex(i)->size(); j++) {
            country = controller->getIndex(i)->getIndex(j);
            this->addItem(country->getPicture()->getItem());
        }
    }

    for (int i = 0; i < controller->size(); i++) {
        for (int j = 0; j < controller->getIndex(i)->size(); j++) {
            country = controller->getIndex(i)->getIndex(j);
            std::vector<Airport*> airports = country->getAirport();
            for (const Airport* airport: airports) {
                this->addItem(airport->getPicture()->getItem());
            }
        }
    }

//    std::vector<Plane*> planes = controller->getPlanes();
//    for (int i = 0; i < static_cast<int>(planes.size()); i++) {
//        this->addItem(planes[i]->getPicture()->getItem());
//    }

    InfoBar* infobar = controller->getInfobar();

    infobar->getName()->item = this->addText(infobar->getName()->text, QFont("Arial", 15, QFont::ExtraBold));
    infobar->getName()->addPosition();
    infobar->getName()->item->setDefaultTextColor(Qt::white);

    infobar->getInfectedNumber()->item = this->addText(infobar->getInfectedNumber()->text, QFont("Arial", 11, QFont::ExtraBold));
    infobar->getInfectedNumber()->addPosition();
    infobar->getInfectedNumber()->item->setDefaultTextColor(Qt::white);

    infobar->getDeadNumber()->item = this->addText(infobar->getDeadNumber()->text, QFont("Arial", 11, QFont::ExtraBold));
    infobar->getDeadNumber()->addPosition();
    infobar->getDeadNumber()->item->setDefaultTextColor(Qt::white);

//    infobar->getInfectedTitle()->item = this->addText(infobar->getInfectedTitle()->text);
//    infobar->getInfectedTitle()->item->setDefaultTextColor(Qt::white);
//    infobar->getInfectedTitle()->setPosition(infobar->getInfectedTitle()->position);

//    infobar->getDeadTitle()->item = this->addText(infobar->getDeadTitle()->text);
//    infobar->getDeadTitle()->item->setDefaultTextColor(Qt::white);
//    infobar->getDeadTitle()->setPosition(infobar->getDeadTitle()->position);

//    // ----

//    this->addItem(infobar->getInfected()->getItem());
//    this->addItem(infobar->getDead()->getItem());

//    infobar->getProgressBar()->item = this->addRect(infobar->getProgressBar()->rect, infobar->getProgressBar()->pen, infobar->getProgressBar()->brush);
//    infobar->getProgressBarInfected()->item = this->addRect(infobar->getProgressBarInfected()->rect, infobar->getProgressBarInfected()->pen, infobar->getProgressBarInfected()->brush);


    // --------------------------------------

    Progress* progress = controller->getProgress();
    //progress->getBack()->item = this->addRect(progress->getBack()->rect, progress->getBack()->pen, progress->getBack()->brush);
    this->addItem(progress->getButton()->getItem());
    progress->getProgress()->item = this->addText(progress->getProgress()->text, QFont("Arial", 15, QFont::ExtraBold));
    progress->getProgress()->addPosition();
    progress->getProgress()->item->setDefaultTextColor(Qt::white);

    // --------------------------------------


    MyText* cureProgress = controller->getCureProgress();
    cureProgress->item = this->addText(cureProgress->text, QFont("Arial", 15, QFont::ExtraBold));
    cureProgress->addPosition();
    cureProgress->item->setDefaultTextColor(Qt::white);
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
        circle->item->clearFocus();
        circle->item->setAcceptedMouseButtons(Qt::NoButton);
        circle->item = this->addEllipse(circle->position.x() - circle->radius / 2,
                                        circle->position.y() - circle->radius / 2,
                                        circle->radius, circle->radius, QColor(160, 0, 0),
                                        QBrush(QColor(160, 0, 0)));
        circle->item->clearFocus();
        circle->item->setAcceptedMouseButtons(Qt::NoButton);
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

                controller->updateSelection(ptr);
                view->update();
                //qDebug() << "Позиция мыши:" << event->scenePos() << " " << !(ptr == nullptr);
            }
            else if (event->button() == Qt::RightButton)
            {
        QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
//                qDebug() << "Правая кнопка мыши нажата.";
                qDebug() << "Позиция мыши:" << event->scenePos() << " " << !(ptr == nullptr);
            }

            //QGraphicsScene::mousePressEvent(event);

}
