//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H
#include <string>
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
    static int nombreLivre;
public:
    Livre();
    Livre(string auteur, string titre, string editeur, string isb, string publi, string etat);
    void saisieLivre();
    void affiche();
    void affiche_peu();
    int getIdentifiant() {return code;};
    string getISBN() {return isbn;};
};


#endif //PROJET_LIVRE_H
