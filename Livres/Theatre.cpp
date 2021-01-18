#include "Theatre.h"

Theatre::Theatre(string auteur, string titre, string editeur, string isbn, string publi, string etat,
                 int siecle) :
                 Livre(auteur, titre, editeur, isbn, publi, etat){
    Theatre::siecle = siecle;
}

void Theatre::affiche() {
    Livre::affiche();
    cout << "Siècle : " << siecle << endl;
}