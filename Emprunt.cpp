//
// Created by Deransart on 16/12/2020.
//

#include "Emprunt.h"
#include <iostream>
#include "Bibliotheque.h"
#include "Livre.h"
#include "Adherent.h"
using namespace std;

int Emprunt::nombre_emprunt = 0;

Emprunt::Emprunt() {
    Emprunt::preteur = NULL;
    Emprunt::emprunteur = NULL;
    Emprunt::livre = NULL;
    Emprunt::identifiant = nombre_emprunt++;
}

Emprunt::Emprunt(Bibliotheque *preteur, Adherent *emprunteur, Livre *livre) {
    Emprunt::preteur = preteur;
    Emprunt::emprunteur = emprunteur;
    Emprunt::livre = livre;
    Emprunt::identifiant = nombre_emprunt++;
}

void Emprunt::affiche() {
    cout << "Emprunt n°" << identifiant;
    cout << "Bibliotheque : " << endl; preteur->affiche();
    cout << "Adherent : " << endl; emprunteur->affiche();
    cout << "Livre : " << endl; livre->affiche();
}

void Emprunt::affiche_peu() {
    emprunteur->affiche_peu(); cout << " emprunte "; livre->affiche_peu(); cout << " à "; preteur->affiche_peu();
}
