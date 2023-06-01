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

//InfoBar::InfoBar(const InfoBar& infoBar) {
//    name = infoBar.name;
//    back = new Picture(infoBar.back);
//    infected = new Picture(infoBar.infected);
//    dead = new Picture(infoBar.dead);
//    backBar = new MyRectangle(*infoBar.backBar);
//    progressBar = new MyRectangle(*infoBar.progressBar);
//    progressBarInfected = new MyRectangle(*infoBar.progressBarInfected);
//}

//InfoBar InfoBar::operator[](const InfoBar& infoBar) {
//    if (&infoBar == this) {
//        return *this;
//    }
//    name = infoBar.name;
//    back = new Picture(infoBar.back);
//    infected = new Picture(infoBar.infected);
//    dead = new Picture(infoBar.dead);
//    backBar = new MyRectangle(*infoBar.backBar);
//    progressBar = new MyRectangle(*infoBar.progressBar);
//    progressBarInfected = new MyRectangle(*infoBar.progressBarInfected);
//    return *this;
//}

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

//void InfoBar::setWorld(Picture*);
//void InfoBar::setInfectedBar(MyRectangle*);
//void InfoBar::setdeadBar(MyRectangle*);
