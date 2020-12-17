//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_CHAINE_H
#define PROJET_CHAINE_H
#include <iostream>
using namespace std;

template<typename A>
class Chaine {
private:
    A element;
    Chaine<A> *suivant = NULL;
public:
    Chaine(A &element);
    virtual ~Chaine();
    A getElement();
    void setElement(A &element);
    Chaine<A>* getSuivant();
    void setSuivant(Chaine<A> *suivant);
    void affiche();
    int longueur();
};

template<typename A>
Chaine<A>::Chaine(A &element) {
    this->setElement(A element)
}

template<typename A>
Chaine<A>::~Chaine() {
    delete element;
}

template<typename A>
A Chaine<A>::getElement() {
    return element;
}

template<typename A>
void Chaine<A>::setElement(A &element) {
    Chaine<A>::element = element;
}

template<typename A>
Chaine<A> *Chaine<A>::getSuivant() {
    return Chaine<A>::suivant;
}

template<typename A>
void Chaine<A>::setSuivant(Chaine<A> *suivant) {
    Chaine<A>::suivant = suivant
}

template<typename A>
void Chaine<A>::affiche() {
    element.affiche()
    if (suivant){
        cout << "-------" << endl;
        suivant->affiche();
    }
}

template<typename A>
int Chaine<A>::longueur() {
    if (suivant) return 1+suivant->longueur();
    else return 1;
}


#endif //PROJET_CHAINE_H
