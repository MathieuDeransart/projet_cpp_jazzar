//
// Created by Deransart on 17/12/2020.
//

#ifndef PROJET_MAILLE_H
#define PROJET_MAILLE_H
#include <iostream>
using namespace std;

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


#endif //PROJET_MAILLE_H
