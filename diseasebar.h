#ifndef DISEASEBAR_H
#define DISEASEBAR_H

#include "mytext.h"
#include "picture.h"

class DiseaseBar {
public:
    DiseaseBar(MyText*, MyText*, MyText*, Picture*, Picture*, Picture*);
    ~DiseaseBar();

    MyText* getName();
    MyText* getDescription();
    MyText* getCost();
    Picture* getPicture();
    Picture* getButton();

    void setDisease(const QString&, const QString&, int, Picture*, bool);
    void changeButton(bool);

private:
    const QPointF position = QPointF(70, 863);
    const QPointF buttonPosition = QPointF(200, 863);


    MyText* name = nullptr;
    MyText* description = nullptr;
    MyText* cost = nullptr;
    Picture* picture = nullptr;
    Picture* button = nullptr;
    Picture* devolve = nullptr;
    Picture* evolve = nullptr;
};

#endif // DISEASEBAR_H
