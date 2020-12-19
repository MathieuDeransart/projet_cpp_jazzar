#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "Création de livres..." << endl;
    Livre livre1 = Livre("L'auteur 1", "Le titre 1", "L'éditeur 1", "ISB 1", "Public 1", "Etat 1");
    Livre livre2 = Livre("L'auteur 2", "Le titre 2", "L'éditeur 2", "ISB 2", "Public 2", "Etat 2");
    Livre livre3 = Livre("L'auteur 3", "Le titre 3", "L'éditeur 3", "ISB 3", "Public 3", "Etat 3");
    Chaine<Livre> livres = Chaine<Livre>();
    livres.ajoute(livre1);
    livres.ajoute(livre2);
    livres.ajoute(livre3);

    cout << "Création d'une bibliothèque et ajout des livres..." << endl;
    Bibliotheque maBibliotheque = Bibliotheque("Au poivre d'âne", "Manosque city");
    maBibliotheque.ajouteLivre(livres);
    cout << endl << "Affichage d'un livre :" << endl;
    livre1.affiche_peu();

    cout << endl << "Affichage d'une chaîne de livre :" << endl;
    maBibliotheque.getLivres().affiche_peu();

    cout << endl << "On retire un livre de la bibliothèque..." << endl;
    maBibliotheque.getLivres().enleve(livre1);
    cout << "Affichage des livres de la bibliothèque :" << endl;
    maBibliotheque.getLivres().affiche_peu();

    cout << endl << "On retire les autres livres de la bibliothèque..." << endl;
    maBibliotheque.getLivres().enleve(livre3);
    maBibliotheque.getLivres().enleve(livre2);
    cout << "Affichage des livres de la bibliothèque :" << endl;
    maBibliotheque.getLivres().affiche_peu();

    return 0;
}

