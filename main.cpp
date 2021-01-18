#include "Bibliotheque.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/*
 * La seule fonction qui sera définie ici sera celle permettant de sauveagarder l'environnement
 * de travail et de retourner la chaine de caractère représentant la sauvegarde.
 */

string sauvegarde_environnement(Chaine<Bibliotheque*> bibliotheques) {
    string save;
    save += "<nombreLivre>"+to_string(Livre::getNombreLivre())+"</nombreLivre>\n";
    save += "<nombre_adherent>"+to_string(Adherent::getNombreAdherent())+"</nombre_adherent>\n";
    for (int i=0; i<bibliotheques.taille(); i++) {
        save += bibliotheques[i]->generateSave(0, "    ", "\n") + "\n";
    }

    string path = "/Users/mathieu/Documents/Scolarité/Semestre 7/E1_PRO/TP/projet_cpp_jazzar/save.txt";
    ofstream fichier(path, ios::out | ios::trunc);
    if (fichier) {
        cout << "*Fichier ouvert, écriture..." << endl;
        fichier << save;
        fichier.close();
    } else
        cerr << "*Erreur à l'ouverture ! Mettre le chemin à jour si vous voulez testez la sauvegarde" << endl;
    return save;
}


int main() {
    cout << "\n%% Projet final de l'électif Programmation Objet en C++\n%% Travail de Agator Joris et Deransart Mathieu\n\n" << endl;

    /*
     * Toutes les méthodes utilisées dans le main que nous avons créées sont documentées dans les header des classes
     * correspondantes.
     */

    cout << R"(Pour faire tourner les tests "t", pour essayer de charger l'environnement depuis le fichier de sauvegarde "c")" << endl;
    string choix;
    cout << "Taper votre choix :"; cin >> choix;
    //choix = "c";

    if (choix == "t") {
        cout << "  ----- Créations des objets et affichage -----\n\n";
        cout << "*Création de livres..." << endl;
        Livre livre1 = Livre("L'auteur 1", "Le titre 1", "L'éditeur", "ISBN1", "Public");
        Livre livre2 = Livre("L'auteur 2", "Le titre 2", "L'éditeur", "ISBN2", "Public");
        Livre livre3 = Livre("L'auteur 3", "Le titre 3", "L'éditeur", "ISBN3", "Public");
        Livre livre4 = Livre("L'auteur 4", "Le titre 4", "L'éditeur", "ISBN4", "Public");
        Livre livre5 = Livre("L'auteur 5", "Le titre 5", "L'éditeur", "ISBN5", "Public");
        Livre livre6 = Livre("L'auteur 6", "Le titre 6", "L'éditeur", "ISBN6", "Public");
        Roman roman1 = Roman("Andrzej Sapkowski", "Le sorceleur 7 : La dame du lac", "Bragelonne", "978-2811208721", "Public", "libre","Roman fantastique");
        Roman roman2 = Roman("J.R.R. Tolkien", "Le seigneur des anneaux 1 : La communauté de l'anneau", "Pocket", "2266026550", "Public", "libre", "Roman fantasy");
        Bandedessinee BD = Bandedessinee("Goscinny", "Astérix le Gaulois", "Hachette", "9782012100015", "Public", "libre", "Uderzo");
        Theatre piece = Theatre("Molière", "L'Avare", "Belin - Gallimard", "9782701175980", "Public", "libre", 17);
        Poesie recueil = Poesie("Victor Hugo", "Les contemplation", "Le livre de poche", "2253014990", "Public", "libre", "Vers");
        Album album = Album("Photographe1", "Mon album photo", "Mes éditions", "ISBN7", "Public", "libre", "Photos");
        Chaine<Livre> livres1 = Chaine<Livre>();
        livres1.ajoute(livre1);
        livres1.ajoute(livre2);
        livres1.ajoute(livre3);
        Chaine<Livre> livres2 = Chaine<Livre>();
        livres2.ajoute(livre4);
        livres2.ajoute(livre5);
        livres2.ajoute(livre6);

        cout << "*Création de bibliothèques et ajout des livres..." << endl;
        Chaine<Bibliotheque *> bibliotheques = Chaine<Bibliotheque *>();
        auto *bibliotheque1 = new Bibliotheque("Au poivre d'âne", "Manosque city");
        auto *bibliotheque2 = new Bibliotheque("Grande Bibliotheque", "Marseille");
        bibliotheques.ajoute(bibliotheque2);
        bibliotheques.ajoute(bibliotheque1);
        bibliotheques[0]->achat(livres1);  // on peut ajouter une liste de livre
        bibliotheques[1]->achat(livre4);  // ou les livres un par un
        bibliotheques[1]->achat(livre5);
        bibliotheques[1]->achat(livre6);

        cout << endl << "*Affichage d'un livre (méthode \"affiche_peu\") :" << endl;
        livre1.affiche_peu();
        cout << endl;  // "affiche_peu" permet d'avoir les informations essentielles
        cout << "*Affichage d'un livre (méthode \"affiche\") :" << endl;
        livre1.affiche();  // "affiche" permet d'afficher toutes les informations en détail

        cout << "*Affichage d'une chaîne de livre :" << endl;
        livres1.affiche_peu();
        cout << endl;  // les deux fonctions d'affichages sont implémentées sur tous nos objets



        cout << "\n\n  ----- Manipulation des livres -----\n\n";

        cout << "*On retire un livre de la bibliothèque 1..." << endl;
        bibliotheques[0]->getLivres().enleve(livre1);
        cout << "*Affichage des livres de la bibliothèque 1 :" << endl;
        bibliotheques[0]->getLivres().affiche_peu();
        cout << endl;

        cout << "*On retire les autres livres de la bibliothèque 1 ..." << endl;
        bibliotheques[0]->getLivres().enleve(livre3);
        bibliotheques[0]->getLivres().enleve(livre2);
        cout << "*Affichage des livres de la bibliothèque 1 :" << endl;
        bibliotheques[0]->getLivres().affiche_peu();
        cout << endl;

        cout << "*On remet les mêmes livres dans la bibliotheque 1..." << endl;
        bibliotheques[0]->achat(livres1);
        cout << "*On crée un adhérent..." << endl;
        int id_maurice = bibliotheques[0]->addAdherent("Maurice", "Barnabé", "St Hilaire");
        cout << "*Nouvel adhérent créé avec succés, avec l'id : " << to_string(id_maurice) << endl;
        cout << "*On lui fait emprunter le livre ";
        bibliotheques[0]->getLivres()[1].affiche_peu();
        cout << "..." << endl;
        bibliotheques[0]->adherent(id_maurice)->emprunter(bibliotheques[0]->getLivres()[1].getIdentifiant());
        cout << "*Et on l'affiche :" << endl;
        bibliotheques[0]->adherent(id_maurice)->affiche_peu();
        cout << endl;
        cout << "*On vérifie alors l'État du livre dans la bibliothèque (il doit être \"emprunté\"):" << endl;
        bibliotheques[0]->getLivres()[1].affiche();
        cout << "*On rend le livre..." << endl;
        bibliotheques[0]->adherent(id_maurice)->rendre(0);
        cout
                << "*Et on affiche comme avant (il doit être \"libre\" dans la bibliotheque et ne plus apparaitre dans les emprunts):"
                << endl;
        bibliotheques[0]->adherent(id_maurice)->affiche_peu();
        cout << endl;
        bibliotheques[0]->getLivres()[1].affiche();


        cout << "\n\n  ----- Gestion des pertes et mise au pilon -----\n\n";


        bibliotheques[0]->adherent(id_maurice)->emprunter(bibliotheques[0]->getLivres()[0]);
        cout << "Livres de la bibliotheque 1 : "; bibliotheques[0]->getLivres().affiche_peu(); cout << endl;
        cout << "Livres de l'adherent : "; bibliotheques[0]->adherent(id_maurice)->affiche_peu(); cout << endl;
        cout << "Le livre est perdu par l'adhérent..." << endl;
        bibliotheques[0]->perte(bibliotheques[0]->adherent(id_maurice)->getLivreEmpruntes()[0], bibliotheques[0]->adherent(id_maurice));
        cout << "Livres de la bibliotheque 1 : "; bibliotheques[0]->getLivres().affiche_peu(); cout << endl;
        cout << "Livres de l'adherent : "; bibliotheques[0]->adherent(id_maurice)->affiche_peu(); cout << endl;
        cout << "Un livre est mis au pilon par la bibliotheque..." << endl;
        bibliotheques[0]->miseAuPilon(bibliotheques[0]->getPtrLivres()->getPointerOfElement(0));
        cout << "Livres de la bibliotheque 1 : "; bibliotheques[0]->getLivres().affiche_peu(); cout << endl;
        cout << "Livres de l'adherent : "; bibliotheques[0]->adherent(id_maurice)->affiche_peu(); cout << endl;
        cout << "On remet les livres enlevés dans la bibliotheque pour la suite des tests...\n";
        bibliotheques[0]->achat(livre1); bibliotheques[0]->achat(livre2);
        cout << "Livres de la bibliotheque 1 : "; bibliotheques[0]->getLivres().affiche_peu(); cout << endl;



        cout << "\n\n  ----- Gestion des prêts entre bibliothèques -----\n\n";

        cout << "*La bibliotheque 1 emprunte le livre de isbn \"ISBN4\", \"ISBN5\" et \"ISBN6\" à la bibliotheque 2..."
             << endl;
        cout << "*La bibliotheque 2 emprunte le livre de isbn \"ISBN1\" à la bibliotheque 1..." << endl;
        bibliotheques[0]->emprunte("ISBN4", bibliotheques[1]);
        bibliotheques[0]->emprunte("ISBN5", bibliotheques[1]);
        bibliotheques[0]->emprunte("ISBN6", bibliotheques[1]);
        bibliotheques[1]->emprunte("ISBN1", bibliotheques[0]);
        cout << "*Emprunt du livre6 par l'adherent et essai d'emprunt du livre1 pourtant prêté à bibliotheque2..."
             << endl;
        bibliotheques[0]->adherent(id_maurice)->emprunter(bibliotheques[0]->getLivres()[0].getIdentifiant());
        bibliotheques[0]->adherent(id_maurice)->emprunter(bibliotheques[0]->getLivres()[3].getIdentifiant());
        cout << "*Affichage de l'adhérent : ";
        bibliotheques[0]->adherent(id_maurice)->affiche_peu();
        cout << endl;
        cout << "*La bibliotheque essaie de rendre ses livres empruntés..." << endl;
        cout << "\n*Affichage des livres avant : ";

        cout << "\n";
        cout << " Bibliothèque 1:" << endl;
        for (int i = 0; i < bibliotheques[0]->getLivres().taille(); i++) {
            bibliotheques[0]->getLivres()[i].affiche_peu();
            cout << " -- Sa provenance : " << bibliotheques[0]->getLivres()[i].getProvenance();
            cout << " -- Son état : " << bibliotheques[0]->getLivres()[i].getEtat();
            cout << endl;
        }
        cout << " Bibliothèque 2:" << endl;
        for (int i = 0; i < bibliotheques[1]->getLivres().taille(); i++) {
            bibliotheques[1]->getLivres()[i].affiche_peu();
            cout << " -- Sa provenance : " << bibliotheques[1]->getLivres()[i].getProvenance();
            cout << " -- Son état : " << bibliotheques[1]->getLivres()[i].getEtat();
            cout << endl;
        }
        cout << "\n";

        cout << "*Les livres 4 et 5 doivent quitter la bibliothèque 1"
                "\n* et de nouveau être marqués comme \"libre\" dans la bibliothèque 2..." << endl;
        bibliotheques[0]->rendEmprunts();
        cout << "*Affichage des livres après : ";
        cout << "\n\n";
        cout << " Bibliothèque 1:" << endl;
        for (int i = 0; i < bibliotheques[0]->getLivres().taille(); i++) {
            bibliotheques[0]->getLivres()[i].affiche_peu();
            cout << " -- Sa provenance : " << bibliotheques[0]->getLivres()[i].getProvenance();
            cout << " -- Son état : " << bibliotheques[0]->getLivres()[i].getEtat();
            cout << endl;
        }
        cout << " Bibliothèque 2:" << endl;
        for (int i = 0; i < bibliotheques[1]->getLivres().taille(); i++) {
            bibliotheques[1]->getLivres()[i].affiche_peu();
            cout << " -- Sa provenance : " << bibliotheques[1]->getLivres()[i].getProvenance();
            cout << " -- Son état : " << bibliotheques[1]->getLivres()[i].getEtat();
            cout << endl;
        }

        roman1.affiche();
        roman2.affiche();
        BD.affiche();
        piece.affiche();
        album.affiche();
        recueil.affiche();



        cout << "\n\n  ----- Sauvegarde de l'environnement de travail -----\n\n";

        cout << "*Enregistrement dans un fichier..." << endl;
        string save = sauvegarde_environnement(bibliotheques);
        cout << "*Résultat de la sauvegarde :" << endl << save << endl;
    }




    // GESTION DE LA SAUVEGARDE
    else if (choix == "c") {
        ifstream fichier("/Users/mathieu/Documents/Scolarité/Semestre 7/E1_PRO/TP/projet_cpp_jazzar/save.txt", ios::in);  // on ouvre le fichier en lecture

        if(fichier)  // si l'ouverture a réussi
        {
            string save;
            string buffer;
            while (getline(fichier, buffer)){
                save += buffer + "\n";
            }
            fichier.close();  // on ferme le fichier

            cout << "*LECTURE DE LA SAVE :" << endl;
            cout << save << endl;

            cout << "*CHARGEMENT DE LA SAVE...\n" << endl;
            Chaine<Bibliotheque*> bibliotheques;
            bibliotheques = Bibliotheque::loadSave(save);

            cout << "*TEST DE LA CONFORMITÉ DE LA SAVE..." << endl;
            cout << "*Les bibliotheques enregistrées sont : ";
            bibliotheques.affiche_peu(); cout << endl;
            for (int i=0; i<bibliotheques.taille(); i++) {
                cout << "*Vérification de \""; bibliotheques[i]->affiche_peu(); cout << "\" :\n";
                cout << "Livres enregistrés :"; bibliotheques[i]->getPtrLivres()->affiche_peu(); cout << endl;
                cout << "Adhérents :"; bibliotheques[i]->Adherents()->affiche_peu(); cout << endl;
            }
            cout << "Nombre d'adhérents :" << Adherent::getNombreAdherent() << endl;
            cout << "Nombre de livre :" << Livre::getNombreLivre() << endl;

            // COMMANDES INTERACTIVES ?
            cout << "\nOn peut rajouter des commandes interactives ici et enregister ensuite la session." << endl;

            map<string, int> d;
            d["end"] = 0;
            d["begin"] = 1;
            d["bibliotheque"] = 2;
            d["achat"] = 3;
            d["pilon"] = 4;
            d["selection_adherents"] = 5;
            d["newAdherent"] = 6;
            d["emprunt_bibliotheque"] = 7;
            d["adherent"] = 8;
            d["emprunt_adherent"] = 9;
            d["nouvelle_bibliotheque"] = 10;
            string menu = "begin";
            string buffer_s;
            int buffer_i;
            Bibliotheque* curseur_biblio;
            Bibliotheque* curseur_biblio2;
            Adherent* curseur_adherent;
            cout << "\n\n /!\\ ATTENTION QUELQUES RÈGLES :\n* NE PAS METTRE DE MAJUSCULE DANS CE QUE VOUS RENTREZ DANS LE PROGRAMME."
                    "\n* SI UN NOMBRE EST DEMANDÉ, NE PAS RENTRER AUTRE CHOSE.";
            while (d[menu]>0) {
                switch(d[menu])
                {
                    case 1: { // begin
                        cout << "\n\nMenu : démarrage\n";
                        cout << "Liste des bibliotheques : ";
                        bibliotheques.affiche_peu();
                        cout << endl;
                        cout << "Liste des index : [0, 1, ... , n-1]\n";
                        cout << "Entrez un indice valide pour selectionner une bibliotheque, le numéro=n pour en créer une nouvelle, ou autre pour quitter : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        if (buffer_i >= 0 && buffer_i < bibliotheques.taille()) {
                            curseur_biblio = bibliotheques[buffer_i];
                            menu = "bibliotheque";
                        }
                        else if (buffer_i == bibliotheques.taille()) {
                            menu = "nouvelle_bibliotheque";
                        }
                        else menu = "end";
                        break;
                    }

                    case 2: { // bibliotheque
                        cout << "\n\nMenu : bibliothèques\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        cout << "Livres de la bibliotheques : "; curseur_biblio->getLivres().affiche_peu(); cout << endl;
                        cout << "Liste des adherents : "; curseur_biblio->Adherents()->affiche_peu(); cout << endl;
                        cout << "Actions possibles :\n0 : Acheter un nouveau livre\n1 : Mettre au pilon un livre"
                                "\n2 : Sélectionner un adhérent\n3 : Nouvel adhérent\n4 : Emprunter à une autre bibliothèque\n5 : Rendre les livres aux bibliothèques\n";
                        cout
                                << "Entrez un indice valide pour selectionner une action, ou autre pour revenir en arrière : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        if (buffer_i == 0) menu = "achat";
                        else if (buffer_i == 1) menu = "pilon";
                        else if (buffer_i == 2) menu = "selection_adherents";
                        else if (buffer_i == 3) menu = "newAdherent";
                        else if (buffer_i == 4) menu = "emprunt_bibliotheque";
                        else if (buffer_i == 5) curseur_biblio->rendEmprunts();
                        else menu = "begin";
                        break;
                    }

                    case 3: { // achat
                        cout << "\n\nMenu : bibliothèques/achat\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        auto newLivre = new Livre();
                        newLivre->saisieLivre();
                        curseur_biblio->achat(*newLivre);
                        delete newLivre;
                        menu = "bibliotheque";
                        break;
                    }

                    case 4: { // pilon
                        cout << "\n\nMenu : bibliothèques/mise_au_pilon\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        cout << "Liste des livres"; curseur_biblio->getLivres().affiche_peu(); cout << endl;
                        cout << "Entrez un indice valide pour selectionner un livre à jeter : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        if (buffer_i >= 0 && buffer_i < curseur_biblio->getLivres().taille()) {
                            curseur_biblio->miseAuPilon(curseur_biblio->getPtrLivres()->getPointerOfElement(buffer_i));
                            cout << "Mise au pilon faite.\n";
                            menu = "bibliotheque";
                        } else {
                            cout << "Mise au pilon faite impossible (index out of range).\n";
                            menu = "bibliotheque";
                        }
                        break;
                    }

                    case 5: { //selection_adherents
                        cout << "\n\nMenu : bibliothèques/selection_adherent\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        cout << "Liste des adherents : "; curseur_biblio->Adherents()->affiche_peu(); cout << endl;
                        cout << "Entrez un indice valide pour selectionner un adherent : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        if (buffer_i >= 0 && buffer_i < curseur_biblio->Adherents()->taille()) {
                            curseur_adherent = curseur_biblio->Adherents()->operator[](buffer_i);
                            menu = "adherent";
                        }
                        else {
                            cout << "Index out of range, retour à la bibliothèque...";
                            menu = "bibliotheque";
                        }
                        break;
                    }

                    case 6: { //newAdherent
                        cout << "\n\nMenu : bibliothèques/nouvel_adherent\n";
                        cout << "Création d'un nouvel adhérent...";
                        curseur_biblio->addAdherent();
                        menu = "bibliotheque";
                        break;
                    }

                    case 7: { // emprunt_bibliotheque
                        cout << "\n\nMenu : bibliothèques/emprunt_bibliotheque\n";
                        cout << "Liste des bibliotheques : "; bibliotheques.affiche_peu(); cout << endl;
                        cout << "Sélectionnez une deuxième bibliothèque par son indice : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);

                        if (buffer_i >= 0 && buffer_i <= bibliotheques.taille()) {
                            if (curseur_biblio == bibliotheques[buffer_i]) {
                                cout << "Vous ne pouvez pas emprunter à la même bibliothèque...\n";
                                menu = "bibliotheque";
                            }
                            else {
                                curseur_biblio2 = bibliotheques[buffer_i];
                                cout << "Livres disponibles :\n";
                                for (int i = 0; i <curseur_biblio2->getPtrLivres()->taille(); i++) {
                                    if (curseur_biblio2->getPtrLivres()->getPointerOfElement(i)->getEtat()=="libre") {
                                        curseur_biblio2->getPtrLivres()->getPointerOfElement(i)->affiche_peu();
                                        cout << " Isbn : '" << curseur_biblio2->getPtrLivres()->getPointerOfElement(i)->getEtat() << "'\n";
                                    }
                                }
                                cout << "Spécifiez l'Isbn du livre à emprunter : ";
                                cin >> buffer_s;
                                curseur_biblio->emprunte(buffer_s, curseur_biblio2);
                                cout << "Si l'emprunt est possible, l'emprunt a été fait.\n";
                                menu = "bibliotheque";
                            }
                        }
                        else {
                            cout << "Index out of range, retour à la bibliotheque.\n";
                            menu = "bibliotheque";
                        }
                    }

                    case 8: { // adherent
                        cout << "\n\nMenu : bibliothèques/adherent\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        cout << "Adhérent considéré : "; curseur_adherent->affiche_peu(); cout << endl;
                        cout << "Actions possible :\n0 : Emprunter un livre\n1 : Rendre tous les livres\n";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        if (buffer_i == 1) {
                            curseur_adherent->rendreTout();
                            cout << "Restitution des livres.\n";
                        }
                        else if (buffer_i == 0) {
                            menu = "emprunt_adherent";
                        }
                        else {
                            cout << "Retour à la bibliothèque.\n";
                            menu = "bibliotheque";
                        }
                        break;
                    }

                    case 9: { // emprunt_adherent
                        cout << "\n\nMenu : bibliothèques/adherent/emprunt\n";
                        cout << "Bibliothèque considérée : "; curseur_biblio->affiche_peu(); cout << endl;
                        cout << "Adhérent considéré : "; curseur_adherent->affiche_peu(); cout << endl;
                        cout << "Livres disponibles :\n";
                        for (int i = 0; i <curseur_biblio->getPtrLivres()->taille(); i++) {
                            if (curseur_biblio->getPtrLivres()->getPointerOfElement(i)->getEtat()=="libre") {
                                curseur_biblio->getPtrLivres()->getPointerOfElement(i)->affiche_peu();
                                cout << " Code : '" << curseur_biblio->getPtrLivres()->getPointerOfElement(i)->getIdentifiant() << "'\n";
                            }
                        }
                        cout << "Entrez un code valide pour emprunter un livre : ";
                        cin >> buffer_s;
                        buffer_i = stoi(buffer_s);
                        curseur_adherent->emprunter(buffer_i);
                        menu = "adherent";
                        break;
                    }
                    case 10: { // nouvelle_bibliotheque
                        curseur_biblio = new Bibliotheque();
                        bibliotheques.ajoute(curseur_biblio);
                        menu = "bibliotheque";
                        break;
                    }
                    default: { // erreur, redirection vers begin
                        cout << "Ce menu n'existe pas, ou un problème est survenu.\nRetour au début...\n";
                        menu = "begin";
                        break;
                    }

                }
            }

            // SAUVEGARDE DE L'ENVIRONNEMENT DE TRAVAIL si on a fait des commandes interactives
            cout << "\n\n*Enregistrement dans un fichier..." << endl;
            save = sauvegarde_environnement(bibliotheques);
            cout << "*Résultat de la sauvegarde :" << endl << save << endl;
        }
        else
            cerr << "Impossible d'ouvrir le fichier ! Mettre le chemin à jour si vous voulez testez la sauvegarde" << endl;
    }
    return 0;
}

