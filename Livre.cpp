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
    Livre::provenance = nullptr;
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

Livre::Livre(string auteur, string titre, string editeur, string isbn, string publi, string etat) {
    Livre::code = nombreLivre++;
    Livre::auteur = auteur;
    Livre::titre = titre;
    Livre::editeur = editeur;
    Livre::isbn = isbn;
    Livre::publi = publi;
    Livre::etat = etat;
    Livre::provenance = NULL;
}

void Livre::affiche() {
    cout << "Titre : " << titre << endl << "Auteur : " << auteur << endl;
    cout << "Public : " << publi << "   État : " << etat << endl;
    cout << "Détail : Code=" << code << " Editeur=" << editeur << " ISBN=" << isbn << endl;
    cout << "Provenance : " << provenance << endl;
}

void Livre::affiche_peu() {
    cout << "\"" << titre << "\" de " << auteur;
}

Livre::Livre(Livre const &other) {
    Livre::code = other.code;
    Livre::auteur = other.auteur;
    Livre::titre = other.titre;
    Livre::editeur = other.editeur;
    Livre::isbn = other.isbn;
    Livre::publi = other.publi;
    Livre::etat = other.etat;
    Livre::provenance = other.provenance;
}
