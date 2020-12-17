//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_CHAINE_H
#define PROJET_CHAINE_H
#include <iostream>
#include "Maille.h"
using namespace std;

// La suppression du premier élément est actuellement impossible
// Lors de l'appel de la méthode, premier pointe bien vers le second élément, mais le changement n'est pas pris en compte à posteriori

/* DESCRIPTION :
 *  La classe 'Chaine' permet de faire des chaine de classe implémentant 'getIdentifiant' et 'affiche'.
 *  Les méthodes sont :
 *  Chaine : initialisation à vide
 *  affiche: appelle la méthode affiche sur tous les éléments des mailles de la chaîne en sautant une ligne entre chaque
 *  longueur : retourne le nombre de mailles de la chaîne
 *  ajoute : permet d'ajouter un élément au début de la chaîne
 *  cherche_index : retourne l'index (int) de l'élément en argument, ou -1 si il n'existe pas
 *  enleve : enleve l'élément en argument si il est dans la chaine (ne gère pas les doublons)
 */


template<typename A>
class Chaine {
private:
    Maille<A> *premier;
public:
    Chaine();
    void ajoute(A &element);
    void affiche();
    int taille();
    int recherche_index(A &element_recherche);
    void enleve(A &element_avirer);
    Maille<A>* getPremier();
};

template<typename A>
Chaine<A>::Chaine() {
    premier = NULL;
}

template<typename A>
void Chaine<A>::ajoute(A &element) {
    auto *nouveau = new Maille<A>(element);
    nouveau->setSuivant(premier);
    premier = nouveau;
}

template<typename A>
void Chaine<A>::affiche() {
    cout << "Chaîne de taille " << taille() << " :" << endl;
    if (premier) premier->affiche();
    else cout << "Rien à afficher"<< endl;
}

template<typename A>
int Chaine<A>::taille() {
    if (premier) return premier->taille();
    else return 0;
}

template<typename A>
int Chaine<A>::recherche_index(A &element_recherche) {
    Maille<A> *curseur = premier;
    int index = 0;
    while (curseur){
        if (curseur->getElement().getIdentifiant() == element_recherche.getIdentifiant()) return index;
        curseur = curseur->getSuivant();
        index ++;
    }
    return -1;
}

template<typename A>
void Chaine<A>::enleve(A &element_avirer) {
    cout << "Recherche de l'index" << endl;
    int index = recherche_index(element_avirer);
    cout << "Index obtenu : " << index << endl;
    Maille<A> *avirer;
    if (index == 0){
        cout << "If" << endl;
        cout << premier << " -- " << premier->getSuivant() << endl;
        avirer = premier;
        premier = premier->getSuivant();
        cout << premier << " -- " << avirer << endl;
        //delete avirer;
    }
    else if (index > 0){
        cout << "Else if" << endl;
        Maille<A> *precedent = premier;
        for (int i =0; i < index-1; i++) precedent = precedent->getSuivant();
        avirer = precedent->getSuivant();
        precedent->setSuivant(avirer->getSuivant());
        delete avirer;
    }
    else cout << "No such item here" << endl;
    cout << premier << "  " << taille() << endl;
}

template<typename A>
Maille<A> *Chaine<A>::getPremier() {
    return premier;
}



#endif //PROJET_CHAINE_H
