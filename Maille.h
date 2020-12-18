//
// Created by Deransart on 17/12/2020.
//

#ifndef PROJET_MAILLE_H
#define PROJET_MAILLE_H
#include <iostream>
using namespace std;

/* DESCRIPTION :
 *  La classe 'Chaine' permet de coder les couples (élément, &mailleSuivante) pour être utilisé dans une chaîne
 * MÉTHODES :
 *  Maille : Initialise une maille avec un élément
 *  get/setElement : setter et getter de l'attribut 'element'
 *  get/setSuivant : setter et getter de l'attribut 'suivant'
 *  affiche : applique la méthode 'affiche' sur l'attribut 'element' puis sur l'attribut 'suivant' si il est non NULL
 *  affiche_peu : idem avec la méthode 'affiche_peu'
 *  taille : retourne 1+suivant->taille() ou 1 si 'suivant' est NULL
 *
 */


template <typename A>
class Maille {
private:
    A element;
    Maille<A> *suivant = NULL;
public:
    Maille();
    Maille(A &element);
    void setElement(A &element);
    A getElement();
    void setSuivant(Maille<A> *suivant);
    Maille<A>* getSuivant();
    void affiche();
    void affiche_peu();
    int taille();

};

template<typename A>
Maille<A>::Maille() {
    Maille<A>::element = nullptr;
}

template<typename A>
Maille<A>::Maille(A &element) {
    Maille<A>::element = element;
}

template<typename A>
void Maille<A>::setElement(A &element) {
    Maille<A>::element = element;
}

template<typename A>
A Maille<A>::getElement() {
    return element;
}

template<typename A>
void Maille<A>::setSuivant(Maille<A> *suivant) {
    Maille<A>::suivant = suivant;
}

template<typename A>
Maille<A> *Maille<A>::getSuivant() {
    return suivant;
}

template<typename A>
void Maille<A>::affiche() {
    element.affiche();
    if (suivant) {
        cout << "-----" << endl;
        suivant->affiche();
    }
}

template<typename A>
int Maille<A>::taille() {
    if (suivant) return 1 + suivant->taille();
    else return 1;
}

template<typename A>
void Maille<A>::affiche_peu() {
    element.affiche_peu();
    if (suivant) {
        cout << "-----" << endl;
        suivant->affiche_peu();
    }
}


#endif //PROJET_MAILLE_H
