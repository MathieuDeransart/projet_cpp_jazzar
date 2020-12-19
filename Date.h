//
// Created by Deransart on 18/12/2020.
//

#ifndef PROJET_DATE_H
#define PROJET_DATE_H
#include <iostream>


class Date {
private:
    int jour;
    int mois;
    int annee;
    bool checkDate(int j, int m, int a);
    bool isLeapYear(int a);
    bool has30Days(int m);
public:
    Date(int j = 1, int m = 1, int a = 1901);
    void affiche();
    void affiche_peu();
    int getJour() {return jour;}
    int getMois() {return mois;}
    int getAnnee() {return annee;}
    void setAnnee(int annee) {this->annee = annee;}
    void setJour(int jour) {this->jour = jour;}
    void setMois(int mois) {this->mois = mois;}
    void saisie();
};


#endif //PROJET_DATE_H
