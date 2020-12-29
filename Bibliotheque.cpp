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
    Bibliotheque::adherents = Chaine<Adherent*>();
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
    Bibliotheque::adherents = Chaine<Adherent*>();
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
    int taille = other->getPtrLivres()->taille();
    for (int i=0; i < taille; i++){
        if (other->getLivres()[i].getISBN() == isbn && other->getLivres()[i].getEtat() == "libre"){
            Livre *l = other->getPtrLivres()->getPointerOfElement(i);
            Livre nouveauLivre = Livre(*l);
            nouveauLivre.setProvenance(other);
            this->ajouteLivre(nouveauLivre);
            l->setEtat("prêté");
        }
    }
}

void Bibliotheque::rendEmprunts() {
    for (int i=0; i<this->livres.taille(); i++){
        if (this->livres[i].getProvenance() != nullptr && this->livres[i].getEtat() == "libre") {
            int identifiant = this->livres[i].getIdentifiant();
            int j = this->livres[i].getProvenance()->getLivres().recherche_index_id(identifiant);
            this->livres[i].getProvenance()->getPtrLivres()->getPointerOfElement(j)->setEtat("libre");
            delete this->livres.pop(i);
            i--;
        }
    }
}

int Bibliotheque::addAdherent() {
    auto nouvelAdherent = new Adherent(this);
    adherents.ajoute(nouvelAdherent);
    return nouvelAdherent->getIdentifiant();
}

int Bibliotheque::addAdherent(string nom, string prenom, string adresse) {
    auto nouvelAdherent = new Adherent(nom, prenom, adresse, this);
    adherents.ajoute(nouvelAdherent);
    return nouvelAdherent->getIdentifiant();
}

Adherent *Bibliotheque::adherent(int identifiant) {
    int index = adherents.recherche_index_id(identifiant);
    if (index >= 0) return Bibliotheque::adherents[index];
    else return nullptr;
}

string Bibliotheque::generateSave(int indentation, string ind_type, string separator) {
    string ind = "";
    for (int i=0; i < indentation; i++) ind+=ind_type;
    string texte ="";
    texte += ind + "<Bibliotheque>" + separator;
    texte += ind+ind_type + "<code>"+to_string(code)+"</code>" + separator;
    texte += ind+ind_type + "<nom>"+nom+"</nom>" + separator;
    texte += ind+ind_type + "<adresse>"+adresse+"</adresse>" + separator;
    texte += ind+ind_type + "<livres>" + separator;
    for (int i=0; i<livres.taille(); i++) texte += livres[i].generateSave(indentation + 2, ind_type, separator) + separator;
    texte += ind+ind_type + "</livres>" + separator;
    texte += ind+ind_type + "<adherents>" + separator;
    for (int i=0; i<adherents.taille(); i++) texte += adherents[i]->generateSave(indentation + 2, ind_type, separator) + separator;
    texte += ind+ind_type + "</adherents>" + separator;
    texte += ind + "</Bibliotheque>";
    return texte;
}
