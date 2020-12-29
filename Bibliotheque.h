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
    Chaine<Adherent*> adherents;
    Chaine<Emprunt> emprunts;   // ne sert à rien...
    Chaine<Echange> echanges;   // ne sert à rien...
    Chaine<Achat> achats;   // ne sert à rien...
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
    int addAdherent();
    int addAdherent(string nom, string prenom, string adresse);
    void affiche();
    void affiche_peu();
    void saisie_bibliotheque();
    void emprunte(string isbn, Bibliotheque* other);
    void rendEmprunts();
    Bibliotheque* getPointer() {return this;};
    Chaine<Livre>* getPtrLivres() {return &livres;};
    Chaine<Adherent*>* Adherents() {return &adherents;};
    Adherent* adherent(int identifiant);
    int getIdentifiant() {return code;};
    string generateSave(int indentation = 0, string ind_type ="  ", string separator = "\n");
};



#endif //PROJET_BIBLIOTHEQUE_H
