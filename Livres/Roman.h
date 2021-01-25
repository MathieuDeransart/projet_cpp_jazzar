#ifndef PROJET_ROMAN_H
#define PROJET_ROMAN_H
#include "../Livre.h"



class Roman : public Livre {

protected:
    string genre = "Inconnu";

public:
    Roman(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre",
          string genre="Littérature");

    const string &getGenre() const {
        return genre;
    }

    void setGenre(const string &genre) {
        Roman::genre = genre;
    }

    void affiche();
    string type() {return "Roman";};
};


#endif //PROJET_ROMAN_H
