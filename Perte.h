//
// Created by Deransart on 19/12/2020.
//

#ifndef PROJET_PERTE_H
#define PROJET_PERTE_H
#include "Livre.h"
#include "Adherent.h"

class Perte {
private:
    int identifiant;
    Livre livre;
    Adherent *adherent;
    static int nombrePertes;
public:
    Perte();
    Perte(Livre livre, Adherent *adherent);
    void affiche();
    void affiche_peu();
    int getIdentifiant();
};


#endif //PROJET_PERTE_H
