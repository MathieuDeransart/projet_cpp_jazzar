//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_CHAINE_H
#define PROJET_CHAINE_H
#include <iostream>
#include "Maille.h"
using namespace std;

/*
 * !!!! UTILISER MAJ_PTR_PREMIER !!!!
 * DESCRIPTION :
 *  La classe 'Chaine' permet de faire des chaine de classe implémentant 'getIdentifiant', 'affiche' et 'affiche_peu'.
 * MÉTHODES :
 *  Chaine : initialisation à vide
 *  affiche: appelle la méthode 'affiche' sur tous les éléments des mailles de la chaîne en sautant une ligne entre chaque -> nécessite 'affiche'
 *  affiche_peu : idem sur 'affiche_peu' pour un affichage concis -> nécessite 'affiche_peu'
 *  taille : retourne le nombre de mailles de la chaîne
 *  ajoute : permet d'ajouter un élément au début de la chaîne
 *  recherche_index : retourne l'index (int) de l'élément en argument, ou -1 si il n'existe pas -> nécessite 'getIdentifiant'
 *  [i] : l'operateur est overloaded pour accéder au i-ème élément de la chaine si i € [0, taille()-1]
 *  enleve : enleve l'élément en argument si il est dans la chaine (ne gère pas les doublons) -> nécessite 'getIdentifiant'
 *  maj_ptr_premier : À UTILISER SUR L'OBJET JUSTE APRÈS L'INITIALISATION, PERMET DE RÉGLER LE PROBLÈME D'IMPOSSIBILITÉ DE MODIFIER LE PREMIER ÉLÉMENT
 */


template<typename A>
class Chaine {
private:
    Maille<A> *premier;
    Maille<A> **ptr_premier;
public:
    Chaine();
    void affiche();
    void affiche_peu();
    int taille();
    void ajoute(A &element);
    int recherche_index(A &element_recherche);
    int recherche_index_id(int identifiant);
    A operator[](int i);  // retourne l'élément i
    A* getPointerOfElement(int i);  // retourne le pointeur de l'élément i
    void enleve(A &element_avirer);
    void maj_ptr_premier();
    A* pop(int i);  // même fonction qu'en python, enlève le ième élément et retourne son pointeur
};

template<typename A>
Chaine<A>::Chaine() {
    premier = NULL;
    ptr_premier = &premier;
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
void Chaine<A>::affiche_peu() {
    if (premier) {
        cout << "[";
        premier->affiche_peu();
    }
    else cout << "[Chaine vide]";
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
int Chaine<A>::recherche_index_id(int identifiant) {
    Maille<A> *curseur = premier;
    int index = 0;
    while (curseur){
        if (curseur->getElement().getIdentifiant() == identifiant) return index;
        curseur = curseur->getSuivant();
        index ++;
    }
    return -1;
}

template<typename A>
void Chaine<A>::enleve(A &element_avirer) {
    int index = recherche_index(element_avirer);
    Maille<A> *avirer;
    if (index == 0){
        avirer = premier;
        *ptr_premier = premier->getSuivant();
        delete avirer;
    }
    else if (index > 0){
        Maille<A> *precedent = premier;
        for (int i =0; i < index-1; i++) precedent = precedent->getSuivant();
        avirer = precedent->getSuivant();
        precedent->setSuivant(avirer->getSuivant());
        delete avirer;
    }
    else cout << "No such item here" << endl;
}

template<typename A>
void Chaine<A>::maj_ptr_premier() {
    if (ptr_premier != &premier) ptr_premier = &premier;
    else cout << "Mise à jour de ptr_premier inutile..." << endl;
}

template<typename A>
A Chaine<A>::operator[](int i) {
    if (i < 0 || i >= taille()) return A();
    Maille<A> *curseur = premier;
    for (int j=0; j<i; j++) curseur = curseur->getSuivant();
    return curseur->getElement();
}

template<typename A>
A *Chaine<A>::getPointerOfElement(int i) {
    if (i < 0 || i >= taille()) return nullptr;
    Maille<A> *curseur = premier;
    for (int j=0; j<i; j++) curseur = curseur->getSuivant();
    return curseur->getPointerOfElement();
}

template<typename A>
A* Chaine<A>::pop(int index) {
    Maille<A> *avirer;
    if (index == 0){
        avirer = premier;
        *ptr_premier = premier->getSuivant();
        return avirer->getPointerOfElement();
    }
    else if (index > 0 && index < taille()){
        Maille<A> *precedent = premier;
        for (int i =0; i < index-1; i++) precedent = precedent->getSuivant();
        avirer = precedent->getSuivant();
        precedent->setSuivant(avirer->getSuivant());
        return avirer->getPointerOfElement();
    }
    else {
        cout << "Index out of range" << endl;
        return NULL;
    }
}








template<typename A>
class Chaine<A*> {
private:
    Maille<A*> *premier;
    Maille<A*> **ptr_premier;
public:
    Chaine();
    void affiche();
    void affiche_peu();
    int taille();
    void ajoute(A* &element);
    int recherche_index(A* &element_recherche);
    int recherche_index_id(int identifiant);
    A* operator[](int i);  // retourne l'élément i
    A** getPointerOfElement(int i);  // retourne le pointeur de l'élément i
    void enleve(A* &element_avirer);
    void maj_ptr_premier();
    A** pop(int i);  // même fonction qu'en python, enlève le ième élément et retourne son pointeur
};

template<typename A>
Chaine<A*>::Chaine() {
    premier = NULL;
    ptr_premier = &premier;
}

template<typename A>
void Chaine<A*>::ajoute(A* &element) {
    auto *nouveau = new Maille<A*>(element);
    nouveau->setSuivant(premier);
    premier = nouveau;
}

template<typename A>
void Chaine<A*>::affiche() {
    cout << "Chaîne de taille " << taille() << " :" << endl;
    if (premier) premier->affiche();
    else cout << "Rien à afficher"<< endl;
}

template<typename A>
void Chaine<A*>::affiche_peu() {
    if (premier) {
        cout << "[";
        premier->affiche_peu();
    }
    else cout << "[Chaine vide]";
}

template<typename A>
int Chaine<A*>::taille() {
    if (premier) return premier->taille();
    else return 0;
}

template<typename A>
int Chaine<A*>::recherche_index(A* &element_recherche) {
    Maille<A*> *curseur = premier;
    int index = 0;
    while (curseur){
        if (curseur->getElement()->getIdentifiant() == element_recherche->getIdentifiant()) return index;
        curseur = curseur->getSuivant();
        index ++;
    }
    return -1;
}

template<typename A>
int Chaine<A*>::recherche_index_id(int identifiant) {
    Maille<A*> *curseur = premier;
    int index = 0;
    while (curseur){
        if (curseur->getElement()->getIdentifiant() == identifiant) return index;
        curseur = curseur->getSuivant();
        index ++;
    }
    return -1;
}

template<typename A>
void Chaine<A*>::enleve(A* &element_avirer) {
    int index = recherche_index(element_avirer);
    Maille<A*> *avirer;
    if (index == 0){
        avirer = premier;
        *ptr_premier = premier->getSuivant();
        delete avirer;
    }
    else if (index > 0){
        Maille<A*> *precedent = premier;
        for (int i =0; i < index-1; i++) precedent = precedent->getSuivant();
        avirer = precedent->getSuivant();
        precedent->setSuivant(avirer->getSuivant());
        delete avirer;
    }
    else cout << "No such item here" << endl;
}

template<typename A>
void Chaine<A*>::maj_ptr_premier() {
    if (ptr_premier != &premier) ptr_premier = &premier;
    else cout << "Mise à jour de ptr_premier inutile..." << endl;
}

template<typename A>
A* Chaine<A*>::operator[](int i) {
    if (i < 0 || i >= taille()) return new A();
    Maille<A*> *curseur = premier;
    for (int j=0; j<i; j++) curseur = curseur->getSuivant();
    return curseur->getElement();
}

template<typename A>
A* *Chaine<A*>::getPointerOfElement(int i) {
    if (i < 0 || i >= taille()) return nullptr;
    Maille<A*> *curseur = premier;
    for (int j=0; j<i; j++) curseur = curseur->getSuivant();
    return curseur->getPointerOfElement();
}

template<typename A>
A** Chaine<A*>::pop(int index) {
    Maille<A*> *avirer;
    if (index == 0){
        avirer = premier;
        *ptr_premier = premier->getSuivant();
        return avirer->getPointerOfElement();
    }
    else if (index > 0 && index < taille()){
        Maille<A*> *precedent = premier;
        for (int i =0; i < index-1; i++) precedent = precedent->getSuivant();
        avirer = precedent->getSuivant();
        precedent->setSuivant(avirer->getSuivant());
        return avirer->getPointerOfElement();
    }
    else {
        cout << "Index out of range" << endl;
        return NULL;
    }
}

#endif //PROJET_CHAINE_H
