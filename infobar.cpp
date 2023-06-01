#include "infobar.h"

InfoBar::InfoBar(MyText* name_, MyText* infectedNumber_, MyText* deadNumber_, Picture* world_, MyRectangle* infectedBar_, MyRectangle* deadBar_) {
    name = name_;
    infectedNumber = infectedNumber_;
    deadNumber = deadNumber_;
    world = world_;
    infectedBar = infectedBar_;
    deadBar = deadBar_;
}

InfoBar::~InfoBar() {
    delete name;
    delete infectedNumber;
    delete deadNumber;
    delete world;
    delete infectedBar;
    delete deadBar;
}

MyText* InfoBar::getName() {
    return name;
}

MyText* InfoBar::getInfectedNumber() {
    return infectedNumber;
}

MyText* InfoBar::getDeadNumber() {
    return deadNumber;
}

Picture* InfoBar::getWorld() {
    return world;
}

MyRectangle* InfoBar::getInfectedBar() {
    return infectedBar;
}

MyRectangle* InfoBar::getdeadBar() {
    return deadBar;
}

void InfoBar::setName(const QString& name_) {
    name->setText(name_);
}

void InfoBar::setInfectedNumber(int number) {
    infectedNumber->setText(QString::number(number));
}

void InfoBar::setDeadNumber(int number) {
    deadNumber->setText(QString::number(number));
}
