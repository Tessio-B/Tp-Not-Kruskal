#ifndef KRUSKA_SOMMET_H
#define KRUSKA_SOMMET_H

#include <iostream>

class Sommets {

private:
    int numS;

public :
    Sommets(int num);
    ~Sommets();
    int getID() const;
    void setID(int id);
    void affichersommet() const;

};

#endif //KRUSKA_SOMMET_H
