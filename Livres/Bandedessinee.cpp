#include "Bandedessinee.h"

Bandedessinee::Bandedessinee(string auteur, string titre, string editeur, string isbn, string publi, string etat,
                             string dessinateur) :
                             Livre(auteur, titre, editeur, isbn, publi, etat){
    Bandedessinee::dessinateur = dessinateur;
}

void Bandedessinee::affiche() {
    Livre::affiche();
    cout << "Dessinateur : " << dessinateur << endl;
}

