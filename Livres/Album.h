

#ifndef PROJET_ALBUM_H
#define PROJET_ALBUM_H
#include "../Livre.h"

class Album : public Livre {

protected:
    string illustration;

public:
    Album(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre",
          string illustration="Photos");

    void affiche();

    const string &getIllustration() const {
        return illustration;
    }

    void setIllustration(const string &illustration) {
        Album::illustration = illustration;
    }

};


#endif //PROJET_ALBUM_H
