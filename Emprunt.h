//
// Created on 16/12/2020.
//

#ifndef PROJET_EMPRUNT_H
#define PROJET_EMPRUNT_H
//#include "Bibliotheque.h"
class Adherent;
class Bibliotheque;
class Livre;

class Emprunt {
private:
    int identifiant;
    Bibliotheque *preteur;
    Adherent *emprunteur;
    Livre *livre;
    static int nombre_emprunt; //sert à créer un numéro d'identifiant pour chaque emprunt, à ne pas décrémenter !
public:
    Emprunt();
    Emprunt(Bibliotheque *preteur, Adherent *emprunteur, Livre *livre);
    int getIdentifiant() {return identifiant;};
    void affiche();
    void affiche_peu();
};


#endif //PROJET_EMPRUNT_H
