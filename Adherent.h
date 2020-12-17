//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_ADHERENT_H
#define PROJET_ADHERENT_H
//#include "Bibliotheque.h"
class Bibliotheque;
class Livre;
#include <string>
using namespace std;

class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int numero_adherent;  // /!\ sert d'identifiant pour la classe adherent
    Bibliotheque *bibliotheque;
    Livre *livre_empruntes;
    static int nombre_adherent;
public:
    Adherent();
    Adherent(string nom, string prenom, string adresse, int numero_adherent, Bibliotheque *bibliotheque, Livre *livre_empruntes);
    int getIdentifiant();
};


#endif //PROJET_ADHERENT_H
