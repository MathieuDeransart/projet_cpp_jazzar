//
// Created on 16/12/2020.
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
 *  achat : ajoute un 'Livre' ou les livres d'une 'Chaine<Livre>' dans les 'livres' de la bibliotheque
 *
 */

class Bibliotheque {
private:
    static int nombre_bibliotheque;
    Chaine<Livre> livres;
    Chaine<Adherent*> adherents;
    int code;
    string nom;
    string adresse;
    Bibliotheque(int code, string nom, string adresse);
    Livre* achat(string sub_save, map<int, Bibliotheque*> id_to_bb);
public:
    Bibliotheque();
    Bibliotheque(string nom, string adresse);
    Chaine<Livre> getLivres();
    void achat(Livre &livre);
    void achat(Chaine<Livre> livres);
    int addAdherent();
    int addAdherent(string nom, string prenom, string adresse);
    void addAdherent(string sub_save, map<int, Bibliotheque*> id_to_bb, map<int, Livre*> id_to_livre);
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
    static Chaine<Bibliotheque*> loadSave(string save);
    void miseAuPilon(Livre *livre);
    void perte(Livre *livre, Adherent* adherent);
};



#endif //PROJET_BIBLIOTHEQUE_H
