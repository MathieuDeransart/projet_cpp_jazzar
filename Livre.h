//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H
#include <string>
class Bibliotheque;
using namespace std;

class Livre {
protected:
    int code;  // /!\ sert d'identifiant pour la classe livre
    string auteur;
    string titre;
    string editeur;
    string isbn;
    string publi;
    string etat;
    Bibliotheque* provenance = NULL;  // NULL signifie que le livre a été acheté par là bibli dans laquelle il se trouve
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
