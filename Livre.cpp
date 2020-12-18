//
// Created by Deransart on 16/12/2020.
//
/*
comment on fait pour articuler la démocratie participatif / représentatif (éviter les limites d'un système représentatif (qui diminue la réalité de l'importance de la question, c'est appauvrissant))
Sur un cas de figure "concret" montrer comment ça peut fonctionner, et les limites
*/


#include "Livre.h"
#include <iostream>
using namespace std;

Livre::Livre() {
    Livre::code = "Non renseigné";
    Livre::auteur = "Non renseigné";
    Livre::titre = "Non renseigné";
    Livre::editeur = "Non renseigné";
    Livre::isb = "Non renseigné";
    Livre::publi = "Non renseigné";
    Livre::etat = "Non renseigné";
}

Livre::Livre(string code, string auteur, string titre, string editeur, string isb, string publi, string etat) {
    Livre::code = code;
    Livre::auteur = auteur;
    Livre::titre = titre;
    Livre::editeur = editeur;
    Livre::isb = isb;
    Livre::publi = publi;
    Livre::etat = etat;
}

void Livre::affiche() {
    cout << "Titre : " << titre << endl << "Auteur : " << auteur << endl;
    cout << "Public : " << publi << "   État : " << etat << endl;
    cout << "Détail : Code=" << code << " Editeur=" << editeur << " ISB=" << isb << endl;
}

void Livre::affiche_peu() {
    cout << "Titre : " << titre << "  Auteur : " << auteur << endl;
}

string Livre::getIdentifiant() {
    return code;
}


