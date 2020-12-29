#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\nProjet final de l'électif Programmation Objet en C++\nTravail de Agator Joris et Deransart Mathieu\n" << endl;

    /*
     * Toutes les méthodes utilisées dans le main que nous avons créées sont documentées dans les header des classes
     * correspondantes.
     */

    cout << "Création de livres..." << endl;
    Livre livre1 = Livre("L'auteur 1", "Le titre 1", "L'éditeur", "ISBN1", "Public");
    Livre livre2 = Livre("L'auteur 2", "Le titre 2", "L'éditeur", "ISBN2", "Public");
    Livre livre3 = Livre("L'auteur 3", "Le titre 3", "L'éditeur", "ISBN3", "Public");
    Livre livre4 = Livre("L'auteur 4", "Le titre 4", "L'éditeur", "ISBN4", "Public");
    Livre livre5 = Livre("L'auteur 5", "Le titre 5", "L'éditeur", "ISBN5", "Public");
    Livre livre6 = Livre("L'auteur 6", "Le titre 6", "L'éditeur", "ISBN6", "Public");
    Chaine<Livre> livres1 = Chaine<Livre>();
    livres1.ajoute(livre1);
    livres1.ajoute(livre2);
    livres1.ajoute(livre3);
    Chaine<Livre> livres2 = Chaine<Livre>();
    livres2.ajoute(livre4);
    livres2.ajoute(livre5);
    livres2.ajoute(livre6);

    cout << "Création de bibliothèques et ajout des livres..." << endl;
    Bibliotheque bibliotheque1 = Bibliotheque("Au poivre d'âne", "Manosque city");
    Bibliotheque bibliotheque2 = Bibliotheque("Grande Bibliotheque", "Marseille");
    bibliotheque1.ajouteLivre(livres1);  // on peut ajouter une liste de livre
    bibliotheque2.ajouteLivre(livre4);  // ou les livres un par un
    bibliotheque2.ajouteLivre(livre5);
    bibliotheque2.ajouteLivre(livre6);


    cout << endl << "Affichage d'un livre (méthode \"affiche_peu\") :" << endl;
    livre1.affiche_peu(); cout << endl;  // "affiche_peu" permet d'avoir les informations essentielles
    cout << "Affichage d'un livre (méthode \"affiche\") :" << endl;
    livre1.affiche();  // "affiche" permet d'afficher toutes les informations en détail

    cout << "Affichage d'une chaîne de livre :" << endl;
    livres1.affiche_peu(); cout << endl;  // les deux fonctions d'affichages sont implémentées sur tous nos objets

    cout << endl << "On retire un livre de la bibliothèque 1..." << endl;
    bibliotheque1.getLivres().enleve(livre1);
    cout << "Affichage des livres de la bibliothèque 1 :" << endl;
    bibliotheque1.getLivres().affiche_peu(); cout << endl;

    cout << "On retire les autres livres de la bibliothèque 1 ..." << endl;
    bibliotheque1.getLivres().enleve(livre3);
    bibliotheque1.getLivres().enleve(livre2);
    cout << "Affichage des livres de la bibliothèque 1 :" << endl;
    bibliotheque1.getLivres().affiche_peu(); cout << endl;

    cout << "On remet les mêmes livres dans la bibliotheque 1..." << endl;
    bibliotheque1.ajouteLivre(livres1);
    cout << "On crée un adhérent..." << endl;
    Adherent maurice = Adherent("Maurice", "Barnabé", "St Hilaire", &bibliotheque1);
    cout << "On lui fait emprunter le livre "; bibliotheque1.getLivres()[1].affiche_peu(); cout << "..." << endl;
    maurice.emprunter(bibliotheque1.getLivres()[1].getIdentifiant());
    cout << "Et on l'affiche :" << endl;
    maurice.affiche_peu(); cout << endl;
    cout << "On vérifie alors l'État du livre dans la bibliothèque (il doit être \"emprunté\"):" << endl;
    bibliotheque1.getLivres()[1].affiche();
    cout << " On rend le livre..." << endl;
    maurice.rendre(0);
    cout << "Et on affiche comme avant (il doit être \"libre\" dans la bibliotheque):" << endl;
    maurice.affiche_peu();
    bibliotheque1.getLivres()[1].affiche();


    cout << endl << "La bibliotheque 1 emprunte le livre de isbn \"ISBN4\", \"ISBN5\" et \"ISBN6\" à la bibliotheque 2..." << endl;
    cout << "La bibliotheque 2 emprunte le livre de isbn \"ISBN1\" à la bibliotheque 2..." << endl;
    bibliotheque1.emprunte("ISBN4", &bibliotheque2);
    bibliotheque1.emprunte("ISBN5", &bibliotheque2);
    bibliotheque1.emprunte("ISBN6", &bibliotheque2);
    bibliotheque2.emprunte("ISBN1", &bibliotheque1);
    cout << "Emprunt du livre6 par l'adherent et essai d'emprunt du livre1 pourtant prêté à bibliotheque2..." << endl;
    maurice.emprunter(bibliotheque1.getLivres()[0].getIdentifiant());  // le livre6 qui a été emprunté
    maurice.emprunter(bibliotheque1.getLivres()[3].getIdentifiant());  // le livre1 qui est déjà prêté
    cout << "Affichage de l'adhérent : "; maurice.affiche_peu(); cout << endl;
    cout << "La bibliotheque essaie de rendre ses livres empruntés..." << endl;
    cout << "\nAffichage des livres avant : ";

    cout << "\n";
    cout << " Bibliothèque 1:" << endl;
    for (int i=0; i < bibliotheque1.getLivres().taille(); i++){
        bibliotheque1.getLivres()[i].affiche_peu();
        cout << " -- Sa provenance : " << bibliotheque1.getLivres()[i].getProvenance();
        cout << " -- Son état : " << bibliotheque1.getLivres()[i].getEtat();
        cout << endl;
    }
    cout << " Bibliothèque 2:" << endl;
    for (int i=0; i < bibliotheque2.getLivres().taille(); i++){
        bibliotheque2.getLivres()[i].affiche_peu();
        cout << " -- Sa provenance : " << bibliotheque2.getLivres()[i].getProvenance();
        cout << " -- Son état : " << bibliotheque2.getLivres()[i].getEtat();
        cout << endl;
    }
    cout << "\n";

    cout << "Les livres 4 et 5 doivent quitter la bibliothèque 1"
            "\n et de nouveau être marqués comme \"libre\" dans la bibliothèque 2..." << endl;
    bibliotheque1.rendEmprunts();
    cout << "Affichage des livres après : ";
    cout << "\n\n";
    cout << " Bibliothèque 1:" << endl;
    for (int i=0; i < bibliotheque1.getLivres().taille(); i++){
        bibliotheque1.getLivres()[i].affiche_peu();
        cout << " -- Sa provenance : " << bibliotheque1.getLivres()[i].getProvenance();
        cout << " -- Son état : " << bibliotheque1.getLivres()[i].getEtat();
        cout << endl;
    }
    cout << " Bibliothèque 2:" << endl;
    for (int i=0; i < bibliotheque2.getLivres().taille(); i++){
        bibliotheque2.getLivres()[i].affiche_peu();
        cout << " -- Sa provenance : " << bibliotheque2.getLivres()[i].getProvenance();
        cout << " -- Son état : " << bibliotheque2.getLivres()[i].getEtat();
        cout << endl;
    }
    cout << "\n";

    livre1.sauvegarder(1);
    bibliotheque2.getLivres()[0].sauvegarder(0, "", ";");

    maurice.sauvegarder();

    return 0;
}

