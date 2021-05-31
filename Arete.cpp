#include "Arete.h"
const std::pair<Sommets*,Sommets*> &Arete::getExtremites() {
    return extremites;
}
Arete::Arete(Sommets *s1, Sommets* s2, int poids) : poids{poids} {
    extremites.first = s1;
    extremites.second = s2;
}
int Arete::getPoids() const {
    return poids;
}
void Arete::showArete() const {
    std::cout << extremites.first->getID() << " - " << extremites.second->getID() << " de poids " << poids << std::endl;
}

