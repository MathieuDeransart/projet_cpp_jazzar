//
// Created on 16/12/2020.
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H
#include <string>
#include <iostream>
#include <map>

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
    Livre(string sub_save, map<int, Bibliotheque*> id_to_bb);
    ~Livre() = default;
    void saisieLivre();
    void affiche();
    void affiche_peu();
    string type() {return "None";};
    string generateSave(int indentation = 0, string ind_type ="  ", string separator = "\n");
    static void loadSave(string save, map<int, Bibliotheque*> id_to_bb);

    int getIdentifiant() {return code;};
    string getAuteur() {return auteur;};
    void setAuteur(string auteur) {Livre::auteur=auteur;};
    string getTitre() {return titre;};
    void setTitre(string titre) {Livre::titre=titre;};
    string getEditeur() {return editeur;};
    void setEditeur(string editeur) {Livre::editeur=editeur;};
    string getISBN() {return isbn;};
    void setIsbn(string isbn) {Livre::isbn=isbn;};
    string getPublic() {return publi;};
    void setPublic(string publi) {Livre::publi=publi;};
    string getEtat() {return etat;};
    void setEtat(string etat) {Livre::etat=etat;};
    Bibliotheque* getProvenance() {return provenance;};
    void setProvenance(Bibliotheque* provenance) { Livre::provenance=provenance;};
    static int getNombreLivre() {return nombreLivre;};
    static void setNombreLivre(int nombreLivre) {Livre::nombreLivre=nombreLivre;};
};


#endif //PROJET_LIVRE_H
