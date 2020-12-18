//
// Created by Deransart on 16/12/2020.
//

#include "Bibliotheque.h"

Bibliotheque::Bibliotheque() {
    Bibliotheque::livres = Chaine<Livre>();
    livres.maj_ptr_premier();
    Bibliotheque::adherents = Chaine<Adherent>();
    adherents.maj_ptr_premier();
    Bibliotheque::emprunts = Chaine<Emprunt>();
    emprunts.maj_ptr_premier();
    Bibliotheque::echanges = Chaine<Echange>();
    echanges.maj_ptr_premier();
    Bibliotheque::achats = NULL;
    Bibliotheque::pertes = NULL;
    Bibliotheque::miseAuPilon = NULL;
}

Chaine<Livre> Bibliotheque::getLivres() {
    return livres;
}

void Bibliotheque::ajouteLivre(Livre &livre) {
    livres.ajoute(livre);
}

void Bibliotheque::ajouteLivre(Chaine<Livre> livres) {
    for (int i=0; i<livres.taille(); i++){
        Livre l = livres[i];
        Bibliotheque::livres.ajoute(l);
    }
}
