//
// Created on 16/12/2020.
//

#ifndef PROJET_ADHERENT_H
#define PROJET_ADHERENT_H
#include "Chaine.h"
class Bibliotheque;
#include "Livre.h"
#include <string>
#include <map>
using namespace std;




class Adherent {
private:
    int numero_adherent;  // /!\ sert d'identifiant pour la classe adherent
    string nom;
    string prenom;
    string adresse;
    Bibliotheque *bibliotheque;
    Chaine<Livre *> livre_empruntes;
    int nombreLivreMax;
    static int nombre_adherent;
public:
    Adherent();
    Adherent(Bibliotheque *bibliotheque);
    Adherent(string nom, string prenom, string adresse, Bibliotheque *bibliotheque);
    Adherent(string sub_save, map<int, Bibliotheque*> id_to_bb, map<int, Livre*> id_to_livre);
    void affiche();
    void affiche_peu();
    void saisie_adherent();
    void emprunter(int codeLivre);
    void emprunter(Livre livre);
    void rendre(int i);
    void rendreTout();
    string generateSave(int indentation = 0, string ind_type = "  ", string separator = "\n");
    static void loadSave(string save, map<int, Bibliotheque*> id_to_bb, map<int, Livre*> id_to_livre);

    int getIdentifiant() {return numero_adherent;};
    const string &getNom() const {return nom;};
    void setNom(const string &nom) {Adherent::nom = nom;};
    const string &getPrenom() const {return prenom;};
    void setPrenom(const string &prenom) {Adherent::prenom = prenom;};
    const string &getAdresse() const {return adresse;};
    void setAdresse(const string &adresse) {Adherent::adresse = adresse;};
    Bibliotheque *getBibliotheque() const {return bibliotheque;};
    void setBibliotheque(Bibliotheque *bibliotheque) {Adherent::bibliotheque = bibliotheque;};
    Chaine<Livre *> getLivreEmpruntes() {return livre_empruntes;};
    void setLivreEmpruntes(const Chaine<Livre *> &livreEmpruntes) {livre_empruntes = livreEmpruntes;};
    int getNombreLivreMax() const {return nombreLivreMax;};
    void setNombreLivreMax(int nombreLivreMax) {Adherent::nombreLivreMax = nombreLivreMax;};
    static int getNombreAdherent() {return nombre_adherent;};
    static void setNombreAdherent(int nombre_adherent) {Adherent::nombre_adherent=nombre_adherent;};
};


#endif //PROJET_ADHERENT_H
