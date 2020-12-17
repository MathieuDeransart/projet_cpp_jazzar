//
// Created by Deransart on 16/12/2020.
//

#include "Echange.h"

Echange::Echange(Bibliotheque *preteur, Livre *livre, Bibliotheque *receveur) {
    Echange::preteur = preteur;
    Echange::livre = livre;
    Echange::receveur = receveur;
}

Echange::~Echange() {
}
