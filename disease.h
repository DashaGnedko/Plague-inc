#ifndef DISEASE_H
#define DISEASE_H

#pragma once

#include <QString>
#include "picture.h"

class Disease {
public:
    Disease(const QString&, const QString&, double, double, double, int, Picture*);
    ~Disease();
    Disease(const Disease&);
    Disease& operator=(const Disease&);

private:
    QString name;
    QString desctiption;
    double infectivityChange;
    double severityChange;
    double lethalityChange;
    int cost;
    Picture* picture = nullptr;
};

#endif // DISEASE_H
