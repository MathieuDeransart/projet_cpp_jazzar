//
// Created on 16/12/2020.
//
/*
comment on fait pour articuler la démocratie participatif / représentatif (éviter les limites d'un système représentatif (qui diminue la réalité de l'importance de la question, c'est appauvrissant))
Sur un cas de figure "concret" montrer comment ça peut fonctionner, et les limites
*/


#include "Livre.h"
#include "Bibliotheque.h"
#include <iostream>
#include <map>
using namespace std;

int Livre::nombreLivre = 0;

Livre::Livre(string sub_save,  map<int, Bibliotheque*> id_to_bb) {

    // LECTURE DE LA SAVE
    int code;
    Bibliotheque* provenance;
    string auteur, titre, editeur, isbn, publi, etat;
    string motif;
    int c0, c1;
    motif = "code";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;  // curseur sur le premier caractère suivant la balise d'ouverture
    c1 = sub_save.find("</"+motif+">");  // curseur sur le premier caratère de la balise de fermeture
    code = stoi(sub_save.substr(c0, c1-c0));}
    motif = "auteur";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    auteur = sub_save.substr(c0, c1-c0);}
    motif = "titre";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    titre = sub_save.substr(c0, c1-c0);}
    motif = "editeur";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    editeur = sub_save.substr(c0, c1-c0);}
    motif = "isbn";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    isbn = sub_save.substr(c0, c1-c0);}
    motif = "publi";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    publi = sub_save.substr(c0, c1-c0);}
    motif = "etat";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    etat = sub_save.substr(c0, c1-c0);}
    motif = "provenance";
    {c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    provenance = id_to_bb[stoi(sub_save.substr(c0, c1-c0))];}

    // CRÉATION DE L'OBJET
    Livre::code = code;
    Livre::auteur = auteur;
    Livre::titre = titre;
    Livre::editeur = editeur;
    Livre::isbn = isbn;
    Livre::publi = publi;
    Livre::etat = etat;
    Livre::provenance = provenance;
}

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

string Livre::generateSave(int indentation, string ind_type, string separator) {
    string ind = "";
    for (int i=0; i < indentation; i++) ind+=ind_type;
    string texte ="";
    texte += ind + "<Livre>" + separator;
    texte += ind+ind_type + "<code>"+to_string(code)+"</code>"+separator;
    texte += ind+ind_type + "<auteur>"+auteur+"</auteur>"+separator;
    texte += ind+ind_type + "<titre>"+titre+"</titre>"+separator;
    texte += ind+ind_type + "<editeur>"+editeur+"</editeur>"+separator;
    texte += ind+ind_type + "<isbn>"+isbn+"</isbn>"+separator;
    texte += ind+ind_type + "<publi>"+publi+"</publi>"+separator;
    texte += ind+ind_type + "<etat>"+etat+"</etat>"+separator;
    if (provenance != NULL) texte += ind+ind_type + "<provenance>"+to_string(provenance->getIdentifiant())+"</provenance>"+separator;
    else texte += ind+ind_type + "<provenance>-1</provenance>"+separator;
    texte += ind + "</Livre>";
    return texte;
}

void Livre::loadSave(string sub_save, map<int, Bibliotheque*> id_to_bb) {

    // LECTURE DE LA SAVE

    int code;
    Bibliotheque* provenance;
    string auteur, titre, editeur, isbn, publi, etat;
    string motif;
    int c0, c1;
    motif = "code";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;  // curseur sur le premier caractère suivant la balise d'ouverture
    c1 = sub_save.find("</"+motif+">");  // curseur sur le premier caratère de la balise de fermeture
    code = stoi(sub_save.substr(c0, c1-c0));

    motif = "auteur";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    auteur = sub_save.substr(c0, c1-c0);

    motif = "titre";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    titre = sub_save.substr(c0, c1-c0);

    motif = "editeur";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    editeur = sub_save.substr(c0, c1-c0);

    motif = "isbn";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    isbn = sub_save.substr(c0, c1-c0);

    motif = "publi";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    publi = sub_save.substr(c0, c1-c0);

    motif = "etat";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    etat = sub_save.substr(c0, c1-c0);

    motif = "provenance";
    c0 = sub_save.find("<"+motif+">") + motif.length() + 2;
    c1 = sub_save.find("</"+motif+">");
    provenance = id_to_bb[stoi(sub_save.substr(c0, c1-c0))];

    // CRÉATION DE L'OBJET

    //cout << "code :" << code << " - auteur :" << auteur << " - titre :" << titre << " - editeur :" << editeur
    //<< " - isbn :" << isbn << " - publi :" << publi << " - etat :" << etat << " - provenance :" << provenance << endl;
}

