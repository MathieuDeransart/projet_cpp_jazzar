//
// Created by Deransart on 16/12/2020.
//

#include "Echange.h"
#include "Livre.h"
#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int Echange::nombre_echange = 0;

Echange::Echange(Bibliotheque *preteur, Livre *livre, Bibliotheque *receveur) {
    Echange::preteur = preteur;
    Echange::livre = livre;
    Echange::receveur = receveur;
    Echange::identifiant = nombre_echange++;
}

Echange::~Echange() {
}

Echange::Echange() {
    Echange::preteur = NULL;
    Echange::livre = NULL;
    Echange::receveur = NULL;
    Echange::identifiant = nombre_echange++;
}

int Echange::getIdentifiant() {
    return identifiant;
}

void Echange::affiche() {
    cout << "Échange n°" << identifiant << endl;
    cout << "Livre échangé :" << endl;
    livre->affiche();
    cout << "Prêteur :" << endl;
    preteur->affiche();
    cout << "Receveur :" << endl;
    receveur->affiche();
}

void Echange::affiche_peu() {
    livre->affiche_peu();
    cout << " de "; preteur->affiche_peu();
    cout << " à "; receveur->affiche_peu();
}
