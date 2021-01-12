//
// Created on 18/12/2020.
//

#include "Achat.h"

int Achat::nombreAchat = 0;

Achat::Achat() {
    Achat::identifiant = nombreAchat++;
    Achat::date = Date();
    Achat::livre = Livre();
    Achat::date.saisie();
    Achat::livre.saisieLivre();
}

Achat::Achat(Livre livre, Date date) {
    Achat::identifiant = nombreAchat++;
    Achat::date = date;
    Achat::livre = livre;
}

void Achat::affiche() {
    cout << "Achat n°" << identifiant << endl;
    livre.affiche();
    date.affiche();
}

void Achat::affiche_peu() {
    livre.affiche_peu();
    cout << " acheté le ";
    date.affiche_peu();
}

int Achat::getIdentifiant() {
    return identifiant;
}
