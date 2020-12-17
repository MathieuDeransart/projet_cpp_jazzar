//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H
#include <string>
using namespace std;

class Livre {
protected:
    string code;  // /!\ sert d'identifiant pour la classe livre
    string auteur;
    string titre;
    string editeur;
    string isb;
    string publi;
    string etat;
public:
    Livre();
    Livre(string code, string auteur, string titre, string editeur, string isb, string publi, string etat);
    void affiche();
    string getIdentifiant(); // renvoie le paramètre 'code'
};


#endif //PROJET_LIVRE_H
