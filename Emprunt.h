//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_EMPRUNT_H
#define PROJET_EMPRUNT_H
#include "Bibliotheque.h"


class Emprunt {
private:
    Bibliotheque *preteur;
    Adherent *emprunteur;
public:
    Emprunt(Bibliotheque *preteur, Adherent *emprunteur);
};


#endif //PROJET_EMPRUNT_H
