//
// Created by Deransart on 16/12/2020.
//

#include "Bibliotheque.h"

Bibliotheque::Bibliotheque() {
    Bibliotheque::livres = Chaine<Livre>();
    Bibliotheque::adherents = Chaine<Adherent>();
    Bibliotheque::emprunts = Chaine<Emprunt>();
    Bibliotheque::echanges = Chaine<Echange>();
    Bibliotheque::achats = NULL;
    Bibliotheque::pertes = NULL;
    Bibliotheque::miseAuPilon = NULL;
}

Bibliotheque::Bibliotheque(Chaine<Livre> livres, Chaine<Adherent> adherents, Chaine<Emprunt> emprunts,
                           Chaine<Echange> echanges, Livre *achats, Livre *pertes, Livre *miseAuPilon) {
    Bibliotheque::livres = livres;
    Bibliotheque::adherents = adherents;
    Bibliotheque::emprunts = emprunts;
    Bibliotheque::echanges = echanges;
    Bibliotheque::achats = achats;
    Bibliotheque::pertes = pertes;
    Bibliotheque::miseAuPilon = miseAuPilon;
}

Chaine<Livre> Bibliotheque::getLivres() {
    return livres;
}
