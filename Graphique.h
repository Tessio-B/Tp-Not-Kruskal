//
// Created by bruzz on 05/04/2021.
//

#ifndef KRUSKA_GRAPHE_H
#define KRUSKA_GRAPHE_H

#include <iostream>
#include <vector>
#include "Sommet.h"
#include "Arete.h"

class Graphique {

private :
    std::vector<Sommets *> m_sommets;
    std::vector<Arete *> m_aretes;

public :
    Graphique(std::string fichiergraphe);
    Graphique();
    ~Graphique();
    void tri();
    void kruskal();
    void showGraph();
};


#endif //KRUSKA_GRAPHE_H
