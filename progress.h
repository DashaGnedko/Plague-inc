#ifndef PROGRESS_H
#define PROGRESS_H

#pragma once

#include "mytext.h"
#include "myrectangle.h"
#include "picture.h"

class Progress {
public:
    Progress(MyText*, Picture*, MyRectangle*);

    MyText* getProgress();
    Picture* getButton();
    MyRectangle* getBack();

    void setDna(int);

private:
    MyText* progress = nullptr;
    Picture* button = nullptr;
    MyRectangle* back = nullptr;
};

#endif // PROGRESS_H
