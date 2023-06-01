#ifndef MENUBAR_H
#define MENUBAR_H

#pragma once

#include "mytext.h"
#include "myrectangle.h"

class MenuBar {
public:
    MenuBar(MyText*, int, int, const QPointF&, const QPointF&, QColor, QBrush);

    void setText(MyText*);
    void setCurrentLevel(int);
    void setPrediction(int);

    MyText* getName();
    int getCurrentLevel();
    MyRectangle* getProgressBar();
    MyRectangle* getProgressBarShow();

private:
    MyText* name = nullptr;
    int currentLevel;
    int maxLevel;
    QPointF begin;
    QPointF end;
    MyRectangle* progressBar = nullptr;
    MyRectangle* progressBarShow = nullptr;
    QColor progressColor;
    QBrush progressBrush;
};

#endif // MENUBAR_H
