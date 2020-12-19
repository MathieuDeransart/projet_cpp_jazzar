//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_ECHANGE_H
#define PROJET_ECHANGE_H
//#include "Bibliotheque.h"
class Bibliotheque;
class Livre;

class Echange {
private:
    static int nombre_echange;
    int identifiant;
    Bibliotheque *preteur;
    Livre *livre;
    Bibliotheque *receveur;
public:
    Echange();
    Echange(Bibliotheque *preteur, Livre *livre, Bibliotheque *receveur);
    virtual ~Echange();
    int getIdentifiant();
    void affiche();
    void affiche_peu();
};


#endif //PROJET_ECHANGE_H
