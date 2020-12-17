#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "Création d'une liste de livres..." << endl;
    Livre livre1 = Livre("Le code 1", "L'auteur 1", "Le titre 1", "L'éditeur 1", "ISB 1", "Public 1", "Etat 1");
    Livre livre2 = Livre("Le code 2", "L'auteur 2", "Le titre 2", "L'éditeur 2", "ISB 2", "Public 2", "Etat 2");
    Livre livre3 = Livre("Le code 3", "L'auteur 3", "Le titre 3", "L'éditeur 3", "ISB 3", "Public 3", "Etat 3");
    Chaine<Livre> livres = Chaine<Livre>();
    livres.ajoute(livre1);
    livres.ajoute(livre2);
    livres.ajoute(livre3);

    cout << "Création d'une liste d'adhérents..." << endl;
    Chaine<Adherent> adherents = Chaine<Adherent>();

    cout << "Création d'une liste d'emprunts..." << endl;
    Chaine<Emprunt> emprunts = Chaine<Emprunt>();

    cout << "Création d'une liste d'échanges..." << endl;
    Chaine<Echange> echanges = Chaine<Echange>();

    cout << "Création d'une bibliothèque..." << endl;
    Bibliotheque maBibliotheque = Bibliotheque(livres, adherents, emprunts, echanges, NULL, NULL, NULL);
    cout << endl << "Affichage d'un livre :" << endl;
    livre1.affiche();
    cout << endl << "Affichage d'une chaîne de livre :" << endl;
    maBibliotheque.getLivres().affiche();
    cout << "Cette chaîne est de longueur = " << maBibliotheque.getLivres().taille() << endl;

    cout << "On retire un livre..." << endl << endl;
    maBibliotheque.getLivres().enleve(livre3);  // marche très bien avec livre2 et livre1, impossible pour livre3...
    cout << maBibliotheque.getLivres().getPremier();
    cout << endl << endl << "On affiche à nouveau" << endl;
    cout << "Affichage d'une chaîne de livre :" << endl;
    maBibliotheque.getLivres().affiche();

    return 0;
}

