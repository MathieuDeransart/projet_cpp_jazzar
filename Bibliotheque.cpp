//
// Created by Deransart on 16/12/2020.
//

#include "Bibliotheque.h"
#include "MiseAuPilon.h"
#include "Perte.h"

int Bibliotheque::nombre_bibliotheque = 0;

Bibliotheque::Bibliotheque() {
    Bibliotheque::livres = Chaine<Livre>();
    livres.maj_ptr_premier();
    Bibliotheque::adherents = Chaine<Adherent>();
    adherents.maj_ptr_premier();
    Bibliotheque::emprunts = Chaine<Emprunt>();
    emprunts.maj_ptr_premier();
    Bibliotheque::echanges = Chaine<Echange>();
    echanges.maj_ptr_premier();
    Bibliotheque::achats = Chaine<Achat>();
    achats.maj_ptr_premier();
    Bibliotheque::pertes = Chaine<Perte>();
    pertes.maj_ptr_premier();
    Bibliotheque::miseAuPilon = Chaine<MiseAuPilon>();
    miseAuPilon.maj_ptr_premier();
    Bibliotheque::code = nombre_bibliotheque++;
    nom = "non renseigné";
    adresse = "non renseignée";
    saisie_bibliotheque();
}

void Bibliotheque::saisie_bibliotheque() {
    cout << "Saisie de Bibliothèque :" << endl;
    cout << "Nom : "; cin >> Bibliotheque::nom;
    cout << "Adresse : "; cin >> Bibliotheque::adresse;
}

Bibliotheque::Bibliotheque(string nom, string adresse) {
    Bibliotheque::livres = Chaine<Livre>();
    livres.maj_ptr_premier();
    Bibliotheque::adherents = Chaine<Adherent>();
    adherents.maj_ptr_premier();
    Bibliotheque::emprunts = Chaine<Emprunt>();
    emprunts.maj_ptr_premier();
    Bibliotheque::echanges = Chaine<Echange>();
    echanges.maj_ptr_premier();
    Bibliotheque::achats = Chaine<Achat>();
    achats.maj_ptr_premier();
    Bibliotheque::pertes = Chaine<Perte>();
    pertes.maj_ptr_premier();
    Bibliotheque::miseAuPilon = Chaine<MiseAuPilon>();
    miseAuPilon.maj_ptr_premier();
    Bibliotheque::code = nombre_bibliotheque++;
    Bibliotheque::nom = nom;
    Bibliotheque::adresse = adresse;
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

void Bibliotheque::affiche() {
    cout << "Bibliotheque n°" << code << endl;
    cout << "Nom : " << nom << endl;
    cout << "Adresse : " << adresse << endl;
}

void Bibliotheque::affiche_peu() {
    cout << nom;
}

void Bibliotheque::emprunte(string isbn, Bibliotheque *other) {
    int taille = other->getLivres().taille();
    for (int i=0; i < taille; i++){
        if (other->getLivres()[i].getISBN() == isbn && other->getLivres()[i].getEtat() == "libre"){
            Livre *l = other->getLivres().getPointerOfElement(i);
            Livre nouveauLivre = Livre(*l);
            nouveauLivre.setProvenance(other);
            this->ajouteLivre(nouveauLivre);
            l->setEtat("prêté");
        }
    }
}

void Bibliotheque::rendEmprunts() {
    for (int i=0; i<this->livres.taille(); i++){
        if (this->livres[i].getProvenance() != this && this->livres[i].getEtat() == "libre") {
            int identifiant = this->livres[i].getIdentifiant();
            int j = this->livres[i].getProvenance()->getLivres().recherche_index_id(identifiant);
            this->livres[i].getProvenance()->livres[j].setEtat("libre");
            delete this->livres.pop(i);
            i--;
        }
    }
}
