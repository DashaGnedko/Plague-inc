#include "plague.h"

Plague::Plague(const QString& name_) {
    name = name_;
    infectivity = 0;
    severity = 0;
    lethality = 0;
    dna = 0;
    cure = 0;
}
