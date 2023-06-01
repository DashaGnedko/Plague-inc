#include "view.h"

View::View(Controller* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

    view->setStyleSheet("background-image: url(:/icons/main-background.png);"
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

    Progress* progress = controller->getProgress();
    this->addItem(progress->getButton()->getItem());
    progress->getProgress()->item = this->addText(progress->getProgress()->text, QFont("Arial", 15, QFont::ExtraBold));
    progress->getProgress()->addPosition();
    progress->getProgress()->item->setDefaultTextColor(Qt::white);

    MyText* cureProgress = controller->getCureProgress();
    cureProgress->item = this->addText(cureProgress->text, QFont("Arial", 15, QFont::ExtraBold));
    cureProgress->addPosition();
    cureProgress->item->setDefaultTextColor(Qt::white);

    MyRectangle* exitButton = controller->getExitButton();
    exitButton->item = this->addRect(exitButton->rect, exitButton->pen, exitButton->brush);
}

QGraphicsView* View::getView() {
    return view;
}

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
    for (Plane* plane: updates.addPlane) {
        this->addItem(plane->getPicture()->getItem());
    }
}

void View::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
        if (ptr == controller->getProgress()->getButton()->getItem()) {
            emit openMenu();
            return;
        }
        if (ptr == controller->getExitButton()->item) {
            exit(0);
        }
        controller->updateSelection(ptr);
        view->update();
    }
}
