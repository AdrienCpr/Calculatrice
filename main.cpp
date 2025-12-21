#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"

// AJOUT V2
#include "Variable.h"
#include "TableDesSymboles.h"

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
    //                 AJOUT : V2 (Variables + TDS)
    // ==========================================================
    cout << "\n=== V2 : Tests Variables + TableDesSymboles ===\n";

    TableDesSymboles tds;

    // On demande "x" deux fois : on doit récupérer le même objet Variable (même pointeur)
    Variable* x1 = tds.getOuCreer("x");
    Variable* x2 = tds.getOuCreer("x");

    cout << "Adresse x1 = " << x1 << "\n";
    cout << "Adresse x2 = " << x2 << "\n";

    // Affectation via la table
    tds.affecter("x", 3.0f);

    // Expression exemple : (20 + x)
    Addition expr1(&c1, x1);

    cout << "Expr1 classique : ";
    expr1.afficher_classique(cout);
    cout << "\nExpr1 NPI       : ";
    expr1.afficher_npi(cout);
    cout << "\nExpr1 calculee  : " << expr1.calculer() << "\n";

    // Si on change x, expr1 doit changer aussi
    tds.affecter("x", 10.0f);
    cout << "Apres x = 10, Expr1 calculee : " << expr1.calculer() << "\n";

    // Autre expression exemple : (34 * (x + 30))
    Addition exprAdd(&(*x1), &c2);          // (x + 30)
    Multiplication expr2(&c3, &exprAdd);    // 34 * (x + 30)

    cout << "\nExpr2 classique : ";
    expr2.afficher_classique(cout);
    cout << "\nExpr2 NPI       : ";
    expr2.afficher_npi(cout);
    cout << "\nExpr2 calculee  : " << expr2.calculer() << "\n";

    // Debug : afficher la table
    cout << "\n--- Contenu TableDesSymboles ---\n";
    tds.afficher(cout);

    return 0;
}
