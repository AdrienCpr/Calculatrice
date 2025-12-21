#include <iostream>
using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Puissance.h"

#include "RacineCarre.h"
#include "Inverse.h"
#include "ValeurAbsolue.h"
#include "LogNeperien.h"

int main() {
    Constante c1(20.0f);
    Constante c2(10.0f);
    Constante cNeg(-5.0f);
    Constante c2pow(2.0f);

    Addition add(&c1, &c2);            // (20 + 10)
    Puissance p(&add, &c2pow);         // (20 + 10) ^ 2
    RacineCarree r(&p);                // sqrt( (20+10)^2 )
    Inverse inv(&r);                   // inv( sqrt(...) )

    ValeurAbsolue ab(&cNeg);           // abs(-5)
    LogNeperien ln(&ab);               // ln(abs(-5))

    Multiplication expr(&inv, &ln);    // inv(...) * ln(...)

    cout << "Affichage classique : ";
    expr.afficher_classique(cout);
    cout << endl;

    cout << "Affichage NPI : ";
    expr.afficher_npi(cout);
    cout << endl;

    cout << "Resultat du calcul : " << expr.calculer() << endl;
    return 0;
}
