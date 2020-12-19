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

int Livre::nombreLivre = 0;

Livre::Livre() {
    Livre::code = nombreLivre++;
    Livre::auteur = "non renseigné";
    Livre::titre = "non renseigné";
    Livre::editeur = "non renseigné";
    Livre::isbn = "non renseigné";
    Livre::publi = "non renseigné";
    Livre::etat = "non renseigné";
}

void Livre::saisieLivre() {
    cout << "Saisie livre :" << endl;
    cout << "Code (identifiant): " << Livre::code << endl;
    cout << "Auteur : "; cin >> Livre::auteur;
    cout << "Titre : "; cin >> Livre::titre;
    cout << "Éditeur : "; cin >> Livre::editeur;
    cout << "ISB : "; cin >> Livre::isbn;
    cout << "Public : "; cin >> Livre::publi;
    cout << "État : "; cin >> Livre::etat;
}

Livre::Livre(string auteur, string titre, string editeur, string isb, string publi, string etat) {
    Livre::code = nombreLivre++;
    Livre::auteur = auteur;
    Livre::titre = titre;
    Livre::editeur = editeur;
    Livre::isbn = isb;
    Livre::publi = publi;
    Livre::etat = etat;
}

void Livre::affiche() {
    cout << "Titre : " << titre << endl << "Auteur : " << auteur << endl;
    cout << "Public : " << publi << "   État : " << etat << endl;
    cout << "Détail : Code=" << code << " Editeur=" << editeur << " ISB=" << isbn << endl;
}

void Livre::affiche_peu() {
    cout << "\"" << titre << "\" de " << auteur;
}
