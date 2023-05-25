#ifndef MENUBAR_H
#define MENUBAR_H

#pragma once

#include "mytext.h"
#include "myrectangle.h"

class MenuBar {
public:
    MenuBar(MyText*, MyRectangle*);

    void setText(MyText*);
    void setCurrentLevel(int);

    MyText* getName();
    int getCurrentLevel();
    MyRectangle* getProgressBar();
    MyRectangle* getProgressBarInfected();
    MyRectangle* getProgressBarShow();

private:
    MyText* name = nullptr;
    int currentLevel;
    MyRectangle* progressBar = nullptr;
    MyRectangle* progressBarInfected = nullptr;
    MyRectangle* progressBarShow = nullptr;
};

#endif // MENUBAR_H
