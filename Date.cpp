//
// Created on 18/12/2020.
//

#include "Date.h"
using namespace std;

Date::Date(int j, int m, int a) {
    if (!checkDate(j, m, a)) {
        jour = 1;
        mois = 1;
        annee = 1901;
    } else {
        mois = m;
        jour = j;
        annee = a;
    }
}

void Date::affiche() {
    cout << "jour = " << jour << ", mois = " << mois << ", annee = " << annee
         << endl;
}

void Date::affiche_peu() {
    cout << jour << "/" << mois << "/" << annee;
}

bool Date::checkDate(int j, int m, int a) {
    if ((j < 1) || (j > 30) || (m < 1) || (m > 12) || (a < 1901) || (a > 2021))
        return false;
    return true;
}

void Date::saisie() {
    int a, m, j;
    cout << "Saisie date :" << endl;
    a = 1900;
    while (a < 1901 || a > 2021){
        cout << "Année : "; cin >> a; setAnnee(a);
    }
    m = 0;
    while (m < 1 || m > 12){
        cout << "Mois : "; cin >> m; setAnnee(m);
    }
    j = 0;
    while(j < 1 || (m == 2 && !isLeapYear(a) && j>28) || (m == 2 && isLeapYear(a) && j>29) || (has30Days(m) && j>30) || j>31){
        cout << "Jour : "; cin >> j; setAnnee(j);
    }
}

bool Date::isLeapYear(int a) {
    if (a%4 == 0){
        if (a%400 == 0) return true;
        else if (a%100 == 0) return false;
        else return true;
    }
    return false;
}

bool Date::has30Days(int m) {
    return (m == 4 || m == 6 || m == 9 || m == 11);
}
