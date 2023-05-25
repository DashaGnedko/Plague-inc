#include "menubar.h"

MenuBar::MenuBar(MyText* name_, MyRectangle* progressBar_) {
    name = name_;
    progressBar = progressBar_;
}

void MenuBar::setText(MyText* name_) {
    name = name_;
}

void MenuBar::setCurrentLevel(int level_) {
    currentLevel = level_;
}

MyText* MenuBar::getName() {
    return name;
}

int MenuBar::getCurrentLevel() {
    return currentLevel;
}

MyRectangle* MenuBar::getProgressBar() {
    return progressBar;
}

MyRectangle* MenuBar::getProgressBarInfected() {
    return progressBar;
}

MyRectangle* MenuBar::getProgressBarShow() {
    return progressBarShow;
}
