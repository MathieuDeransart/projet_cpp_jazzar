//
// Created by Deransart on 16/12/2020.
//

#include "Adherent.h"
#include "Bibliotheque.h"
#include "Livre.h"

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
                Livre * l = bibliotheque->getLivres().getPointerOfElement(i);
                l->setEtat("emprunté");
                livre_empruntes.ajoute(l);
            }
        }
    }
}

void Adherent::rendre(int i) {
    if (i < livre_empruntes.taille()) {
        Livre* aRendre = this->livre_empruntes[i];
        Livre** aRendre2 = this->livre_empruntes.pop(i);
        aRendre->setEtat("libre");
        delete aRendre2;
    }
}

void Adherent::rendreTout() {
    for (int i=0; i<livre_empruntes.taille(); i++) {
        this->rendre(0);
    }
}

void Adherent::sauvegarder(int indentation, string ind_type, string separator) {
    string ind = "";
    for (int i=0; i < indentation; i++) ind+=ind_type;
    string texte ="";
    texte += ind+ "<Adherent>" +separator;
    texte += ind+ind_type +"<numero_adherent>"+to_string(numero_adherent)+"</numero_adherent>" + separator;
    texte += ind+ind_type +"<nom>"+nom+"</nom>" + separator;
    texte += ind+ind_type +"<prenom>"+prenom+"</prenom>" + separator;
    texte += ind+ind_type +"<adresse>"+adresse+"</adresse>" + separator;
    texte += ind+ind_type +"<bibliotheque>"+to_string(bibliotheque->getIdentifiant())+"</bibliotheque>" + separator;
    texte += ind+ind_type +"<nombreLivreMax>"+to_string(nombreLivreMax)+"</nombreLivreMax>" + separator;
    texte += ind+ind_type +"<livre_empruntes>" + separator;
    for(int i=0; i<livre_empruntes.taille(); i++)
        texte += ind+ind_type+ind_type + to_string(livre_empruntes[i]->getIdentifiant()) + separator;
    texte += ind+ind_type +"</livre_empruntes>" + separator;
    texte += ind+ "</Adherent>";
    cout << texte << endl;
}

