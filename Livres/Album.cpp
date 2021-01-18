#include "Album.h"

string illustrations[] = {"Photos",
                         "Dessin",
                         "Photos et Dessins"};

Album::Album(string auteur, string titre, string editeur, string isbn, string publi, string etat,
             string illustration) :
             Livre(auteur, titre, editeur, isbn, publi, etat){
    try{
        bool presence = false;
        for(int i = 0; i< sizeof(illustrations)/ sizeof(string); i++){
            if(illustrations[i]==illustration){
                presence = true;
            }
        }
        if(not presence){
            throw string("Ce genre n'existe pas");
        }
        else{
            Album::illustration = illustration;
        }
    }
    catch(string const& erreur){
        cout << erreur << endl;

    }
}

void Album::affiche() {
    Livre::affiche();
    cout << "Illustration : " << illustration << endl;
}

