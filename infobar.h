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
    InfoBar(MyText* name, MyText* infectedNumber, MyText* deadNumber, Picture* world, MyRectangle* infectedBar, MyRectangle* deadBar);
    ~InfoBar();
    //InfoBar(const InfoBar&);
    //InfoBar operator[](const InfoBar&);

    MyText* getName();
    MyText* getInfectedNumber();
    MyText* getDeadNumber();
    Picture* getWorld();
    MyRectangle* getInfectedBar();
    MyRectangle* getdeadBar();

    void setName(const QString&);
    void setInfectedNumber(int);
    void setDeadNumber(int);
    //void setWorld(Picture*);
    //void setInfectedBar(MyRectangle*);
    //void setdeadBar(MyRectangle*);

private:
    MyText* name = nullptr;
    MyText* infectedNumber = nullptr;
    MyText* deadNumber = nullptr;
    Picture* world = nullptr;
    MyRectangle* infectedBar = nullptr;
    MyRectangle* deadBar = nullptr;
};

#endif // INFOBAR_H
