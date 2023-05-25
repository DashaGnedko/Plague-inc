#include "infobar.h"

InfoBar::InfoBar(MyText* name_, MyText* infectedTitle_, MyText* deadTitle_, MyText* infectedNumber_, MyText* deadNumber_, Picture* back_, Picture* infected_, Picture* dead_, MyRectangle* backBar_, MyRectangle* progressBar_, MyRectangle* progressBarInfected_) {
    name = name_;
    infectedTitle = infectedTitle_;
    deadTitle = deadTitle_;
    infectedNumber = infectedNumber_;
    deadNumber = deadNumber_;
    back = back_;
    infected = infected_;
    dead = dead_;
    backBar = backBar_;
    progressBar = progressBar_;
    progressBarInfected = progressBarInfected_;
}

InfoBar::~InfoBar() {
    delete name;
    delete back;
    delete infected;
    delete dead;
    delete backBar;
    delete progressBar;
    delete progressBarInfected;
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

MyText* InfoBar::getInfectedTitle() {
    return infectedTitle;
}

MyText* InfoBar::getDeadTitle() {
    return deadTitle;
}

MyText* InfoBar::getInfectedNumber() {
    return infectedNumber;
}

MyText* InfoBar::getDeadNumber() {
    return deadNumber;
}

Picture* InfoBar::getBack() {
    return back;
}

Picture* InfoBar::getInfected() {
    return infected;
}

Picture* InfoBar::getDead() {
    return dead;
}

MyRectangle* InfoBar::getBackBar() {
    return backBar;
}

MyRectangle* InfoBar::getProgressBar() {
    return progressBar;
}

MyRectangle* InfoBar::getProgressBarInfected() {
    return progressBarInfected;
}

void InfoBar::setName(MyText* name_) {
    name = name_;
}

void InfoBar::setInfectedTitle(MyText* infectedTitle_) {
    infectedTitle = infectedTitle_;
}

void InfoBar::setDeadTitle(MyText* deadTitle_) {
    deadTitle = deadTitle_;
}

void InfoBar::setInfectedNumber(MyText* infectedNumber_) {
    infectedNumber = infectedNumber_;
}

void InfoBar::setDeadNumber(MyText* deadNumber_) {
    deadNumber = deadNumber_;
}

void InfoBar::setBack(Picture* back_) {
    back = back_;
}

void InfoBar::setInfected(Picture* infected_) {
    infected = infected_;
}

void InfoBar::setDead(Picture* dead_) {
    dead = dead_;
}

void InfoBar::setBackBar(MyRectangle* backBar_) {
    backBar = backBar_;
}

void InfoBar::setProgressBar(MyRectangle* progressBar_) {
    progressBar = progressBar_;
}

void InfoBar::setProgressBarInfected(MyRectangle* progressBarInfected_) {
    progressBarInfected = progressBarInfected_;
}
