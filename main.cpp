#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"

int main(void) {
    Constante c1(20.0);

    c1.afficher_classique();
    cout << endl;

    Constante c2(30.0);
    Addition add1(&c1, &c2);

    add1.afficher_classique(cout);
    cout << endl;

    add1.afficher_npi(cout);
    cout << endl;

    Constante c3(34.0);
    Multiplication m1(&c3, &add1);

    m1.afficher_classique(cout);
    cout << endl;

    m1.afficher_npi(cout);
    cout << endl;

    Constante c4(50.0);
    Constante c5(10.0);
    Soustraction s1(&c4, &c5);

    s1.afficher_classique(cout);
    cout << endl;

    s1.afficher_npi(cout);
    cout << endl;

    Division d1(&m1, &c5);

    d1.afficher_classique(cout);
    cout << endl;

    d1.afficher_npi(cout);
    cout << endl;

    return 0;
}

