#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "Création d'une liste de livres..." << endl;
    Livre livre1 = Livre("Le code 1", "L'auteur 1", "Le titre 1", "L'éditeur 1", "ISB 1", "Public 1", "Etat 1");
    Livre livre2 = Livre("Le code 2", "L'auteur 2", "Le titre 2", "L'éditeur 2", "ISB 2", "Public 2", "Etat 2");
    Chaine<Livre> livres = Chaine<Livre>(livre1);
    livres.ajoute(livre2);

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
    cout << "Cette chaîne est de longueur = " << maBibliotheque.getLivres().longueur() << endl;

    cout << "On retire un livre..." << endl;
    maBibliotheque.getLivres().enleve(livre1);
    cout << "On affiche à nouveau" << endl;
    cout << endl << "Affichage d'une chaîne de livre :" << endl;
    maBibliotheque.getLivres().affiche();

    return 0;
}

