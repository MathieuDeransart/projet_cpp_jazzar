//
// Created by Deransart on 19/12/2020.
//

#include "MiseAuPilon.h"

int MiseAuPilon::nombreMiseAuPilon = 0;

MiseAuPilon::MiseAuPilon() {
    MiseAuPilon::identifiant = nombreMiseAuPilon++;
    MiseAuPilon::date = Date();
    MiseAuPilon::livre = Livre();
    MiseAuPilon::date.saisie();
    MiseAuPilon::livre.saisieLivre();
}

MiseAuPilon::MiseAuPilon(Livre livre, Date date) {
    MiseAuPilon::identifiant = nombreMiseAuPilon++;
    MiseAuPilon::date = date;
    MiseAuPilon::livre = livre;
}

void MiseAuPilon::affiche() {
    cout << "Mise au pilon n°" << identifiant << endl;
    livre.affiche();
    date.affiche();
}

void MiseAuPilon::affiche_peu() {
    livre.affiche_peu();
    cout << " détruit le ";
    date.affiche_peu();
}

int MiseAuPilon::getIdentifiant() {
    return identifiant;
}

