//
// Created by Deransart on 16/12/2020.
//

#ifndef PROJET_CHAINE_H
#define PROJET_CHAINE_H
#include <iostream>
using namespace std;

// /!\ les éléments de classe A considérés dans la liste doivent posséder une méthode getIdentifiant et affiche /!\
// Une chaine sans éléments n'est pas encore gérée, il faut mettre à jou la fonction 'ajoute'

/* DESCRIPTION :
 *  La classe 'Chaine' permet de faire des chaine de toute classe.
 *  Les méthodes sont :
 *  Chaine : initialisation à vide ou avec un argument
 *  getElement : retourne l'élément de la chaine
 *  getSuivant : retourne la chaine suivante
 *  setSuivant : ...
 *  affiche: appelle la méthode affiche sur tous les éléments de la chaîne en sautant une ligne entre chaque
 *  longueur : retourne le nombre de chaine jusqu'au bout, en comprenant la chaîne d'où est appelée la méthode
 *  ajoute : permet d'ajouter un élément
 *  cherche_index : retourne l'index (int) de l'élément en argument, ou -1 si il n'existe pas
 *  enleve : enleve l'élément en argument si il est dans la chaine (ne gère pas les doublons)
 */

template<typename A>
class Chaine {
private:
    A element;
    Chaine<A> *suivant = NULL;
public:
    Chaine();
    Chaine(A &element);
    //virtual ~Chaine();
    A getElement();
    void setElement(A &element);
    Chaine<A>* getSuivant();
    void setSuivant(Chaine<A> *suivant);
    void affiche();
    int longueur();
    void ajoute(A &element);
    int cherche_index(A &element_recherche, int ne_pas_modifier = 0);
    void enleve(A &element_a_enlever);
};

template<typename A>
Chaine<A>::Chaine() {
    Chaine<A>::element = A();
}

template<typename A>
Chaine<A>::Chaine(A &element) {
    this->setElement(element);
}

/*
template<typename A>
Chaine<A>::~Chaine() {
    delete element;
}
*/

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
    Chaine<A>::suivant = suivant;
}

template<typename A>
void Chaine<A>::affiche() {
    element.affiche();
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

template<typename A>
void Chaine<A>::ajoute(A &element) {
    A premierElement = this->element;
    Chaine<A> *nouveau = new Chaine<A>(premierElement);
    nouveau->setSuivant(this->suivant);
    this->suivant = nouveau;
    this->element = element;
    // dans le cas d'une chaîne vide ?
}

template<typename A>
int Chaine<A>::cherche_index(A &element_recherche, int ne_pas_modifier) {
    if (element_recherche.getIdentifiant() == element.getIdentifiant()) return ne_pas_modifier;
    else if (suivant) suivant->cherche_index(element_recherche, ne_pas_modifier++);
    else return -1;  //on n'a pas trouvé de tel élément
}

template<typename A>
void Chaine<A>::enleve(A &element_a_enlever) {
    int index = this->cherche_index(element_a_enlever);
    if (index != -1){
        int longueur = this->longueur();
        if (index == 0){
            if (longueur == 1){
                element = A();
            }
            else {
                this->element = suivant->element;
                Chaine<A> *avirer = suivant;
                suivant = suivant->suivant;
                delete avirer;
            }
        }
        else{
            //mettre le suivant de i-1 sur le suivant de i et supprimer i -> marche aussi si i est le dernier élément
            Chaine<A> *precedent = this;
            for (int i = 0; i < index; i++) precedent = precedent->suivant;
            Chaine<A> *avirer = precedent->suivant;
            precedent->suivant = avirer->suivant;
            delete avirer;
        }
    }
}


#endif //PROJET_CHAINE_H
