//
// Created by Deransart on 19/12/2020.
//

#include "Perte.h"

int Perte::nombrePertes = 0;

Perte::Perte() {
    Perte::identifiant = nombrePertes++;
    Perte::livre = Livre();
    livre.saisieLivre();
    Perte::adherent = NULL;
}

Perte::Perte(Livre livre, Adherent *adherent) {
    Perte::identifiant = nombrePertes++;
    Perte::livre = livre;
    Perte::adherent = adherent;
}

void Perte::affiche() {
    cout << "Perte n°" << identifiant << " :" << endl;
    livre.affiche();
    adherent->affiche();
}

void Perte::affiche_peu() {
    livre.affiche_peu();
    cout << " perdu par ";
    adherent->affiche_peu();
}

int Perte::getIdentifiant() {
    return identifiant;
}
