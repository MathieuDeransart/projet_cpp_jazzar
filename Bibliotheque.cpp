//
// Created on 16/12/2020.
//

#include "Bibliotheque.h"
#include "MiseAuPilon.h"
#include "Perte.h"
#include <map>

int Bibliotheque::nombre_bibliotheque = 0;

Bibliotheque::Bibliotheque(int code, string nom, string adresse) {
    Bibliotheque::livres = Chaine<Livre>();
    livres.maj_ptr_premier();
    Bibliotheque::adherents = Chaine<Adherent*>();
    adherents.maj_ptr_premier();
    Bibliotheque::code = code;
    Bibliotheque::nom = nom;
    Bibliotheque::adresse = adresse;
}

Bibliotheque::Bibliotheque() {
    Bibliotheque::livres = Chaine<Livre>();
    livres.maj_ptr_premier();
    Bibliotheque::adherents = Chaine<Adherent*>();
    adherents.maj_ptr_premier();
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
    Bibliotheque::code = nombre_bibliotheque++;
    Bibliotheque::nom = nom;
    Bibliotheque::adresse = adresse;
}

Chaine<Livre> Bibliotheque::getLivres() {
    return livres;
}

Livre *Bibliotheque::achat(string sub_save, map<int, Bibliotheque*> id_to_bb) {
    Livre nouveauLivre = Livre(sub_save, id_to_bb);
    livres.ajoute(nouveauLivre);
    return livres.getPointerOfElement(0);
}

void Bibliotheque::achat(Livre &livre) {
    livres.ajoute(livre);
}

void Bibliotheque::achat(Chaine<Livre> livres) {
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
            this->achat(nouveauLivre);
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

void Bibliotheque::addAdherent(string sub_save, map<int, Bibliotheque*> id_to_bb, map<int, Livre*> id_to_livre) {
    Adherent* nouvelAdherent = new Adherent(sub_save, id_to_bb, id_to_livre);
    adherents.ajoute(nouvelAdherent);
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
    texte += ind+ind_type + "<code_bibliotheque>"+to_string(code)+"</code_bibliotheque>" + separator;
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

Chaine<Bibliotheque*> Bibliotheque::loadSave(string save) {
    Chaine<Bibliotheque*> bibliotheques = Chaine<Bibliotheque*>();
    map<int, Bibliotheque*> id_to_bb;
    id_to_bb[-1] = nullptr;
    string nom, adresse;
    int code;
    string motif;
    int c0, c1;
    int d0, d1;

    // CRÉATION DES BIBLIOTHÈQUES
    c0 = save.find("<Bibliotheque>");
    while (c0 > 0) {
        c1 = save.find("</Bibliotheque>", c0);
        motif = "code_bibliotheque";
        {d0 = save.find("<"+motif+">", c0) + motif.length() + 2;  // curseur sur le premier caractère suivant la balise d'ouverture
        d1 = save.find("</"+motif+">", c0);  // curseur sur le premier caractère de la balise de fermeture
        code = stoi(save.substr(d0, d1-d0));}
        motif = "nom";
        {d0 = save.find("<"+motif+">", c0) + motif.length() + 2;
        d1 = save.find("</"+motif+">", c0);
        nom = save.substr(d0, d1-d0);}
        motif = "adresse";
        {d0 = save.find("<"+motif+">", c0) + motif.length() + 2;
        d1 = save.find("</"+motif+">", c0);
        adresse = save.substr(d0, d1-d0);}

        auto nouvelleBibliotheque = new Bibliotheque(code, nom, adresse);
        bibliotheques.ajoute(nouvelleBibliotheque);
        id_to_bb[code] = nouvelleBibliotheque;

        c0 = save.find("<Bibliotheque>", c1);
    }

    // REMPLISSAGE DES BIBLIOTHEQUES

    for (int i=0; i<bibliotheques.taille(); i++){
        map<int, Livre*> id_to_livre;
        int identifiant = bibliotheques[i]->getIdentifiant();
        c0 = save.find("<code_bibliotheque>"+to_string(identifiant)+"</code_bibliotheque>");  //on se place dans la bonne biblio
        c0 = save.find("<livres>", c0);  //curseur sur la balise d'ouverture 'livres' de la biblio considérée
        c1 = save.find("</livres>", c0);  // idem pour fermeture
        d0 = save.find("<Livre>", c0);
        while (d0 > 0 && d0 < c1) {  // on vérifie que le livre (si trouvé) n'est pas après la balise de fermeture
            d1 = save.find("</Livre>", d0);
            string sub_save = save.substr(d0, d1-d0);
            Livre* l = bibliotheques[i]->achat(sub_save, id_to_bb);
            id_to_livre[l->getIdentifiant()]=l;  // on map pour la création des adhérents
            d0 = save.find("<Livre>", d1);
        }

        c0 = save.find("<code_bibliotheque>"+to_string(identifiant)+"</code_bibliotheque>");  //on se place dans la bonne biblio
        c0 = save.find("<adherents>", c0);  //curseur sur la balise d'ouverture 'adherents' de la biblio considérée
        c1 = save.find("</adherents>", c0);  // idem pour fermeture
        d0 = save.find("<Adherent>", c0);
        while (d0 > 0 && d0 < c1) {
            d1 = save.find("</Adherent>", d0);
            string sub_save = save.substr(d0, d1-d0);
            bibliotheques[i]->addAdherent(sub_save, id_to_bb, id_to_livre);
            d0 = save.find("<Adherent>", d1);
        }
    }

    // MISE À JOUR DES VARIABLES DE CLASSES
    // À FAIRE AVEC LES DEUX PREMIÈRES BALISES DE LA SAUVEGARDE
    motif = "nombreLivre";
    {c0 = save.find("<"+motif+">") + motif.length() + 2;
    c1 = save.find("</"+motif+">");
    Livre::setNombreLivre(stoi(save.substr(c0, c1-c0)));}
    motif = "nombre_adherent";
    {c0 = save.find("<"+motif+">") + motif.length() + 2;
    c1 = save.find("</"+motif+">");
    Adherent::setNombreAdherent(stoi(save.substr(c0, c1-c0)));}

    return bibliotheques;
}

void Bibliotheque::miseAuPilon(Livre livre) {
    livres.enleve(livre);
}

void Bibliotheque::perte(Livre livre, Adherent* adherent) {
    int i = adherent->getLivreEmpruntes().recherche_index_id(livre.getIdentifiant());
    int j = adherents.recherche_index_id(adherent->getIdentifiant());
    if (j >= 0 && i >=0) {
        Adherent* cible = adherents[j];
        cible->rendre(i);
    }
    this->miseAuPilon(livre);
}
