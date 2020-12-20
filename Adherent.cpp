//
// Created by Deransart on 16/12/2020.
//

#include "Adherent.h"
#include "Bibliotheque.h"

int Adherent::nombre_adherent = 0;

Adherent::Adherent() {
    Adherent::nom = "Non renseigné";
    Adherent::prenom = "Non renseigné";
    Adherent::adresse = "Non renseigné";
    Adherent::numero_adherent = nombre_adherent++;
    Adherent::bibliotheque = NULL;
    Adherent::nombreLivreMax = 3;
    Adherent::livre_empruntes = Chaine<Livre*>();
    livre_empruntes.maj_ptr_premier();
}

Adherent::Adherent(Bibliotheque *bibliotheque) {
    Adherent::numero_adherent = nombre_adherent++;
    Adherent::bibliotheque = bibliotheque;
    Adherent::nombreLivreMax = 3;
    Adherent::livre_empruntes = Chaine<Livre*>();
    livre_empruntes.maj_ptr_premier();
    saisie_adherent();
}

void Adherent::saisie_adherent() {
    cout << "Nouvel adhérent :" << endl;
    cout << "Nom : "; cin >> Adherent::nom;
    cout << "Prenom : "; cin >> Adherent::prenom;
    cout << "Adresse : "; cin >> Adherent::adresse;
}

Adherent::Adherent(string nom, string prenom, string adresse, Bibliotheque *bibliotheque) {
    Adherent::nom = nom;
    Adherent::prenom = prenom;
    Adherent::adresse = adresse;
    Adherent::numero_adherent = nombre_adherent++;
    Adherent::bibliotheque = bibliotheque;
    Adherent::livre_empruntes = Chaine<Livre *>();
    Adherent::nombreLivreMax = 3;
    Adherent::livre_empruntes.maj_ptr_premier();
}

int Adherent::getIdentifiant() {
    return numero_adherent;
}

void Adherent::affiche() {
    cout << "Adhérent n°" << numero_adherent << " :" << endl;
    cout << "Nom : " << nom << "  Prénom : " << prenom << endl;
    cout << "Adresse : " << adresse << endl;
    cout << "Bibliothèque : "; bibliotheque->affiche();
    cout << "Livres empruntés : " << endl; livre_empruntes.affiche();
}

void Adherent::affiche_peu() {
    cout << nom << " " << prenom << " possède : "; livre_empruntes.affiche_peu();
}

void Adherent::emprunter(int codeLivre) {
    if (livre_empruntes.taille() < nombreLivreMax) {
        int i = bibliotheque->getLivres().recherche_index_id(codeLivre);
        if (i != -1) {
            string etat = bibliotheque->getLivres()[i].getEtat();
            if (etat == "libre"){
                bibliotheque->getLivres()[i].setEtat("emprunté");
                Livre * l = bibliotheque->getLivres().getPointerOfElement(i);
                cout << "Poiteur :" << l << "  Du livre "; l->affiche_peu(); cout << endl;
                livre_empruntes.ajoute(l);
            }
        }
    }
}
