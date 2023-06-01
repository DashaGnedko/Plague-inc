#include "diseasebar.h"

#include <QDebug>

DiseaseBar::DiseaseBar(MyText* name_, MyText* description_, MyText* cost_, Picture* picture_, Picture* devolve_, Picture* evolve_) {
    name = name_;
    description = description_;
    cost = cost_;
    picture = new Picture(picture_);
    picture->setPixmapItemPosition(position);
    button = new Picture(evolve_);
    devolve = devolve_;
    evolve = evolve_;
}

DiseaseBar::~DiseaseBar() {
    delete picture;
    delete button;
    delete devolve;
    delete evolve;
}

MyText* DiseaseBar::getName() {
    return name;
}

MyText* DiseaseBar::getDescription() {
    return description;
}

MyText* DiseaseBar::getCost() {
    return cost;
}

Picture* DiseaseBar::getPicture() {
    return picture;
}

Picture* DiseaseBar::getButton() {
    return button;
}

void DiseaseBar::setDisease(const QString& name_, const QString& description_, int cost_, Picture* picture_, bool isBought) {
    name->setText(name_);
    description->setText("\\\\ " + description_);
    picture->setPixmap(*picture_->getPixmap());
    cost->setText("\\\\ " + QString::number(cost_) + " DNA Points");
    changeButton(isBought);
//    if (isBought) {
//        button->setPixmap(*devolve->getPixmap());
//    } else {
//        button->setPixmap(*evolve->getPixmap());
//    }
    //picture->setPixmapItemPosition(position);
}

//int times = 0;

void DiseaseBar::changeButton(bool isBought) {
    //qDebug() << isBought;
    //times++;
    if (isBought) {
        //button = devolve;
        button->setPixmap(*devolve->getPixmap());
    } else {
        //button = evolve;
        button->setPixmap(*evolve->getPixmap());
    }
}
