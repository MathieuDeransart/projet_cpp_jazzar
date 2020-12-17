//
// Created by Deransart on 16/12/2020.
//

#include "Adherent.h"

int Adherent::nombre_adherent = 0;

Adherent::Adherent() {
    Adherent::nom = "Non renseigné";
    Adherent::prenom = "Non renseigné";
    Adherent::adresse = "Non renseigné";
    Adherent::numero_adherent = numero_adherent;
    Adherent::bibliotheque = NULL;
    Adherent::livre_empruntes = NULL;
    nombre_adherent ++;
}

Adherent::Adherent(string nom, string prenom, string adresse, int numero_adherent, Bibliotheque *bibliotheque,
                   Livre *livre_empruntes) {
    Adherent::nom = nom;
    Adherent::prenom = prenom;
    Adherent::adresse = adresse;
    Adherent::numero_adherent = numero_adherent;
    Adherent::bibliotheque = bibliotheque;
    Adherent::livre_empruntes = livre_empruntes;
    nombre_adherent ++;
}

int Adherent::getIdentifiant() {
    return numero_adherent;
}

