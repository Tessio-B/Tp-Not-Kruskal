#include "Sommet.h"

void Sommets::affichersommet() const {
    std::cout<<getID();
}
Sommets::Sommets(int num) : numS{num} {}

void Sommets::setID(int id) {
    numS = id;
}

int Sommets::getID() const { return numS; }

