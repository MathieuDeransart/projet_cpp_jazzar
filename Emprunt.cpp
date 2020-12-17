//
// Created by Deransart on 16/12/2020.
//

#include "Emprunt.h"
#include <iostream>
using namespace std;

int Emprunt::nombre_emprunt = 0;

Emprunt::Emprunt() {
    Emprunt::preteur = NULL;
    Emprunt::emprunteur = NULL;
    Emprunt::identifiant = nombre_emprunt++;
}

Emprunt::Emprunt(Bibliotheque *preteur, Adherent *emprunteur) {
    Emprunt::preteur = preteur;
    Emprunt::emprunteur = emprunteur;
    Emprunt::identifiant = nombre_emprunt++;
}

int Emprunt::getIdentifiant() {
    return identifiant;
}
