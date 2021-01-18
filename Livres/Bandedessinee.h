//
// Created by djost on 12/01/2021.
//

#ifndef PROJET_BANDEDESSINEE_H
#define PROJET_BANDEDESSINEE_H
#include "../Livre.h"


class Bandedessinee : public Livre{

protected:
    string dessinateur;

public:
    Bandedessinee(string auteur, string titre, string editeur, string isbn, string publi, string etat = "libre",
                  string dessinateur="Incoonu");

    const string &getDessinateur() const {
        return dessinateur;
    }

    void setDessinateur(const string &dessinateur) {
        Bandedessinee::dessinateur = dessinateur;
    }

    void affiche();

};


#endif //PROJET_BANDEDESSINEE_H
