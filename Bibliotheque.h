//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_BIBLIOTHEQUE_H
#define PROJET_BIBLIOTHEQUE_H
#include "Adherent.h"
#include "Livre.h"
#include "Emprunt.h"
#include "Echange.h"
#include "string"
#include "Chaine.h"
#include <iostream>
using namespace std;

class Bibliotheque {
private:
    Chaine<Livre> livres;
    Chaine<Adherent> adherents;
    Chaine<Emprunt> emprunts;
    Chaine<Echange> echanges;
    Livre *achats;
    Livre *pertes;
    Livre *miseAuPilon;
public:
    Bibliotheque();
    Bibliotheque(Chaine<Livre> livres, Chaine<Adherent> adherents, Chaine<Emprunt> emprunts, Chaine<Echange> echanges, Livre *achats, Livre *pertes, Livre *miseAuPilon);
    Chaine<Livre> getLivres();
};



#endif //PROJET_BIBLIOTHEQUE_H
