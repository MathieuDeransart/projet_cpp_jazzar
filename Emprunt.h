//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_EMPRUNT_H
#define PROJET_EMPRUNT_H
//#include "Bibliotheque.h"
class Adherent;
class Bibliotheque;

class Emprunt {
private:
    int identifiant;
    Bibliotheque *preteur;
    Adherent *emprunteur;
    static int nombre_emprunt; //sert à créer un numéro d'identifiant pour chaque emprunt, à ne pas décrémenter !
public:
    Emprunt();
    Emprunt(Bibliotheque *preteur, Adherent *emprunteur);
    int getIdentifiant();
};


#endif //PROJET_EMPRUNT_H
