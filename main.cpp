#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Variable.h"   // <-- AJOUT

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

    // ==========================================================
    //              AJOUT : TESTS VARIABLES (Itération 1)
    // ==========================================================
    cout << "\n=== Tests Variables ===\n";

    Variable x("x");        // crée la variable x
    x.SetValeur(3.0f);      // lui affecte une valeur

    // Exemple 1 : (x + 10)
    Addition expr1(&x, &c5);   // c5 vaut 10.0
    cout << "Expr1 classique : ";
    expr1.afficher_classique(cout);
    cout << "\nExpr1 NPI       : ";
    expr1.afficher_npi(cout);
    cout << "\nExpr1 calculee  : " << expr1.calculer() << "\n";

    // Exemple 2 : (34 * (20 + x))
    Addition add2(&c1, &x);
    Multiplication expr2(&c3, &add2);

    cout << "\nExpr2 classique : ";
    expr2.afficher_classique(cout);
    cout << "\nExpr2 NPI       : ";
    expr2.afficher_npi(cout);
    cout << "\nExpr2 calculee  : " << expr2.calculer() << "\n";

    // Vérif : si on change x, toute l'expression change
    x.SetValeur(10.0f);
    cout << "\nApres x = 10 :\n";
    cout << "Expr1 calculee  : " << expr1.calculer() << "\n";
    cout << "Expr2 calculee  : " << expr2.calculer() << "\n";

    return 0;
}
