#ifndef PROGRESS_H
#define PROGRESS_H

#pragma once

#include "mytext.h"
#include "myrectangle.h"
#include "picture.h"

class Progress {
public:
    Progress(MyText*, MyText*, Picture*, Picture*, MyRectangle*, MyRectangle*, MyRectangle*);

    MyText* getText();
    MyText* getProgress();
    Picture* getPicture();
    Picture* getButton();
    MyRectangle* getBack();
    MyRectangle* getProgressBar();
    MyRectangle* getProgressBarInfected();

private:
    MyText* text = nullptr;
    MyText* progress = nullptr;
    Picture* picture = nullptr;
    Picture* button = nullptr;
    MyRectangle* back = nullptr;
    MyRectangle* progressBar = nullptr;
    MyRectangle* progressBarInfected = nullptr;
};

#endif // PROGRESS_H
