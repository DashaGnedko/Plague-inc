#include "viewmenu.h"

ViewMenu::ViewMenu(ControllerMenu* controller_, QWidget *parent) : QGraphicsScene(parent) {

    view = new QGraphicsView(this);
    controller = controller_;

    QPalette palette;
    palette.setColor(QPalette::Base, QColor(150, 0, 0));
    view->setAutoFillBackground(true);
    view->setPalette(palette);

    this->setSceneRect(0, 0, parent->width() - 2, parent->height() - 2);

    Picture* background = new Picture("D:/Code QT/Plague-inc/dna-background-2.png", QPointF(70, 110), 1200, 700);
    this->addItem(background->getItem());

    Picture* backgroundBacteria = new Picture("D:/Code QT/Plague-inc/bacteria.png", QPointF(1324, 112), 500, 400);
    this->addItem(backgroundBacteria->getItem());

    Picture* backgroundHuman = new Picture("D:/Code QT/Plague-inc/human.png", QPointF(1324, 562), 500, 400);
    this->addItem(backgroundHuman->getItem());

    MyRectangle* toolBar = new MyRectangle(0, parent->height() - 60, parent->width() - 1, parent->height() - 1, QColor(34, 0, 1), QBrush(QColor(34, 0, 1)));
    toolBar->item = this->addRect(toolBar->rect, toolBar->pen, toolBar->brush);

    controller->getInfectivity()->getName()->item = this->addText(controller->getInfectivity()->getName()->text, QFont());
    controller->getInfectivity()->getName()->addPosition();
    controller->getInfectivity()->getName()->item->setDefaultTextColor(Qt::white);
    controller->getInfectivity()->getProgressBar()->item = this->addRect(controller->getInfectivity()->getProgressBar()->rect, controller->getInfectivity()->getProgressBar()->pen, controller->getInfectivity()->getProgressBar()->brush);

    controller->getSeverity()->getName()->item = this->addText(controller->getSeverity()->getName()->text, QFont());
    controller->getSeverity()->getName()->addPosition();
    controller->getSeverity()->getName()->item->setDefaultTextColor(Qt::white);
    controller->getSeverity()->getProgressBar()->item = this->addRect(controller->getSeverity()->getProgressBar()->rect, controller->getSeverity()->getProgressBar()->pen, controller->getSeverity()->getProgressBar()->brush);

    controller->getLethality()->getName()->item = this->addText(controller->getLethality()->getName()->text, QFont());
    controller->getLethality()->getName()->addPosition();
    controller->getLethality()->getName()->item->setDefaultTextColor(Qt::white);
    controller->getLethality()->getProgressBar()->item = this->addRect(controller->getLethality()->getProgressBar()->rect, controller->getLethality()->getProgressBar()->pen, controller->getLethality()->getProgressBar()->brush);
}

QGraphicsView* ViewMenu::getView() {
    return view;
}

ViewMenu::~ViewMenu() {
    delete view;
}

void ViewMenu::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//exit(0);
    if (event->button() == Qt::LeftButton)
            {
//                QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
//                if (ptr == controller->getProgress()->getButton()->getItem()) {
//                    emit openMenu();
//                    return;
//                }
//                QPointF mousePos = event->pos();
                //qDebug() << "Левая кнопка мыши нажата.";
                //QGraphicsItem* ptr = this->itemAt(event->scenePos(), QTransform());
                qDebug() << "Позиция мыши:" << event->scenePos();
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
