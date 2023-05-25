#ifndef INFOBAR_H
#define INFOBAR_H

#pragma once

#include <QString>
#include <QGraphicsItem>
#include "picture.h"
#include "myrectangle.h"
#include "mytext.h"

class InfoBar {
public:
    InfoBar(MyText* name, MyText* infectedTitle, MyText* deadTitle, MyText* infectedNumber, MyText* deadNumber, Picture* back, Picture* infected, Picture* dead, MyRectangle* backBar, MyRectangle* progressBar, MyRectangle* progressBarInfected);
    ~InfoBar();
    //InfoBar(const InfoBar&);
    //InfoBar operator[](const InfoBar&);

    MyText* getName();
    MyText* getInfectedTitle();
    MyText* getDeadTitle();
    MyText* getInfectedNumber();
    MyText* getDeadNumber();
    Picture* getBack();
    Picture* getInfected();
    Picture* getDead();
    MyRectangle* getBackBar();
    MyRectangle* getProgressBar();
    MyRectangle* getProgressBarInfected();

    void setName(MyText*);
    void setInfectedTitle(MyText*);
    void setDeadTitle(MyText*);
    void setInfectedNumber(MyText*);
    void setDeadNumber(MyText*);
    void setBack(Picture*);
    void setInfected(Picture*);
    void setDead(Picture*);
    void setBackBar(MyRectangle*);
    void setProgressBar(MyRectangle*);
    void setProgressBarInfected(MyRectangle*);

private:
    MyText* name = nullptr;
    MyText* infectedTitle = nullptr;
    MyText* deadTitle = nullptr;
    MyText* infectedNumber = nullptr;
    MyText* deadNumber = nullptr;
    Picture* back = nullptr;
    Picture* infected = nullptr;
    Picture* dead = nullptr;
    MyRectangle* backBar = nullptr;
    MyRectangle* progressBar = nullptr;
    MyRectangle* progressBarInfected = nullptr;
};

#endif // INFOBAR_H
