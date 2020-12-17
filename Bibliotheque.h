//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_BIBLIOTHEQUE_H
#define PROJET_BIBLIOTHEQUE_H
#include "Adherent.h"
#include "Livre.h"
#include "Emprunt.h"
#include "Echange.h"
#include "string"
#include <iostream>
using namespace std;

class Bibliotheque {
private:
    Livre *books;
    Adherent *adherents;
    Emprunt *loans;
    Echange *exchange;
    Livre *achats;
    Livre *pertes;
    Livre *miseAuPilon;

};



#endif //PROJET_BIBLIOTHEQUE_H
