#include "controllermenu.h"

ControllerMenu::ControllerMenu() {
    infectivity = new MenuBar(new MyText("INFECTIVITY", QPointF(335, 1035)), new MyRectangle(450, 1035, 670, 1065, QColor(182, 18, 40), QBrush(QColor(182, 18, 40, 40))));
    severity = new MenuBar(new MyText("SEVERITY", QPointF(750, 1035)), new MyRectangle(850, 1035, 1070, 1065, QColor(242, 253, 77), QBrush(QColor(242, 253, 77, 40))));
    lethality = new MenuBar(new MyText("LETHALITY", QPointF(1150, 1035)), new MyRectangle(1250, 1035, 1470, 1065, QColor(124, 34, 91), QBrush(QColor(124, 34, 91, 40))));
}

ControllerMenu::~ControllerMenu() {
    delete infectivity;
    delete severity;
}

MenuBar* ControllerMenu::getInfectivity() {
    return infectivity;
}

MenuBar* ControllerMenu::getSeverity() {
    return severity;
}

MenuBar* ControllerMenu::getLethality() {
    return lethality;
}
