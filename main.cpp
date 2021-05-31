#include <iostream>
#include "Graphique.h"

int main() {
    Graphique graphe("../fichier-texte-Kruskal.txt");
    graphe.kruskal();
    graphe.showGraph();
}