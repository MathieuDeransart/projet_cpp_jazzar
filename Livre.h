//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H
#include <string>
#include <iostream>
class Bibliotheque;
using namespace std;

/*
 * DESCRIPTION:
 *
 * MÉTHODES:
 *  Livre() -> crée un livre sans aucune information (juste son code est généré correctement)
 *  Livre(Livre) -> constructeur de recopie, garde le même code et n'augmente pas le compteur de classe
 *  Livre(informations...) -> crée un livre avec les informations fournies en argument
 *  saisiLivre() -> interface pour rentrer les données dans une instance créée sans informations
 *  affiche() -> affiche toutes les données et saute une ligne
 *  affiche_peu() -> affiche le titre et l'auteur sur une ligne, sans sauter de ligne
 *  getIdentifiant() -> retourne le code du livre, qui sert d'identifiant pour les recherches dans des chaines
 *  getISBN() -> getter de l'attribut isbn
 *  getEtat() -> getter de l'attribut etat
 *  setEtat(string) -> setter de l'attribut etat
 *  setProvenance(Bibliotheque*) -> setter de l'attribut provenance
 */

class Livre {
protected:
    int code;  // /!\ sert d'identifiant pour la classe livre
    string auteur;
    string titre;
    string editeur;
    string isbn;
    string publi;
    string etat;
    Bibliotheque* provenance;  // NULL signifie que le livre a été acheté par la bibli dans laquelle il se trouve
    static int nombreLivre;

public:
    Livre();
    Livre(Livre const &other);
    Livre(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre");
    void saisieLivre();
    void affiche();
    void affiche_peu();
    int getIdentifiant() {return code;};
    string getISBN() {return isbn;};
    string getEtat() {return etat;};
    void setEtat(string etat) {Livre::etat = etat;};
    void setProvenance(Bibliotheque* provenance) { Livre::provenance = provenance;};
    Bibliotheque* getProvenance() {return provenance;};
};


#endif //PROJET_LIVRE_H
