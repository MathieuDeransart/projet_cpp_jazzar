//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_ECHANGE_H
#define PROJET_ECHANGE_H
#include "Bibliotheque.h"
#include "Livre.h"

class Echange {
private:
    Bibliotheque *preteur;
    Livre *livre;
    Bibliotheque *receveur;
public:
    Echange(Bibliotheque *preteur, Livre *livre, Bibliotheque *receveur);
    virtual ~Echange();

};


#endif //PROJET_ECHANGE_H
