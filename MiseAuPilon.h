//
// Created by Deransart on 19/12/2020.
//

#ifndef PROJET_MISEAUPILON_H
#define PROJET_MISEAUPILON_H
#include "Livre.h"
#include "Date.h"

class MiseAuPilon {
private:
    int identifiant;
    Date date;
    Livre livre;
    static int nombreMiseAuPilon;
public:
    MiseAuPilon();
    MiseAuPilon(Livre livre, Date date = Date());
    void affiche();
    void affiche_peu();
    int getIdentifiant();
};


#endif //PROJET_MISEAUPILON_H
