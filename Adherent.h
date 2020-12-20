//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_ADHERENT_H
#define PROJET_ADHERENT_H
#include "Chaine.h"
class Bibliotheque;
#include "Livre.h"
#include <string>
using namespace std;




class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int numero_adherent;  // /!\ sert d'identifiant pour la classe adherent
    Bibliotheque *bibliotheque;
    Chaine<Livre *> livre_empruntes;
    int nombreLivreMax;
    static int nombre_adherent;
public:
    Adherent();
    Adherent(Bibliotheque *bibliotheque);
    Adherent(string nom, string prenom, string adresse, Bibliotheque *bibliotheque);
    int getIdentifiant();
    void affiche();
    void affiche_peu();
    void saisie_adherent();
    void emprunter(int codeLivre);
};


#endif //PROJET_ADHERENT_H
