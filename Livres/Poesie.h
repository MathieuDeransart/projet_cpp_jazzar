
#ifndef PROJET_POESIE_H
#define PROJET_POESIE_H
#include "../Livre.h"

class Poesie : public Livre {

protected:
    string indicateur;

public:
    Poesie(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre",
           string indicateur="Vers");

    void affiche();

    const string &getType() const {
        return indicateur;
    }

    void setType(const string &type) {
        Poesie::indicateur = type;
    }

};


#endif //PROJET_POESIE_H
