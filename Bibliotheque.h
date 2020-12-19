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
#include "Achat.h"
#include "MiseAuPilon.h"
#include "Perte.h"
#include <iostream>
using namespace std;

/* DESCRIPTION :
 *  À faire
 * MÉTHODES :
 *  Bibliotheque : initialise une bibliotheque vide
 *  ajouteLivre : ajoute un 'Livre' ou les livres d'une 'Chaine<Livre>' dans les 'livres' de la bibliotheque
 *
 */

class Bibliotheque {
private:
    static int nombre_bibliotheque;
    Chaine<Livre> livres;
    Chaine<Adherent> adherents;
    Chaine<Emprunt> emprunts;
    Chaine<Echange> echanges;
    Chaine<Achat> achats;
    Chaine<Perte> pertes;
    Chaine<MiseAuPilon> miseAuPilon;
    int code;
    string nom;
    string adresse;
public:
    Bibliotheque();
    Bibliotheque(string nom, string adresse);
    Chaine<Livre> getLivres();
    void ajouteLivre(Livre &livre);
    void ajouteLivre(Chaine<Livre> livres);
    void affiche();
    void affiche_peu();
    void saisie_bibliotheque();
};



#endif //PROJET_BIBLIOTHEQUE_H
