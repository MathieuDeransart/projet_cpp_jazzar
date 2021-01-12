//
// Created on 18/12/2020.
//

#ifndef PROJET_ACHAT_H
#define PROJET_ACHAT_H
#include <iostream>
#include "Date.h"

#include "Livre.h"
using namespace std;

/*
 * MÉTHODES :
 *  Achat() : crée un nouvel achat et demande de saisir le livre et la date
 *  Achat(livre, date) : crée un nouvel achat avec les arguments donnés
 */


class Achat {
private:
    int identifiant;
    Date date;
    Livre livre;
    static int nombreAchat;
public:
    Achat();
    Achat(Livre livre, Date date = Date());
    void affiche();
    void affiche_peu();
    int getIdentifiant();
};


#endif //PROJET_ACHAT_H
