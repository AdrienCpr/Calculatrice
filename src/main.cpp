#include <iostream>
using namespace std;

#include "Variable.h"

int main(void)
{
    Variable x("x");      // création de la variable x
    x.SetValeur(3.0f);    // affectation

    cout << "Affichage classique : ";
    x.afficher_classique(cout);
    cout << endl;

    cout << "Affichage NPI       : ";
    x.afficher_npi(cout);
    cout << endl;

    cout << "Valeur calculee     : " << x.calculer() << endl;

    // Test changement de valeur
    x.SetValeur(10.0f);
    cout << "Nouvelle valeur     : " << x.calculer() << endl;

    return 0;
}
