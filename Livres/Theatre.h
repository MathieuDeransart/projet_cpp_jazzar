//
// Created by djost on 12/01/2021.
//

#ifndef PROJET_THEATRE_H
#define PROJET_THEATRE_H
#include "../Livre.h"


class Theatre : public Livre{

protected:
    int siecle;

public:
    Theatre(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre",
            int siecle=1);
    void affiche();

    int getSiecle() const {
        return siecle;
    }

    void setSiecle(int siecle) {
        Theatre::siecle = siecle;
    }


};


#endif //PROJET_THEATRE_H
