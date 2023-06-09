#include "viewmenu.h"

ViewMenu::ViewMenu(ControllerMenu* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

    QPalette palette;
    palette.setColor(QPalette::Base, QColor(150, 0, 0));
    view->setAutoFillBackground(true);
    view->setPalette(palette);

    this->setSceneRect(0, 0, parent->width() - 2, parent->height() - 2);

    view->setStyleSheet("background-image: url(:/icons/background.png);"
                          "background-repeat: no-repeat;"
                          "background-position: center;"
                          "background-size: cover;");

    controller->getInfectivity()->getProgressBar()->item = this->addRect(controller->getInfectivity()->getProgressBar()->rect,
                                                                         controller->getInfectivity()->getProgressBar()->pen,
                                                                         controller->getInfectivity()->getProgressBar()->brush);
    controller->getInfectivity()->getProgressBarShow()->item = this->addRect(controller->getInfectivity()->getProgressBarShow()->rect,
                                                                         controller->getInfectivity()->getProgressBarShow()->pen,
                                                                         controller->getInfectivity()->getProgressBarShow()->brush);

    controller->getSeverity()->getProgressBar()->item = this->addRect(controller->getSeverity()->getProgressBar()->rect,
                                                                      controller->getSeverity()->getProgressBar()->pen,
                                                                      controller->getSeverity()->getProgressBar()->brush);
    controller->getSeverity()->getProgressBarShow()->item = this->addRect(controller->getSeverity()->getProgressBarShow()->rect,
                                                                      controller->getSeverity()->getProgressBarShow()->pen,
                                                                      controller->getSeverity()->getProgressBarShow()->brush);

    controller->getLethality()->getProgressBar()->item = this->addRect(controller->getLethality()->getProgressBar()->rect,
                                                                       controller->getLethality()->getProgressBar()->pen,
                                                                       controller->getLethality()->getProgressBar()->brush);
    controller->getLethality()->getProgressBarShow()->item = this->addRect(controller->getLethality()->getProgressBarShow()->rect,
                                                                       controller->getLethality()->getProgressBarShow()->pen,
                                                                       controller->getLethality()->getProgressBarShow()->brush);

    Update* update = controller->getUpdates();
    for (int i = 0; i < update->size(); i++) {
        this->addItem(update->getElement(i)->getPicture()->getItem());
        this->setFocusItem(update->getElement(i)->getPicture()->getItem());
    }

    DiseaseBar* bar = controller->getDiseaseBar();

    QGraphicsTextItem* info = this->addText("INFORMATION", QFont("Arial", 11, QFont::ExtraBold));
    info->setPos(QPointF(207, 855));
    info->setDefaultTextColor(Qt::white);

    QGraphicsTextItem* cost = this->addText("COST", QFont("Arial", 11, QFont::ExtraBold));
    cost->setPos(QPointF(1050, 855));
    cost->setDefaultTextColor(Qt::white);

    controller->getDnaNumber()->item = this->addText(controller->getDnaNumber()->text, QFont("Arial", 16, QFont::ExtraBold));
    controller->getDnaNumber()->addPosition();
    controller->getDnaNumber()->item->setDefaultTextColor(Qt::white);

    bar->getName()->item = this->addText(bar->getName()->text, QFont("Arial", 15, QFont::ExtraBold));
    bar->getName()->addPosition();
    bar->getName()->item->setDefaultTextColor(Qt::white);

    bar->getDescription()->item = this->addText(bar->getDescription()->text, QFont("Arial", 10, QFont::Medium));
    bar->getDescription()->addPosition();
    bar->getDescription()->item->setDefaultTextColor(Qt::white);

    bar->getCost()->item = this->addText(bar->getCost()->text, QFont("Arial", 11, QFont::ExtraBold));
    bar->getCost()->addPosition();
    bar->getCost()->item->setDefaultTextColor(Qt::white);

    this->addItem(bar->getPicture()->getItem());
    this->addItem(bar->getButton()->getItem());
    this->setFocusItem(bar->getButton()->getItem());

    MyRectangle* exitButton = controller->getExitButton();
    exitButton->item = this->addRect(exitButton->rect, exitButton->pen, exitButton->brush);
}

QGraphicsView* ViewMenu::getView() {
    return view;
}

ViewMenu::~ViewMenu() {
    delete view;
}

void ViewMenu::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
        if (ptr == controller->getDiseaseBar()->getButton()->getItem()) {
            controller->updateCurrentDisease();
            return;
        }
        if (ptr == nullptr) {
            return;
        }
        if (ptr == controller->getExitButton()->item) {
            emit closeMenu();
            return;
        }
        Disease* disease = controller->getUpdates()->updateSelection(ptr, controller->getDiseaseBar());
        if (disease != nullptr) {
            controller->setPrediction(disease);
        }
    }
}
