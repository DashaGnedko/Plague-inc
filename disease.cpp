#include "disease.h"

Disease::Disease(const QString& name_, const QString& desctiption_, double infectivityChange_,
                 double severityChange_, double lethalityChange_, int cost_, Picture* picture_) {
    name = name_;
    desctiption = desctiption_;
    infectivityChange = infectivityChange_;
    severityChange = severityChange_;
    lethalityChange = lethalityChange_;
    cost = cost_;
    picture = picture_;
}

Disease::~Disease() {
    delete picture;
}

Disease::Disease(const Disease& disease) {
    name = disease.name;
    desctiption = disease.desctiption;
    infectivityChange = disease.infectivityChange;
    severityChange = disease.severityChange;
    lethalityChange = disease.lethalityChange;
    cost = disease.cost;
    picture = new Picture(disease.picture);
}

Disease& Disease::operator=(const Disease& disease) {
    if (&disease == this) {
        return *this;
    }
    name = disease.name;
    desctiption = disease.desctiption;
    infectivityChange = disease.infectivityChange;
    severityChange = disease.severityChange;
    lethalityChange = disease.lethalityChange;
    cost = disease.cost;
    picture = new Picture(disease.picture);
    return *this;
}
