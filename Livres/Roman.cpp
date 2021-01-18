#include "Roman.h"

string genres[] = {"Littérature",
             "Roman noir",
             "Roman policier",
             "Romananimalier",
             "Roman d'amour",
             "Roman de mœurs",
             "Roman gothique",
             "Roman courtois",
             "Roman épistolaire",
             "Roman-feuilleton",
             "Roman graphique",
             "Roman historique",
             "Roman-photo",
             "Roman picaresque",
             "Roman-mémoires",
             "Roman populaire",
             "Roman d'aventures",
             "Roman d'anticipation",
             "Roman d'espionnage",
             "Roman d'apprentissage",
             "Roman de chevalerie",
             "Roman autobiographique",
             "Nouveau roman",
             "Roman chevaleresque",
             "Conte",
             "Nouvelle",
             "Roman fantasy"};



Roman::Roman(string auteur, string titre, string editeur, string isbn, string publi,string etat,
             string genre) :
             Livre(auteur, titre, editeur, isbn, publi, etat) {

    try{
        bool presence = false;
        for(int i = 0; i<sizeof(genres)/sizeof(string); i++){
            if(genres[i]==genre){
                presence = true;
            }
        }
        if(not presence){
            throw string("Ce genre n'existe pas");
        }
        else{
            Roman::genre = genre;
        }
    }
    catch(string const& erreur){
        cout << erreur << endl;

    }
}

void Roman::affiche() {

    Livre::affiche();
    cout << "Genre : " << genre << endl;
}


