#include "Poesie.h"

string indicateurs[] = {"Vers",
                        "Prose",
                        "Vers et Prose"};

Poesie::Poesie(string auteur, string titre, string editeur, string isbn, string publi, string etat,
               string indicateur):
               Livre(auteur, titre, editeur, isbn, publi, etat){

    try{
        bool presence = false;
        for(int i = 0; i< sizeof(indicateurs) / sizeof(string); i++){
            if(indicateurs[i] == indicateur){
                presence = true;
            }
        }
        if(not presence){
            throw string("Ce indicateur n'existe pas");
        }
        else{
            Poesie::indicateur = indicateur;
        }
    }
    catch(string const& erreur){
        cout << erreur << endl;

    }
}

void Poesie::affiche() {
    Livre::affiche();
    cout << "Indicateur : " << indicateur << endl;
}
