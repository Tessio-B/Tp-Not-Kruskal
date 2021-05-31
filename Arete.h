//
// Created by bruzz on 05/04/2021.
//

#ifndef KRUSKA_ARETE_H
#define KRUSKA_ARETE_H

#include <iostream>
#include <vector>
#include "Sommet.h"

class Arete {
private :
    int poids;
    std::pair<Sommets *, Sommets *> extremites;

public:
    Arete(Sommets *s1, Sommets* s2, int poids);
    ~Arete();
    const std::pair<Sommets*,Sommets*> &getExtremites();
    int getPoids() const;
    void showArete() const;
};

#endif //KRUSKA_ARETE_H
