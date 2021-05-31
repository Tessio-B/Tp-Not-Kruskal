#include "Graphique.h"
#include <fstream>
#include <algorithm>

Graphique::Graphique(std::string fichiergraphe) {
    std::ifstream ifs{fichiergraphe};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + fichiergraphe);
    }
    int ordre;
    ifs >> ordre;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if (ifs.fail()) {
        throw std::runtime_error("Probleme de lecture de la taille du graphe.");
    }
    for (int i = 0; i <= ordre; ++i) {
        m_sommets.push_back(new Sommets(i));
    }
    int num1, num2, poids;
    for (int i = 0; i < taille; ++i) {
        ifs >> num1 >> num2 >> poids;
        if (ifs.fail()) {
            throw std::runtime_error("Probleme de lecture d'un.e arc/arete.");
        }
        m_aretes.push_back(new Arete(m_sommets[num1], m_sommets[num2], poids));
    }
}
bool triDesAretes (Arete* const a, Arete* const b)
{
    return a->getPoids() < b->getPoids();
}
void Graphique::showGraph() {
    std::cout << "Sommets du graphe: " << std::endl;
    for (auto s: m_sommets) {
        s->affichersommet();
        std::cout <<", ";
    }
    std::cout << std::endl <<  "Arete du graphe :" << std::endl;
    for (auto a: m_aretes) {
        a->showArete();
    }
}



void Graphique::tri() {
    std::sort(m_aretes.begin(), m_aretes.end(), triDesAretes);
    std::cout << "Graphique apres tri : " << std::endl;
    for(auto p : m_aretes) {
        p->showArete();
    }
}
void Graphique::kruskal() {
    tri();
    int tempo;
    Graphique graphetemp;
    for (int i = 0; i < m_aretes.size(); ++i) {
        if (m_aretes[i]->getExtremites().first->getID() != m_aretes[i]->getExtremites().second->getID()){ // on check si ID different
            graphetemp.m_aretes.push_back(m_aretes[i]); // si oui on rajoute l'arete
            tempo = m_aretes[i]->getExtremites().second->getID();
            m_aretes[i]->getExtremites().second->setID(m_aretes[i]->getExtremites().first->getID()); // on change l'id du 2 par celui du 1
            for (int j = 0; j < m_sommets.size(); ++j) {
                if (m_sommets[j]->getID() == tempo){
                    m_sommets[j]->setID(m_aretes[i]->getExtremites().first->getID()); // on regarde si meme id
                }
            }
        }
    }
    std::cout << "\n" << std::endl;
    std::cout << " Graphique apres algorithme de Kruskal : " << std::endl;
    for (auto p : graphetemp.m_aretes)
        p->showArete();
    std::cout <<std::endl;
}

Graphique::Graphique() {}

Graphique::~Graphique() {}




